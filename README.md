<!-- Logo/Header -->
<p align="center">
  <img src="./assets/logo/rizitos_logo.png" width="220" alt="Rizitos Logo"/>
</p>

<h1 align="center">Team Rizitos 🇵🇦 — WRO Future Engineers 2025</h1>
<p align="center">
  <i>Panamá • WRO FUTURE ENGINEERS SENIOR'S CATEGORY • Python • Autonomous Systems</i>
</p>

<p align="center">
  <img src="https://img.shields.io/badge/Platform-Raspberry%20Pi%205-20C997?style=flat-square&logo=raspberrypi&logoColor=white"/>
  <img src="https://img.shields.io/badge/Language-Python%203-20C997?style=flat-square&logo=python&logoColor=white"/>
  <img src="https://img.shields.io/badge/Team-Colegio%20San%20Vicente%20de%20Paúl-ADB5BD?style=flat-square"/>
</p>

---

##  Introduction

We are **Team Rizitos**, a student robotics team from *Colegio San Vicente de Paúl* in Santiago, Veraguas 🇵🇦.  
Our group includes two seniors — **Flor Glaize** and **Francis Mojica** — and one junior, **Hebe Hernández**.

Together, we combine creativity, logic, and persistence to bring Rizitos to life: a fully autonomous robot designed to overcome obstacles, complete multiple laps, and finish strong.

---

##  Our Robot: **Rizitos**

<p align="center">
  <img src="./assets/robot_banner.jpg" width="80%" alt="Rizitos Robot Front View"/>
</p>

**Rizitos** is our autonomous self-driving robot which is designed to complete 3 laps and overcome a variety of obstacles in the WRO Future Engineers Senior's course.

The robot is based on a custom-modified chassis and multi-sensor platform. It includes ultrasonic detection, steering logic, lap tracking, and precise stop behavior — all coded in **Python**, running fully offline on a **Raspberry Pi 5**.



---

##  Meet the Minds Behind Rizitos!

<table align="center">
  <tr>
    <td colspan="3" align="center">
      <img src="./t-photos/rizitos_team.jpg" width="80%" alt="Team Rizitos Group Photo"/>
    </td>
  </tr>
  <tr>
    <td align="center">
      <b>Francis Mojica</b><br>
      Rizito's Software Programmer 💻<br>
      <sub>Creates Rizito's coding and programming</sub>
    </td>
    <td align="center">
      <b>Flor Glaize</b><br>
      Rizito's Mechanical Builder ⚙️<br>
      <sub>Focuses on Rizito's structure and hardware</sub>
    </td>
    <td align="center">
      <b>Hebe Hernández</b><br>
      Rizito's Documenter 📄<br>
      <sub>Records Rizito's GitHub repository, diagrams and schemes</sub>
    </td>
  </tr>
</table>

---

##  Repository Content

This is Rizito's Repository Index, where it shows all steps for Rizito's creation!:

| Folder          | Description                                                                 |
|------------------|-----------------------------------------------------------------------------|
| [`models/`](./models)     | Contains Rizito's STL and design files used for 3D printing and fabrication.        |
| [`other/`](./other)       | Includes additional diagrams and documentation of Rizito's motion and materials.   |
| [`schemes/`](./schemes)   | PNG diagrams illustrating all electromechanical components and wiring connections. |
| [`src/`](./src)           | Source code written in Python that controls the robot's autonomous functions.     |
| [`t-photos/`](./t-photos) | Official team group photo of Team Rizitos.                                         |
| [`v-photos/`](./v-photos) | Photos of Rizitos robot taken from multiple angles.                               |
| [`video/`](./video)       | Final challenge video of Rizitos completing all 3 laps.                           |

---

##  Engineering Materials

Below is a summary of the core components used to bring Rizitos to life. All parts were assembled and modified by us to meet the WRO Future Engineers 2025 challenge.

- Raspberry Pi 5 (central processor)
- Dual DC Motor Driver (GPIO-controlled)
- 2x MG90S Micro Servo Motors (steering + ultrasonic base)
- HC-SR04 Ultrasonic Distance Sensor
- 3D-printed camera + sensor mounts
- Modified smart car chassis with front-wheel steering
- USB Camera (used for testing only; not used during challenge)
- GPIO jumper wires, 9V battery case, L-type wrench, screwdrivers, and cable ties

---

##  Building Instructions

**Robot Structure:**
- The main concept for Rizitos' design was developed by our team using an external guide as reference.  
  → [`M.V.P`](https://www.adeept.com/video/static1/itemsfile/511343Tutorial.pdf)

**Operating Diagram:**
- The [`schemes/`](./schemes) folder contains all diagrams used to distribute Rizito's connection ports and lists all electronic components.

**Programming Code:**
- The [`src/`](./src) folder includes our Python source code that manages the robot’s movement, sensors, and decision-making logic.

>  *All programming and hardware integration were done by ourselves.*


>  **Rizitos is in constant evolution!.**  
> As we iterate, test, and improve our system, both the software and hardware may be updated regularly.  
> If you notice inconsistencies between sections or media, feel free to reach out or contribute!

---

## Rizito's Mobility System

### Key Functional Behaviors

#### 1. **Continuous Forward Movement**
- The robot uses a **DC gear motor** connected through a **motor driver**.
- The motor is activated by `GPIO17` (forward) and deactivated by `GPIO27` (reverse stop).
- While moving forward, the ultrasonic sensor constantly checks the path ahead for potential obstacles.

#### 2. **Lateral Obstacle Detection & Evasion**
- An **ultrasonic sensor (HC-SR04)** mounted on a rotating servo scans the left and right sides.
- The scanning servo is controlled by `GPIO22`, and the sensor operates via `GPIO5` (Trig) and `GPIO6` (Echo).
- If an obstacle is detected within a 15 cm range:
  - Forward motion is halted.
  - The scanning servo rotates the sensor to both directions.
  - The robot chooses the clearer path.
  - It turns using the **steering servo** on `GPIO23`.
  - Then, forward motion resumes once the path is clear.

#### 3. **Turning and Steering**
- The robot uses a front-mounted **MG90S micro servo** on `GPIO23` for steering.
- It receives directional commands (left or right) based on sensor feedback.
- After completing the turn, the servo resets to its center position for straight movement.

#### 4. **Lap Completion and Stop Behavior**
- The robot keeps track of laps internally (via code).
- After completing **3 full laps**, it:
  - Deactivates the motor by setting `GPIO17` and `GPIO27` to LOW.
  - Centers the steering servo.
  - Stops at its starting position and remains idle.

---

###  Why These Components?

| Component                       | Purpose & Reason                                                                  |
|--------------------------------|-----------------------------------------------------------------------------------|
| **DC Gear Motor**              | Drives the robot forward with consistent torque; controlled via motor driver.    |
| **Motor Driver Board**         | Interfaces motor control using GPIO signals for forward/reverse movement.        |
| **MG90S Servo (Steering)**     | Handles front-wheel steering with speed and precision.                          |
| **MG90S Servo (Sensor Mount)** | Rotates the ultrasonic sensor for side scanning.                                |
| **Ultrasonic Sensor (HC-SR04)**| Provides accurate distance measurements to detect obstacles.                     |


---

## 🧭 Navigation Strategy

The code we developed for Rizitos enables it to function **fully offline** and autonomously complete its WRO Future Engineers tasks — from open-lap circuits to obstacle-filled tracks. Using Python and a Raspberry Pi 5, our logic adapts in real-time to environment conditions, enabling dynamic movement, evasive maneuvers, and consistent loop tracking.

---

###  Open Round Strategy (No Obstacles)

In the Open Round, Rizitos focuses on uninterrupted movement and precise tracking of lap completions:

1. **Initialization**
   - The system powers up and configures all key GPIO pins.
   - Motors, servos, and the ultrasonic sensor are initialized.

2. **Lap Execution**
   - The **rear motor** (controlled via GPIO17/27) pushes the robot forward.
   - The **steering servo** (GPIO23) is fixed in its neutral center alignment.
   - A custom lap counter written in Python keeps track of completed loops using time and gyroscopic orientation.

3. **Stop Condition**
   - After three full laps, the motor driver is stopped.
   - Rizitos halts and re-centers its servos.

---

###  Obstacle Round Strategy (Dynamic Avoidance)

In the Challenge Round, Rizitos switches to a reactive navigation strategy using distance sensing and servo control:

1. **Active Scanning**
   - The **ultrasonic sensor** (HC-SR04) mounted on a scanning servo (GPIO22) rotates left and right.
   - Obstacle detection occurs continuously through distance sampling (Trig on GPIO5, Echo on GPIO6).

2. **Obstacle Encounter Logic**
   - If an object is detected ≤15cm ahead:
     - **Forward motion stops** (motors LOW).
     - The **scanning servo** sweeps left and right.
     - Python code determines which side has more clearance.
     - The **steering servo** (GPIO23) turns the wheels in the clearer direction.
     - The robot resumes forward movement.

3. **Gyroscopic Orientation**
   - An IMU/Gyroscope module is used to measure orientation (if available).
   - The lap counter checks rotational thresholds (360° x 3) to confirm progress.

4. **Completion Behavior**
   - After the third full lap (with successful evasion logic), the system cuts motor power and resets servos.
   - Rizitos comes to a full and final stop at its original point.

> This reactive planning system enables Rizitos to perform autonomously without AI inference or remote control!


---


Rizitos is not just a robot — it’s a reflection of our team’s collaboration, growth, and effort. Every wire connected, every line of code written, and every obstacle overcome was a result of three people working as one.

We are proud of what we’ve built — not just Rizitos, but the experience and bond that came with it. And we’re even more excited to share it with the world!


>If you have questions or want to share your thoughts, pfeel free to do so through the GitHub comments!







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

##  Our robot **Rizitos**

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
      <sub>Creates Rizito's coding and programming </sub>
    </td>
    <td align="center">
      <b>Flor Glaize</b><br>
      Rizito's Mechanical Builder ⚙️<br>
      <sub>Focuses on Rizito's structure and Hardware </sub>
    </td>
    <td align="center">
      <b>Hebe Hernández</b><br>
     Rizito's Documenter 📄<br>
      <sub> Records Rizito's GitHub repository, diagrams and schemes</sub>
    </td>
  </tr>
</table>

---

##  Rizito's Mobility System

Rizitos is designed to:

- Move forward autonomously  
- Detect lateral obstacles  
- Perform smooth steering  
- Complete 3 full laps  
- Stop at the starting position

### Core Logic:

1. **Obstacle Detection:**  
   The ultrasonic sensor continuously scans the front. If an obstacle is detected, the robot stops and begins a side scan using a rotating servo.

2. **Side Scanning & Decision Making:**  
   The scanning servo rotates the sensor left and right. Based on available space, the robot turns using the steering servo.

3. **Turning Mechanism:**  
   The steering servo (mounted on the front wheel axis) adjusts direction before the motors resume forward motion.

4. **Lap Counter:**  
   The robot internally counts laps using time or angle thresholds. After completing 3 full circuits, it stops all motors.

---

## Why we chose these components?

- **DC Gear Motors:** Deliver enough torque and speed to maintain consistent movement across the test course.  
- **Motor Controller Board:** Provides safe GPIO interfacing with adequate current handling.  
- **MG90S Servos:** Lightweight and reliable for precise direction adjustments.  
- **Ultrasonic Sensor (HC-SR04):** Balanced cost, simplicity, and sufficient accuracy for real-time navigation.  
- **Raspberry Pi 5:** Offers GPIO flexibility, multitasking capabilities, and support for Python-based logic.

---

##  System Overview

### Key Functions:
- Autonomous forward movement  
- Side-scanning obstacle detection (rotating ultrasonic sensor)  
- Evasive turning with steering servo  
- Lap counter with automatic stop  
- Fully offline execution — no voice or AI modules

### GPIO Pin Mapping

| Function              | GPIO Pins                  | Component                     |
|-----------------------|----------------------------|-------------------------------|
| Motor Movement        | GPIO17 (FWD), GPIO27 (REV) | Dual DC Motors via Driver     |
| Steering Servo        | GPIO23                     | MG90S Servo (Front Steering)  |
| Scanning Servo        | GPIO22                     | MG90S Servo (Sensor Rotation) |
| Ultrasonic Sensor     | GPIO5 (Trig), GPIO6 (Echo) | HC-SR04 Distance Sensor       |

📎 Wiring diagrams and schematics available in [`/schemes`](./schemes)

---

##  Strategy for Performance

### Open Round (No Obstacles)

In the open round, Rizitos performs clean laps with the following logic:

- Motors activate forward motion (GPIO17 HIGH)  
- The ultrasonic sensor passively monitors distance (no evasive action)  
- The lap counter increments after each full loop  
- After completing 3 rotations, the robot stops and resets servo angles

### Obstacle Course Execution

In the challenge round with obstacles:

- If an obstacle is detected ≤ 15 cm ahead:  
  - Motors stop  
  - Scanning servo rotates the ultrasonic sensor (left to right)  
  - Robot decides the clearer path  
  - Steering servo turns left/right accordingly  
  - Motors resume forward motion

- Obstacle evasion repeats dynamically throughout the run

---

## 🧱 Repository Structure

| Folder        | Description                                                                 |
|---------------|-----------------------------------------------------------------------------|
| [`/src`](./src)          | Main Python control scripts for mobility, sensors, and logic              |
| [`/schemes`](./schemes)  | Electrical wiring diagrams and pin layout maps                         |
| [`/models`](./models)    | 3D printable models for mechanical parts (STL files)                   |
| [`/t-photos`](./t-photos)| Team photo assets used in documentation                                |
| [`/v-photos`](./v-photos)| Images of the robot (front, side, diagonal views)                      |
| [`/video`](./video)      | Embedded video of Rizitos running the WRO course                       |
| [`/other`](./other)      | Any additional planning files or charts                               |

---

> [!NOTE]  
> This repository is a continuous work in progress. As our team improves Rizitos through testing, redesigns, and code optimization, some sections of the documentation may evolve.  
> If you notice any inconsistencies or have suggestions, please reach out through GitHub Issues.

---




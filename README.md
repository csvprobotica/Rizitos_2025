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

## 🤖 Our Robot: **Rizitos**

<p align="center">
  <img src="./assets/robot_banner.jpg" width="80%" alt="Rizitos Robot Front View"/>
</p>

**Rizitos** is our autonomous self-driving robot which is designed to complete 3 laps and overcome a variety of obstacles in the WRO Future Engineers Senior's course.

The robot is based on a custom-modified chassis and multi-sensor platform. It includes ultrasonic detection, steering logic, lap tracking, and precise stop behavior — all coded in **Python**, running fully offline on a **Raspberry Pi 5**.

> “Made from what we had. Powered by what we learned.”

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

This repository is organized into clear folders, each holding specific materials related to Rizitos:

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
  → [`M.V.P`](https://osoyoo.com/manual/sportcarkit.pdf)

**Operating Diagram:**
- The [`schemes/`](./schemes) folder contains all diagrams used to distribute Rizito's connection ports and lists all electronic components.

**Programming Code:**
- The [`src/`](./src) folder includes our Python source code that manages the robot’s movement, sensors, and decision-making logic.

> 🛠️ *All programming and hardware integration were completed by us from scratch.*

---

## 📌 Note on Development
> [!NOTE]

> ⚙️ **Rizitos is in constant evolution.**  
> As we iterate, test, and improve our system, both the software and hardware may be updated regularly.  
> If you notice inconsistencies between sections or media, feel free to reach out or contribute!

---







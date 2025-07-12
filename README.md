<!-- Logo/Header -->
<p align="center">
  <img src="./assets/logo/rizitos_logo.png" width="220" alt="Rizitos Logo"/>
</p>

<h1 align="center">Team Rizitos — WRO Future Engineers 2025</h1>
<p align="center">
  <i>Panamá • Raspberry Pi 5 • Python • Autonomous Systems</i>
</p>

<p align="center">
  <img src="https://img.shields.io/badge/Platform-Raspberry%20Pi%205-20C997?style=flat-square&logo=raspberrypi&logoColor=white"/>
  <img src="https://img.shields.io/badge/Language-Python%203-20C997?style=flat-square&logo=python&logoColor=white"/>
  <img src="https://img.shields.io/badge/Team-Colegio%20San%20Vicente%20de%20Paúl-ADB5BD?style=flat-square"/>
</p>

---

## 🔷 Introduction

We are **Team Rizitos**, a student robotics team from *Colegio San Vicente de Paúl* in Santiago, Veraguas 🇵🇦.  
Our group includes two seniors — **Flor Glaize** and **Francis Mojica** — and one junior, **Hebe Hernández**.

Together, we combine creativity, logic, and persistence to bring Rizitos to life: a fully autonomous robot designed to overcome obstacles, complete multiple laps, and finish strong.

Our goal isn’t just to build a robot — it’s to understand every part of it, and to represent Panama with purpose, precision, and pride.

---

## 🚗 And Here We Have **Rizitos**

<p align="center">
  <img src="./assets/robot_banner.jpg" width="80%" alt="Rizitos Robot Front View"/>
</p>

**Rizitos** is an autonomous self-driving robot we designed and built from scratch for the WRO 2025 challenge.

The robot is based on a custom-modified chassis and multi-sensor platform. It includes ultrasonic detection, steering logic, lap tracking, and precise stop behavior — all coded in **Python**, running fully offline on a **Raspberry Pi 5**.

It navigates. It avoids. It completes 3 full laps. And it does it without any remote input.

> “Made from what we had. Powered by what we learned.”

---

## 👥 Meet the Minds Behind Rizitos

<table align="center">
  <tr>
    <td colspan="3" align="center">
      <img src="./t-photos/rizitos_team.jpg" width="80%" alt="Team Rizitos Group Photo"/>
    </td>
  </tr>
  <tr>
    <td align="center">
      <b>Francis Mojica</b><br>
      Logic & Code<br>
      <sub>Python, obstacle evasion, lap tracking</sub>
    </td>
    <td align="center">
      <b>Flor Glaize</b><br>
      Mechanical Build<br>
      <sub>Structure, wheels, mounts, wiring</sub>
    </td>
    <td align="center">
      <b>Hebe Hernández</b><br>
      GitHub & Docs<br>
      <sub>Repository, planning, diagrams</sub>
    </td>
  </tr>
</table>

---

## 🧠 System Overview

### Key Functions:
- Autonomous forward movement
- Side-scanning obstacle detection (rotating ultrasonic sensor)
- Evasive turning with steering servo
- Lap counter with automatic stop
- Offline execution — no voice or AI modules

### Pin Mapping:

| Function            | GPIO Pins        | Component                 |
|---------------------|------------------|---------------------------|
| Motor Movement      | D7 (FWD), D8 (REV)| Motor Driver              |
| Steering Servo      | D9               | MG90S Servo (Direction)   |
| Scanning Servo      | D10              | MG90S Servo (Sensor Base) |
| Ultrasonic Sensor   | D2 (Trig), D3 (Echo)| HC-SR04                 |

📎 Wiring diagrams and schematics in [`/schemes`](./schemes)

---

## ⚙️ Engineering Materials

Below is a general list of the key components we used to build **Rizitos**. Every connection, calibration, and mount was configured and tested manually — no pre-installed logic, no automation.

- Raspberry Pi 5 — primary control board  
- DC Motor x2 — propulsion  
- MG90S Servo x2 — one for steering, one for sensor scanning  
- Ultrasonic Sensor — distance measurement (front-mounted, rotating)  
- Motor Driver Board — power + direction control  
- Tracking Sensors (Line/Light) — available but unused  
- 4-Wheel Chassis — customized with additional mounting plates  
- Power Pack — 7.4V rechargeable system  
- Camera Module — optional, not used for logic  
- Mounting Tools — screws, brackets, mini wrench, flexible sensor cables

---

## 📂 Repository Structure

```
/src        → Python source code
/models     → STL files for printed components
/schemes    → Diagrams: circuits, flowcharts
/t-photos   → Team pictures
/v-photos   → Robot views (all angles)
/video      → Robot in action
```

---

## 🛠️ Hardware Summary

- Raspberry Pi 5 (Linux OS, offline control)
- Dual DC motors with gear drive system
- MG90S servo motor (for front-wheel steering)
- Secondary servo for rotating ultrasonic sensor
- Ultrasonic distance sensor (HC-SR04)
- Line and light tracking sensors (available, not used in current logic)
- Raspberry Pi-compatible motor controller (PWM & GPIO based)
- Rechargeable battery pack (modular mount)
- 4-wheel chassis with suspension system
- Jumper wires, sensor brackets, screw kit

All physical integration and component placement were manually adjusted and tested by the team.

---

## 📌 What We Learned

- How to wire, test, and troubleshoot a real robotic platform  
- How to calibrate sensors and servos for reliable logic  
- How to write structured Python for real-world hardware  
- How to work as a team — with a common goal and clear roles

Everything was written, built, and improved by us — no kits, no code copied, no shortcuts.

---

## 🏁 WRO 2025 Evaluation Criteria – ✔️ Fully Covered

We designed this robot and documentation to meet all 30 evaluation points:

- [x] Three complete laps
- [x] Stops at the exact starting position
- [x] Avoids side obstacles using a rotating ultrasonic sensor
- [x] Designed and coded by students only
- [x] No cloud, AI, or voice — all offline
- [x] Original code and logic in Python
- [x] Circuit diagrams and 3D model files included
- [x] Clear GitHub repo with logical structure
- [x] Roles, documentation, and presentation quality

📖 [See full guidelines (PDF)](https://wro-association.org/wp-content/uploads/WRO-2025-Future-Engineers-Self-Driving-Cars-General-Rules.pdf)

---

## 🖼️ Showcase & Media

- 📸 Robot Photos → [`/v-photos`](./v-photos)  
- 👥 Team Pictures → [`/t-photos`](./t-photos)  
- 🎥 Final Run Video → [`/video`](./video)

---

## 💬 Final Thoughts

This project challenged us in ways we didn’t expect — and helped us grow in ways we’re proud of.  
Rizitos isn’t just a robot. It’s the result of building from scratch, staying up late, testing again, and believing we could figure it out.

> “We didn’t start as experts — we became builders.”

---

📫 **Contact:** rizitos.wro2025@gmail.com  
🏫 **School:** Colegio San Vicente de Paúl  
🧠 **Built With:** Raspberry Pi 5 · Python · Creativity



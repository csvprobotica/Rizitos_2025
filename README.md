##  Team Rizitos WRO 2025

_We are Team Rizitos, a robotics team competing in the Future  Engineers Senior's category of the WRO. Our group is made up of two seniors, Flor Glaize and Francis Mojica , and one junior, Hebe Hernández. Together, we combine creativity, teamwork, and technical skills to bring our robot to life.
Our robot, also named Rizitos, is designed to complete 3 laps and overcome a variety of obstacles in the WRO Future Engineers Senior's course. We proudly represent Colegio San Vicente de Paúl from Santiago de Veraguas, Panamá._ 

Engineering materials
====

This repository includes all the engineering materials we used to build our robot, Rizitos, for the 2025 season of the WRO Future Engineers competition.

Below is the list of parts we used to assemble our self-driving vehicle:

* Basic Board for Arduino (Fully compatible with Arduino UNO R3) – Quantity: 1
*	Motor Shield V1.1 – Quantity: 1
*	MG90S Servo Motor – Quantity: 1
*	Voltage Meter – Quantity: 1
*	Tracking Sensor – Quantity: 1
*	Ultrasonic Sensor – Quantity: 1
*	Servo Motor – Quantity: 1
*	Mount Holder for Ultrasonic Sensor – Quantity: 1
*	ESP8266 Wi-Fi Shield – Quantity: 1
*	HC Module – Quantity: 1
*	Car Chassis – Quantity: 1
*	Motor with Wires – Quantity: 1
*	Wheels – Quantity: 4
*	9V Battery Box – Quantity: 1
*	9V Battery – Quantity: 1
*	Phillips Screwdriver – Quantity: 1
*	Hex Screwdriver – Quantity: 1
*	L-type Wrench – Quantity: 1
*	20-pin 15 cm Female-to-Female Cable – Quantity: 1
*	7-pin 25 cm Female-to-Female Cable – Quantity: 1
*	3-pin 15 cm Female-to-Female Cable – Quantity: 1
*	Steering Cup – Quantity: 2


Building Instructions
====
* Robot Structure:
  - The main idea of  Rizito’s design was developed by us and a source that  we used as a guideline .[`M.V.P`](https://osoyoo.com/manual/sportcarkit.pdf)
* Operating Diagram:
  - The directory  [`schemes`](https://github.com/csvprobotica/RoSGhost/tree/main/schemes)contains Rizito's connection ports diagram where all the ports used are distributed, and the  list of electronic components which each of the elements used are described.
* Programming Code: (Block and Python)
  - The directory [`scr`](https://github.com/csvprobotica/RoSGhost/tree/main/src) directory contains the main source code written in Arduino (C++) using the mBlock programming environment. Which manages the robot’s key functions such as movement and sensor responses.

All the programming has been done by ourselves.



## Content

* [`models`](https://github.com/csvprobotica/RoSGhost/tree/main/models) in this archive you'll  find Rizito's 3D models diagrams with its components.
* [`other`](https://github.com/csvprobotica/RoSGhost/tree/main/other) this carpet contains additional files of Rizito's operation through the course via a diagram.
* [`schemes`](https://github.com/csvprobotica/RoSGhost/tree/main/schemes) contains an explanatory  diagram in PNG format of the electromechanical components illustrating all the elements (motors, sensors ,etc.) with its connections.
* [`src`](https://github.com/csvprobotica/RoSGhost/tree/main/src) this record contains all Rizito's Arduino code programming ( which is text-based style) that makes our robot move.
* [`t-photos`](https://github.com/csvprobotica/RoSGhost/tree/main/t-photos) you'll find Rizito's Team members photos (2) (the official one and another  with  a gist of fun).
* [`v-photos`](https://github.com/csvprobotica/RoSGhost/tree/main/v-photos) in this folder you'll encounter our robot, Rizitos, from 6 different angles.
* [`video`](https://github.com/csvprobotica/RoSGhost/tree/main/video) the video.mp4 file shows Rizitos in action, where it completes the whole 3 laps.

## Mobility

Rizito's is designed to evade lateral obstacles, complete three full rotations, and stop at its initial position using the motor interface connected to D7 (forward) and D8 (reverse), a steering servo on D9, and an ultrasonic scanning servo on D10.

This mobility system allows the robot to autonomously navigate environments with obstacles, perform evasive maneuvers, and maintain orientation through servo-controlled direction changes.

Below are the key aspects of its mobility:

Continuous Forward Movement:
	•	The motor interface K2 is controlled by digital pin D7 for forward motion and D8 for reverse.
	•	The robot moves forward continuously using D7 while monitoring distances with the ultrasonic sensor.

Lateral Obstacle Evasion:
	•	The ultrasonic sensor is mounted on a servo motor connected to D10, allowing it to rotate for side detection.
	•	The sensor uses digital pins D2 (Trig) and D3 (Echo) for distance measurement, and is powered through SV and GND.
	•	When an obstacle is detected, the robot stops forward motion (D7 OFF) and rotates the ultrasonic sensor via D10 to scan the sides.
	•	Based on the sensor reading, the robot turns using the steering servo on D9, either left or right.
	•	Once the path is clear, the robot resumes forward motion using D7.

Turning and Navigation:
	•	The steering system uses the MG90S Micro Servo connected to D9.
	•	To turn left or right, the servo is rotated to a predefined angle via D9.
	•	After the turn, the servo returns to its neutral position to continue forward.

Stopping at the Initial Position:
	•	After completing three rotations, the robot stops the motor interface by setting D7 and D8 LOW.
	•	The steering servo on D9 is returned to its centered position.
	•	The robot remains stationary at the initial

## Strategy


The strategy employed in this code enables the Lego Mindstorms Inventor robot to autonomously navigate its environment, avoid obstacles, and complete a series of precise rotations. By utilizing the rear motor for forward movement, the front motor for turning, and the gyroscope for orientation tracking, the robot can perform complex maneuvers and maintain accuracy in its movements. This approach ensures that the robot can handle dynamic environments and complete its assigned task effectively.

Here is a detailed description of the strategy implemented in the code:

1. Initialization:
   - The robot's hub, motors,color and ultrasonic sensors are initialized.
   - The rear motor (connected to port B) is designated for forward movement.
   - The front motor (connected to port A) is designated for turning.
   - Three ultrasonic sensors (connected to ports D,E and F) are used to detect obstacles on the right and left sides, respectively.

2. Continuous Forward Movement:
   - The robot starts moving forward at a constant speed using the rear motor.
   - This movement is continuous, allowing the robot to traverse its environment.

3. Obstacle Detection and Evasion:
   - While moving forward, the robot continuously monitors the distance to obstacles on both sides using the ultrasonic sensors.
   - If the right sensor detects an obstacle within 10 cm, the robot:
     - Stops the rear motor to halt forward movement.
     - Activates the front motor to turn 90 degrees to the left.
     - Waits for a short duration to complete the turn.
     - Resumes forward movement with the rear motor.
   - If the left sensor detects an obstacle within 10 cm, the robot:
     - Stops the rear motor.
     - Activates the front motor to turn 90 degrees to the right.
     - Waits for a short duration to complete the turn.
     - Resumes forward movement with the rear motor.
   - This ensures that the robot can navigate around obstacles and continue its path.

4. Gyroscope for Orientation and Rotation Tracking:
   - The robot uses the integrated gyroscope to maintain and track its orientation.
   - At the beginning of the operation, the gyroscope is reset to establish a zero-degree reference.
   - The gyroscope continuously measures the robot's turning angle to track its rotational progress.

5. Three Full Rotations:
   - The robot is programmed to complete three full rotations, equivalent to 1080 degrees.
   - Each time the gyroscope detects a 360-degree rotation, the rotation counter is incremented, and the gyroscope is reset.
   - The process of obstacle detection, evasion, and continuous forward movement ensures that the robot can complete its rotations without interruptions.

6. Completion and Stopping:
   - After completing the three full rotations, the robot stops the rear motor.
   - The robot remains in its final position, indicating the completion of its task.

## Challenges
_During the process of building and programming Rizitos , we experienced several challenges that helped us learn and improve as a team. The main difficulties we faced were:_

_1.	It Was Our First Time Using Arduino
This project was our first time working with Arduino, so we had to learn how to connect the components, understand the board, and figure out how it all worked. It was a new experience for all of us, and we had to spend extra time learning and testing._

_2.	Adapting the Ultrasonic Sensor to the New Robot Model
One of the challenges we faced was using the ultrasonic distance sensor correctly with our robot. Since this was our first time working with this specific robot model, it took us a while to understand which ports to use and how to connect the sensor properly. At first, the readings weren’t consistent, and we weren’t sure if it was a wiring issue or a problem in the code. It required several tests and adjustments before we were finally able to get it to detect obstacles as expected._

_3.	Using Text-Based Programming Instead of Blocks
Instead of block-based coding, we used text-style programming through mBlock. This made it a bit more difficult because we had to be careful with syntax and understand how to write each line of code correctly. Even small mistakes could cause the robot to stop working, so it required a lot of attention and patience._


##  Team Rizitos WRO 2025

_We are Team Rizitos, a robotics team competing in the Future  Engineers category of the WRO. Our group is made up of two seniors, Flor Glaize and Francis Mojica , and one junior, Hebe Hernández. Together, we combine creativity, teamwork, and technical skills to bring our robot to life.
Our robot, also named Rizitos, is designed to complete 3 laps and overcome a variety of obstacles in the WRO Future Engineers course. We proudly represent Colegio San Vicente de Paúl from Santiago de Veraguas, Panamá._ 

Engineering materials
====

This repository includes all the engineering materials we used to build our robot, Rizitos, for the 2025 season of the WRO Future Engineers competition.

Below is the list of parts we used to assemble our self-driving vehicle:

* OSOYOO Basic Board for Arduino (Fully compatible with Arduino UNO R3) – Quantity: 1
*	OSOYOO Motor Shield V1.1 – Quantity: 1
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
  - The main idea of the design was developed by us and two sources were used as a guideline.[`M.V.P`](https://www.google.com/url?sa=t&source=web&rct=j&opi=89978449&url=https://www.lego.com/cdn/product-assets/product.bi.additional.main.pdf/51515_MVP.pdf&ved=2ahUKEwiw8bretaWHAxV0mbAFHf3RBCYQFnoECBMQAQ&usg=AOvVaw04D5riAZvc2TIGsk0whvge) and [`Antons Mindstorms Hot Rod`](https://www.antonsmindstorms.com/product/hot-rod-with-spike-prime-pdf-building-instructions/)
* Components Assembly:
  - The Studio 2.0 application was used for the creation and 3D modeling of all parts in the [`models`]() directory.
* Operating Diagram:
  - The directory  [`schemes`](https://github.com/csvprobotica/RoSGhost/tree/main/schemes)contains a connection diagram where all the ports used are distributed, a process diagram which details all the actions to be performed and a list of electronic components in which each of the elements used are described.
* Programming Code: (Block and Python)
  - The directory [`scr`](https://github.com/csvprobotica/RoSGhost/tree/main/src) contains the main source code realized in a block system using the Lego Inventor Mindstorms program and Python Code.

All the programming has been done by ourselves.



## Content

* [`models`](https://github.com/csvprobotica/RoSGhost/tree/main/models) in this directory you will find the 3D modeled files for the assembly of the robot and its components.
* [`other`](https://github.com/csvprobotica/RoSGhost/tree/main/other) in this directory you will find additional files of the robot operation, process diagram and execution.
* [`schemes`](https://github.com/csvprobotica/RoSGhost/tree/main/schemes) contains a schematic diagram in PNG format of the electromechanical components illustrating all the elements (electronic components and motors) used in the vehicle and how they are connected to each other.
* [`src`](https://github.com/csvprobotica/RoSGhost/tree/main/src) contains code of control software for all components which were programmed to participate in the competition.
* [`t-photos`](https://github.com/csvprobotica/RoSGhost/tree/main/t-photos) contains 2 photos of the team (an official one and one funny photo with all team members).
* [`v-photos`](https://github.com/csvprobotica/RoSGhost/tree/main/v-photos) contains 6 photos of the vehicle (from every side, from top and bottom).
* [`video`](https://github.com/csvprobotica/RoSGhost/tree/main/video) contains the video.mp4 file with the robot driving demonstration.

## Mobility
This robot is designed to evade lateral obstacles, complete three full rotations, and stop at its initial position using a rear motor for forward movement and a front motor for turning.

This mobility system allows the robot to autonomously navigate environments with obstacles, perform evasive maneuvers, and maintain precise orientation using the gyroscope.

Below are the key aspects of its mobility:
1. Continuous Forward Movement:
   - The rear motor, connected to port B, drives the robot forward at a constant speed.
   - The robot moves continuously while monitoring distances to obstacles on both sides.

2. Lateral Obstacle Evasion:
   - Three ultrasonic sensors are connected to ports D (right), E (left) and F (front).
   - These sensors detect obstacles on the sides of the robot.
   - If the right sensor detects a wall within 10 cm, the robot stops the rear motor and uses the front motor to turn 90 degrees to the left.
   - If the left sensor detects a wall within 10 cm, the robot stops the rear motor and uses the front motor to turn 90 degrees to the right.
   - After evading an obstacle, the rear motor resumes forward movement.

3. Turning and Navigation:
   - The front motor, connected to port A, is used exclusively for precise turns.
   - To turn 90 degrees to the left, the front motor is activated in the opposite direction for a specific duration.
   - To turn 90 degrees to the right, the front motor is activated in the direct direction for a specific duration.
   - Turns are calibrated to ensure the robot maintains its course and can navigate effectively around obstacles.

4. Gyroscope Utilization:
   - The integrated gyroscope in the LEGO Mindstorms hub is used to track the robot's orientation.
   - At the start, the gyroscope is reset to establish a zero-degree reference angle.
   - While the robot moves and evades obstacles, the gyroscope measures the cumulative turning angle.
   - The robot is programmed to complete three full rotations, totaling 1080 degrees.
   - Each time the gyroscope detects a 360-degree rotation, the lap counter is incremented and the gyroscope angle is reset.

5. Stopping at the Initial Position:
   - After completing the three rotations, the robot stops the rear motor and remains at the initial position, indicating the task is complete.

## Strategy
The code provided for the LEGO Mindstorms Inventor robot outlines a strategy for autonomous navigation, obstacle evasion, and precise rotational movements.

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
_During the process of building and programming Rizitos , we experienced several challenges that helped us learn and improve as a team. The main difficulties we faced were:
1.	It Was Our First Time Using Arduino
This project was our first time working with Arduino, so we had to learn how to connect the components, understand the board, and figure out how it all worked. It was a new experience for all of us, and we had to spend extra time learning and testing.
2.	Adapting the Ultrasonic Sensor to the New Robot Model
One of the challenges we faced was using the ultrasonic distance sensor correctly with our robot. Since this was our first time working with this specific robot model, it took us a while to understand which ports to use and how to connect the sensor properly. At first, the readings weren’t consistent, and we weren’t sure if it was a wiring issue or a problem in the code. It required several tests and adjustments before we were finally able to get it to detect obstacles as expected.
3.	Using Text-Based Programming Instead of Blocks
Instead of block-based coding, we used text-style programming through mBlock. This made it a bit more difficult because we had to be careful with syntax and understand how to write each line of code correctly. Even small mistakes could cause the robot to stop working, so it required a lot of attention and patience._


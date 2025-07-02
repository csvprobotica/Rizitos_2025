#include <Arduino.h>
#include <Servo.h>

// K2 motor pins (L293DD without PWM)
const int motorForward = 7;
const int motorBackward = 8;

// Steering servo (MG90S)
Servo steeringServo;
const int steeringPin = 9;

// Servo for ultrasonic sensor (LACC200610)
Servo ultrasonicServo;
const int ultrasonicServoPin = 10;

// Ultrasonic sensor pins
const int trigPin = 2;
const int echoPin = 3;

// Line sensor (goal)
const int lineSensor = A2;
const int lineThreshold = 500;

// Obstacle avoidance parameters for ~50 cm radius turn
using ul = unsigned long;
const int wallDistance = 15;            // 15 cm minimum separation
const int centerAngle = 90;             // Center position of steering servo
const int offsetAngle = 20;             // Soft offset (±150°) for wide turns
const ul dodgeTime = 900;               // 0.6 s maneuver for ~50 cm radius

// Total execution time
const ul maxTime = 11000;               // 11 seconds

// Turn tracking variables (optional)
int laps = 0;
ul lastStep = 0;
const ul debounceLap = 1000;            // 1 second debounce for line sensor
ul t0;

// Prototypes
int measureFrontDistance();
int measureDistanceAtAngle(int angle);
void avoidWall();
bool detectLap();
void moveForward();
void stopAll();

void setup() {
  // Motors
  pinMode(motorForward, OUTPUT);
  pinMode(motorBackward, OUTPUT);
  stopAll();

  // Servos
  steeringServo.attach(steeringPin);
  ultrasonicServo.attach(ultrasonicServoPin);
  steeringServo.write(centerAngle);
  ultrasonicServo.write(centerAngle);

  // Ultrasonic sensor
  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW);
  pinMode(echoPin, INPUT);

  // Line sensor
  pinMode(lineSensor, INPUT);

  // Serial communication
  Serial.begin(9600);

  // Start time
  t0 = millis();
}

void loop() {
  // Check max execution time
  if (millis() - t0 >= maxTime) {
    stopAll();
    Serial.println("Time completed");
    while (true);
  }

  // Read front distance
  int frontDist = measureFrontDistance();
  Serial.print("Front distance: ");
  Serial.print(frontDist);
  Serial.println(" cm");

  // Move forward or avoid
  if (frontDist > wallDistance) {
    steeringServo.write(centerAngle);
    moveForward();
  } else {
    avoidWall();
  }

  // Lap counting (optional)
  if (detectLap()) {
    laps++;
    Serial.print("Lap ");
    Serial.println(laps);
  }
}

// Measure front distance without moving servo
int measureFrontDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH, 20000);
  return duration ? duration * 0.034 / 2 : 999;
}

// Measure distance at a given angle for avoidance
int measureDistanceAtAngle(int angle) {
  ultrasonicServo.write(angle);
  delay(150);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH, 20000);
  return duration ? duration * 0.034 / 2 : 999;
}

// Clean curve avoidance with ~50 cm radius
void avoidWall() {
  int distRight = measureDistanceAtAngle(0);
  int distLeft = measureDistanceAtAngle(180);

  int angle = (distRight > distLeft) ? (centerAngle + offsetAngle)
                                     : (centerAngle - offsetAngle);
  steeringServo.write(angle);
  moveForward();
  delay(dodgeTime);
  steeringServo.write(centerAngle);
}

// Move straight
void moveForward() {
  digitalWrite(motorForward, HIGH);
  digitalWrite(motorBackward, LOW);
}

// Detect lap with center line sensor
bool detectLap() {
  ul now = millis();
  int reading = analogRead(lineSensor);
  if (reading < lineThreshold && (now - lastStep) > debounceLap) {
    lastStep = now;
    return true;
  }
  return false;
}

// Stop and center steering
void stopAll() {
  digitalWrite(motorForward, LOW);
  digitalWrite(motorBackward, LOW);
  steeringServo.write(centerAngle);
}


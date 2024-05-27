// Define motor A pins
const int motorAPWM = 9;  // PWM pin for Motor A speed control
const int motorADir = 10; // Direction pin for Motor A

// Define motor B pins
const int motorBPWM = 5;  // PWM pin for Motor B speed control
const int motorBDir = 6;  // Direction pin for Motor B

// Speed control parameters
const int maxSpeed = 255;  // Maximum speed (PWM value)
const int rampDelay = 50;  // Delay between speed increments (in milliseconds)
const int increment = 5;   // Speed increment step

void setup() {
  // Initialize motor control pins
  pinMode(motorAPWM, OUTPUT);
  pinMode(motorADir, OUTPUT);
  pinMode(motorBPWM, OUTPUT);
  pinMode(motorBDir, OUTPUT);

  // Set initial direction for both motors
  digitalWrite(motorADir, HIGH);
  digitalWrite(motorBDir, HIGH);

  Serial.begin(9600);
}

void loop() {
  // Ramp up Motor A from 0 to full speed
  for (int speed = 0; speed <= maxSpeed; speed += increment) {
    analogWrite(motorAPWM, speed);
    Serial.print("Motor A speed: ");
    Serial.println(speed);
    delay(rampDelay);
  }

  // Ramp down Motor A from full speed to 0
  for (int speed = maxSpeed; speed >= 0; speed -= increment) {
    analogWrite(motorAPWM, speed);
    Serial.print("Motor A speed: ");
    Serial.println(speed);
    delay(rampDelay);
  }

  // Ramp up Motor B from 0 to full speed
  for (int speed = 0; speed <= maxSpeed; speed += increment) {
    analogWrite(motorBPWM, speed);
    Serial.print("Motor B speed: ");
    Serial.println(speed);
    delay(rampDelay);
  }

  // Ramp down Motor B from full speed to 0
  for (int speed = maxSpeed; speed >= 0; speed -= increment) {
    analogWrite(motorBPWM, speed);
    Serial.print("Motor B speed: ");
    Serial.println(speed);
    delay(rampDelay);
  }
}
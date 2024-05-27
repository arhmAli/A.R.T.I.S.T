#include <Encoder.h>

// Define motor A pins
const int motorAPWM = 9;  // PWM pin for Motor A speed control
const int motorADir = 10; // Direction pin for Motor A

// Define motor B pins
const int motorBPWM = 5;  // PWM pin for Motor B speed control
const int motorBDir = 6;  // Direction pin for Motor B

// Define encoder pins for Motor A
Encoder motorAEnc(2, 3); // Encoder pins for Motor A

// Define encoder pins for Motor B
Encoder motorBEnc(12, 7); // Encoder pins for Motor B

// PID parameters
float Kp = 2.0;
float Ki = 5.0;
float Kd = 1.0;

// Target speed (in encoder counts per second)
int targetSpeedA = 100;
int targetSpeedB = 100;

// PID variables for Motor A
float integralA = 0, previousErrorA = 0;

// PID variables for Motor B
float integralB = 0, previousErrorB = 0;

// Timing
unsigned long previousMillis = 0;
const long interval = 100; // Loop interval in milliseconds

void setup() {
  // Initialize motor control pins
  pinMode(motorAPWM, OUTPUT);
  pinMode(motorADir, OUTPUT);
  pinMode(motorBPWM, OUTPUT);
  pinMode(motorBDir, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    // Read encoder values
    long currentPosA = motorAEnc.read();
    long currentPosB = motorBEnc.read();

    // Calculate speed (counts per second)
    static long previousPosA = 0;
    static long previousPosB = 0;
    int speedA = (currentPosA - previousPosA) * (1000 / interval);
    int speedB = (currentPosB - previousPosB) * (1000 / interval);
    previousPosA = currentPosA;
    previousPosB = currentPosB;

    // Calculate error for Motor A
    int errorA = targetSpeedA - speedA;
    // Calculate integral for Motor A
    integralA += errorA * (interval / 1000.0);
    // Calculate derivative for Motor A
    float derivativeA = (errorA - previousErrorA) / (interval / 1000.0);
    // Compute PID output for Motor A
    float outputA = Kp * errorA + Ki * integralA + Kd * derivativeA;
    // Update previous error for Motor A
    previousErrorA = errorA;

    // Calculate error for Motor B
    int errorB = targetSpeedB - speedB;
    // Calculate integral for Motor B
    integralB += errorB * (interval / 1000.0);
    // Calculate derivative for Motor B
    float derivativeB = (errorB - previousErrorB) / (interval / 1000.0);
    // Compute PID output for Motor B
    float outputB = Kp * errorB + Ki * integralB + Kd * derivativeB;
    // Update previous error for Motor B
    previousErrorB = errorB;

    // Control motors
    controlMotor(motorAPWM, motorADir, outputA);
    controlMotor(motorBPWM, motorBDir, outputB);

    // Debugging information
    Serial.print("Motor A - ");
    Serial.print("Encoder Position: "); Serial.print(currentPosA);
    Serial.print(" | Speed: "); Serial.print(speedA);
    Serial.print(" | Error: "); Serial.print(errorA);
    Serial.print(" | Integral: "); Serial.print(integralA);
    Serial.print(" | Derivative: "); Serial.print(derivativeA);
    Serial.print(" | Output: "); Serial.println(outputA);

    Serial.print("Motor B - ");
    Serial.print("Encoder Position: "); Serial.print(currentPosB);
    Serial.print(" | Speed: "); Serial.print(speedB);
    Serial.print(" | Error: "); Serial.print(errorB);
    Serial.print(" | Integral: "); Serial.print(integralB);
    Serial.print(" | Derivative: "); Serial.print(derivativeB);
    Serial.print(" | Output: "); Serial.println(outputB);
  }
}

void controlMotor(int pwmPin, int dirPin, float output) {
  if (output > 0) {
    digitalWrite(dirPin, HIGH);
    analogWrite(pwmPin, constrain(output, 0, 255));
  } else {
    digitalWrite(dirPin, LOW);
    analogWrite(pwmPin, constrain(-output, 0, 255));
  }
}
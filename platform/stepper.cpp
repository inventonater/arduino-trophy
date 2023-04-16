#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"
#include <math.h>

// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield();

// Connect a stepper motor with 200 steps per revolution (1.8 degree)
// to motor port #1 (M1 and M2)
Adafruit_StepperMotor *myStepper = AFMS.getStepper(200, 1);

const int minStep = 0;
const int maxStep = 100; // Set this to the desired maximum step position
const int amplitude = (maxStep - minStep) / 2;
const int midpoint = (maxStep + minStep) / 2;
const float angularSpeed = 0.05; // Adjust this value to control the speed of the stepper motor
const int stepsPerRevolution = 200;
const int stepDelay = 10; // Adjust this delay to control the speed of the stepper motor movement

int currentStep = 0;

void setup() {
  Serial.println("Stepper test!");
  AFMS.begin();  // create with the default frequency 1.6KHz

  // Set the speed of the stepper motor
  myStepper->setSpeed(stepsPerRevolution / stepDelay);
}

void loop() {
  for (float angle = 0; angle <= 2 * PI; angle += angularSpeed) {
    int targetStep = midpoint + amplitude * sin(angle);

    if (targetStep > currentStep) {
      myStepper->step(targetStep - currentStep, FORWARD, INTERLEAVE);
      currentStep = targetStep;
    } else {
      myStepper->step(currentStep - targetStep, BACKWARD, INTERLEAVE);
      currentStep = targetStep;
    }
    delay(stepDelay);
  }
}

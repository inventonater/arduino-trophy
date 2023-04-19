#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"
#include <math.h>

// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield();

Adafruit_StepperMotor *myStepper = AFMS.getStepper(60, 1);
const int rpm = 2;

void setup() {
  // Serial.begin(9600); // Initialize serial communication
  Serial.println("Stepper test!");
  AFMS.begin();  // create with the default frequency 1.6KHz

  // Set the speed of the stepper motor
  myStepper->setSpeed(rpm);
}

void loop() {
  //SINGLE, DOUBLE, INTERLEAVE, MICROSTEP
  myStepper->step(360, FORWARD, INTERLEAVE);
  myStepper->step(360, BACKWARD, INTERLEAVE); 
}


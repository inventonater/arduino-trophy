#include <Arduino.h>
#include <Servo.h>
#include <math.h>

const int servo = A1;
const int minPulse = 1450;
const int maxPulse = 1550;
const int amplitude = (maxPulse - minPulse) / 2;
const int midpoint = (maxPulse + minPulse) / 2;
const float angularSpeed = 0.05; // Adjust this value to control the speed of the servo movement

Servo myServo;

void setup() {
  myServo.attach(servo);
}

void loop() {
  for (float angle = 0; angle <= 2 * PI; angle += angularSpeed) {
    int pos = midpoint + amplitude * sin(angle);
    myServo.writeMicroseconds(pos);
    delay(200); // Adjust this delay to control the speed of the servo movement

    // print the microsecond value to the serial monitor
    Serial.println(pos);
  }
}

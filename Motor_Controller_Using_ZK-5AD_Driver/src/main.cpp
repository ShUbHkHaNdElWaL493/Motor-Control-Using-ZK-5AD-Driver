#include <Arduino.h>
#include "Actuator.h"

//Input pins for the actuator
#define D0 10
#define D1 9

//Signal from the joystick
#define joyX A0

actuator Actuator1(D0, D1);

void setup() {
  // put your setup code here, to run once:
  pinMode(joyX, INPUT);
  pinMode(D0, OUTPUT);
  pinMode(D1, OUTPUT);
  Actuator1.stop();
}

void loop() {
  // put your main code here, to run repeatedly:
  int displacement = analogRead(joyX);
  if (displacement > 600)
  {
    Actuator1.rotateAntiClockwise();
  } else if (displacement < 424)
  {
    Actuator1.rotateClockwise();
  } else
  {
    Actuator1.stop();
  }
}
#include <Arduino.h>

// PINS
#define pot A0
#define pwm 3

// CAN resolution 10 bit
#define CAN_min 0
#define CAN_max 1023

// PWM values
#define pwm_min 0
#define pwm_max 255


int command;

void setup() {

  Serial.begin(9600);

  // Pins setup
  pinMode(pot, INPUT);
  pinMode(pwm,OUTPUT);

  
}

void loop() {

  // CAN range to pwm range
  command = map(analogRead(pot), CAN_min, CAN_max, pwm_min, pwm_max);

  // Group by value
  if (command < 16) command=0;
  command = command > 15 ? 85 : command;
  command = command > 85 ? 170 : command;
  command = command > 170 ? 255 : command;
  
  analogWrite(pwm, command);

  Serial.print(command); 

}
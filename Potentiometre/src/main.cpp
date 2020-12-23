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


int commande;

void setup() {

  // Pins setup
  pinMode(pot, INPUT);
  pinMode(pwm,OUTPUT);

  
}

void loop() {

  commande=map(analogRead(pot), CAN_min, CAN_max, pwm_min, pwm_max);
  analogWrite(pwm, commande); 

}
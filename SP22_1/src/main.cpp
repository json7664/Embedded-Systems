#include <Arduino.h>

void setup() {
  pinMode(13,OUTPUT);
  // put your setup code here, to run once:
}

void loop() {
  digitalWrite(13,HIGH);
  delay(3000);
  digitalWrite(13,LOW);
  delay(1000);
  // put your main code here, to run repeatedly:
}
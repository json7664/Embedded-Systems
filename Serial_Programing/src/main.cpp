#include <Arduino.h>

void setup() {
  // put your setup code here, to run once
  Serial1.begin(115200);  // Serial1 transmit from the board
  Serial.begin(115200);
  
}
uint8_t myChar;
void loop() {
  // put your main code here, to run repeatedly:
  // Serial1.println("hello");
  // delay(1000);
  while (Serial1.available())
  {
   myChar = Serial1.read();   // Returns a character
   Serial.write(myChar);
  }
}
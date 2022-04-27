#include <Arduino.h>

extern "C" uint8_t getVal(char * myNumber);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  char* number = "2";
  int num = getVal(number);
  Serial.println(num);
  delay(1000);
}
#include <Arduino.h>
extern "C" uint8_t StrLen(char* MyString);
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
  
  char* testStr = "I hope you all get A's";
  uint8_t Counter= StrLen(testStr);
  Serial.println(Counter);
delay(1000);
}
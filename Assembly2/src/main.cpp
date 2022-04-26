#include <Arduino.h>
extern "C" uint8_t StrLen(char* MyString);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);
  char* testStr = "Hello world";
  Serial.println(StrLen(testStr));
}


// ---------Exam topics --------------------
// PC interupt
// UART interrupt

// writing and reading a function in assembly
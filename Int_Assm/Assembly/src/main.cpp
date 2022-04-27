#include <Arduino.h>

extern "C" uint8_t Aadd3(uint8_t a, uint8_t b, uint8_t c);
extern "C" uint8_t StrCount(char* c);
extern "C" void TglPORTC(uint8_t PinMask);
char* str = "Hello World";
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  DDRC |= (1<<7); //Output for C7
  

  
}

void loop() {
  // put your main code here, to run repeatedly:
  uint8_t result=Aadd3(1,2,3);
  
  TglPORTC((1<<7));
  uint8_t count = StrCount(str);
  Serial.println(count);
  delay(1000);

}
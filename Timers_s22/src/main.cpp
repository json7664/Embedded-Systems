#include <Arduino.h>
//Timer0
//Channel A = PB7 - D11
//Channel B = PD0 - SCL
//Setup a 1 khz Timer - Up to OCR0A
void setup() {
  // put your setup code here, to run once:
  DDRD |= (1<<0);
  TCCR0A=0b01010011;
  //       xx - A is disconnected
  //         xx - Non inverting PWM
  //           xx - Dont care
  //             xx - Fast PWM, OCR0A is TOP
 TCCR0B = 0b00000011;
 //         xxxx - Dont Care
//              x - Other wave bit
//               xxx - Div by 64 gives 8Us per tick * 125 = 1ms
OCR0A= 124;
OCR0B = 31;
  // put your main code here, to run repeatedly:

}

void loop() {
  OCR0B++;
  if (OCR0B>125)
    OCR0B=0;
    delay(100);

  
}
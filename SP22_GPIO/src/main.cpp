//My LED is pn C7
#include <Arduino.h>
/*
#define MyDDRC *(unsigned char*)0x27
#define MyPORTC *(unsigned char*)0x28
#define MyPin 7
#define MyPinON (1<<MyPin)
#define MyPinOFF ~(1<<MyPin)
*/
void setup() {
  // put your setup code here, to run once:
   
    //MyDDRC |= MyPinON;
    DDRC |= (1<<DDC7);


  }

void loop() {
  // put your main code here, to run repeatedly:
  //MyPORTC |= MyPinON;
PORTC ^= (1<<DDC7);
  delay(500);
  //MyPORTC &= MyPinOFF;
  //PORTC &= ~(1<<DDC7);;
  //delay(2000);



}
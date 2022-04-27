#include <Arduino.h>
//Blink with interrupts
//1 second duty cycle
//Use Timer 3
//Using PD0, INT0 for interrupt
//PB1 is SCK on micro
void setup() {
  // put your setup code here, to run once:
  DDRC |= (1<<7); //Set C7 as an output
  DDRD &= ~(1<<0); // PD0 is an input
  PORTD |= (1<<0);
  Serial.begin(9600);
 
  //////////////////////////////////////////////////////
  //Timer Setup
  ////////////////////////////////////////////////////////
 
  TCCR1A=0x00; //Disconnect all pins, simple timer count up to OCR3A
  TCCR1B=0b00001100; //CPS = 256, WG bits set for counter
  TCCR1C=0x0; //All disabled
  OCR1A=31250;// Overflow every 1 second
  TIMSK1=0b00000011; //Enable Overflow interrupt
  ///////////////////////////////////////////////////////
  
/////////////////////////////////////////////////
//Set up INT0 Interrupt
////////////////////////////////////////////////
//EICRA|=((1<<0)||(1<<1));
EICRA=0b00000001; //Setup INT0 for ANY Edge detection
EIMSK=0b00000001; //Turn on INT0


PCMSK0=0b00100000; //Enable PCINT1
PCICR=0b00000001; //Turn on PCINT0


}
ISR(PCINT0_vect)
{
  Serial.println("Soemthing happened with #9");
  
}
ISR(TIMER1_COMPA_vect)
{
    Serial.println("In Int");
    PORTC ^= (1<<7);
   
}
ISR(INT0_vect)
{
   if((PIND & 1) > 0)
    Serial.println("Rising Edge!!");
    else
    Serial.println("Falling Edge");


}
void loop() {
  // put your main code here, to run repeatedly:

}

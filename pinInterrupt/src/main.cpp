// Using PD0, INT0 FOR interrupt
// PB1 is on SCK on micro
#include <Arduino.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  DDRC |= (1<<7); // set C7 as an output pin Change 7 at d13 
  DDRD &= ~(1<<0); // PD0 as an input
  PORTD |= (1 << 0); // enabling pull up resistor
  TCCR1A = 0x00; // Disconnect the pins, simple timer count up to OCR3A 
  TCCR1B = 0b00001100; //CPS = 256, WG bits set for counter 
  TCCR1C = 0x00;       // all disabled
  OCR1A = 31250;// OVerflow every 1 second
  TIMSK1 = 0b00000011; // Enable overflow interrupt


////////////////////////////////////////////////
//////////////SETUP INT0 Interrupt

// EICRA = 0b00000011; // setup INT0 for rising edge detection
 EICRA = 0b00000001; // setup INT0 for any edge detection
 EIMSK = 0b00000001; // Turn ON INT0


 PCMSK0 = 0b00100000; // Enable PCINT0
 PCICR = 0b00000001; // Turn ON PCINT0
}

ISR(PCINT0_vect) 
{
  Serial.println("Something happened with #9");
}

ISR(TIMER1_COMPA_vect)
{
  PORTC ^= (1 << 7);
}

ISR(INT0_vect)
{
 if((PIND&1) > 0) Serial.println("Rising Edge");
 else Serial.println("Falling Edge");
}

void loop() {
  // put your main code here, to run repeatedly:
}
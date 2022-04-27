// Interrupts
// Blink example with interrrupts
// 1 second duty cycle
// Using timer 3 
#include <Arduino.h>

void TimSetup();

void setup() {
 // put your setup code here, to run once:
  DDRC |= (1<<7); // set C7 as an output pin Change 7 at d13
  // TimSetup();
  TCCR1A = 0x00; // Disconnect the pins, simple timer count up to OCR3A 
 TCCR1B = 0b00001100; //CPS = 256, WG bits set for counter 
 TCCR1C = 0x00;       // all disabled
 OCR1A = 31250;// OVerflow every 1 second
 TIMSK1 = 0b00000011; // Enable overflow interrupt

  sei();

}

ISR(TIMER1_COMPA_vect)
{
  PORTC ^= (1 << 7);
}

void loop() {
  // put your main code here, to run repeatedly:
  // if (DoOnce = 0) TimSetup()
}

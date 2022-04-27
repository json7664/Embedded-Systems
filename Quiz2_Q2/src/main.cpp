// Using the Adafruit circuit playground classic
// Assuming the switch is connected to the PIN PD4,
// Using Timer1 to comp and reset after 1 sec 
// Bounce time 50ms
#include <Arduino.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  DDRD &= ~(1 << 4);        // PD4 as an input
  PORTD |= (1 << 4);        // enabling the pullup resistor

  TCCR1A = 0x00;            // Disconnect the pins, simple timer count up to OCR3A 
  TCCR1B = 0b00001100;      //CPS = 256, WG bits set for counter 
  TCCR1C = 0x00;            // all disabled
  OCR1A = 31250;            // OVerflow every 1 second // 1562
  TIMSK1 = 0b00000011;      // Enable overflow interrupt
}

// Interrupt timer subroutine for 1 second press
ISR(TIMER1_COMPA_vect)
{
  delay(50); 
  if ((PIND & 1) > 0) Serial.println("Switch Pressed"); // Press left button
}

void loop() {
  // put your main code here, to run repeatedly:
}
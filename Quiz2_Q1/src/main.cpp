//Using the datasheet given for this question

///////////////////DATASHEET REGS ADDR//////////////////////
// +ve temp = (ADC code)/32
//-ve temp = (ADC code - 16384)/32
// To measure the temp using control reg (0x80 and 0x81)
// Status reg (0x8F)
// Temp data to read from reg addr 0x92 and 0x93 (Output of the register values)
////////////////////////////////////////////////////////////

// Using I2C communication protocol for this device 
// Assuming this device can use Arduino wire library for I2C comms 
#include <Arduino.h>
#include "Wire.h"

#define tempCtrlReg  *(uint8_t*)   0x80            // Control register addr for temperature
#define statusReg    *(uint8_t*)   0x8F            // Status register addr
#define sysClk       *(uint8_t*)   0x81            // System clk addr
#define tempDataReg1               0x92            // Output temp data reg1
#define tempDataReg2               0x93            // Output temp data reg2

void setup() {
  // put your setup code here, to run once:
  sysClk |= (1 << 0);                              // Setting the sysClk to internal clk
  Wire.begin();                                    // Setting for the I2C protocol
}

float getTemp()
{
    float ReturnByte;
    
    Wire.beginTransmission(statusReg);
    Wire.write(tempCtrlReg);
    Wire.endTransmission(false);
    Wire.requestFrom(statusReg,1,true);
    if (Wire.available()== statusReg)
        ReturnByte=(Wire.read()-16384)/32;
    else ReturnByte=(Wire.read())/32;
    return(ReturnByte);

} 

void loop() {
  // put your main code here, to run repeatedly:
 float temp =  getTemp();
 
}
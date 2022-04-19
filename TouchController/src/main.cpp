#include <Arduino.h>
#include "Wire.h"
//Touch Controller address 0x74, I2C
#define TC_ADDRESS 0x74
#define TC_FINGER_COUNT 0x0011
#define TC_SWIPEINFO 0x000D


void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  Serial.begin(9600);
}
/*GetFingerCount
* Returns number of fingers
* Register address 0x11
*/
uint8_t GetByteFromTC(uint8_t IQS_Address,uint16_t MemAddress)
{
  
  uint8_t ReturnByte=255;
  Wire.beginTransmission(IQS_Address);
  Wire.write(MemAddress >> 8);
  Wire.write((uint8_t)MemAddress);
  Wire.endTransmission(false);
  Wire.requestFrom(IQS_Address,1,true);
  if (Wire.available()==1)
    ReturnByte=Wire.read();
  return(ReturnByte);

}
void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);
  Serial.print ("Finger Count -> ");
  Serial.println(GetByteFromTC(TC_ADDRESS,TC_FINGER_COUNT));
  //delay (10);
  //uint8_t MyChar = GetByteFromTC(TC_ADDRESS,TC_SWIPEINFO);
  //if (MyChar != 0)
  //{
  //  Serial.print ("Swipe Data -> ");
  //Serial.println(GetByteFromTC(TC_ADDRESS,TC_SWIPEINFO));
//}

}
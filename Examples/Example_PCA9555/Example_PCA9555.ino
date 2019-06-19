#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
#include <Wire.h>
char incomingByte = 0;
#define U14PCA9555_ADDRESS (0x20)
#define U15PCA9555_ADDRESS (0x21)
#define DATA_SIZE 8

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("<Aduino is ready>");
  Serial.println("U14 Address is");
  Serial.println(U14PCA9555_ADDRESS);//32
  Wire.beginTransmission(U14PCA9555_ADDRESS);
  Wire.write(0x06);  // pointer
  Wire.write(0x0F);  // DDR Port0 bits 0-3 input 4-7 output 
  Wire.write(0x00);  // DDR Port1 all output
  Wire.endTransmission(); 
  Serial.println("U14PCA9555_ADDRESS, 0x06,0x0F,0x00"); 
  delay(3000);
  Serial.println("U15 Address is");
  Serial.println(U15PCA9555_ADDRESS);//33
  Wire.beginTransmission(U15PCA9555_ADDRESS);
  Wire.write(0x06);  // pointer
  Wire.write(0x0F);  // DDR Port0 bits 0-3 input 4-7 output 
  Wire.write(0x00);  // DDR Port1 all output
  Wire.endTransmission(); 
  Serial.println("U15PCA9555_ADDRESS, 0x06,0x0F,0x00"); 
   delay(2000);
 
}

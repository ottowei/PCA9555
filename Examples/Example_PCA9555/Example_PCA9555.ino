#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
#include <Wire.h>
char incomingByte = 0;
#define U14PCA9555_ADDRESS 0x20
#define U15PCA9555_ADDRESS 0x21
#define DATA_SIZE 8

void setup() {
  Serial.begin(9600);
  Serial.println("<Aduino is ready>");
  Serial.println("U14 Address is");
  Serial.println(U14PCA9555_ADDRESS);//32
  Wire.begin();
  Wire.beginTransmission(0x20);
  Wire.write(0x06);  // pointer
  Wire.write(0x00);  // DDR Port0 all output
  Wire.write(0x00);  // DDR Port1 all output
  Wire.endTransmission(); 
  Serial.println("U15 Address is");
  Serial.println(U15PCA9555_ADDRESS);//33
  Wire.beginTransmission(0x21);
  Wire.write(0x06);  // pointer
  Wire.write(0x00);  // DDR Port0 all output
  Wire.write(0x00);  // DDR Port1 all output
  Wire.endTransmission(); 

}

void loop() {

  Wire.beginTransmission(0x20);
  Wire.write(0x02);  // Output Port 0
  Wire.write(0x00);  // 0xFF = 5V //DDR Port0 bits 0-3 input 4-7 output
  // Wire.write(0x00);  // DDR Port1 all output
  Wire.endTransmission();
  Serial.println("U14PCA9555_ADDRESS, 0x02,0x00,0x00");
  delay(3000);
  // Serial.println("U15 Address is");
  // Serial.println(U15PCA9555_ADDRESS);//33
  Wire.beginTransmission(0x21);
  Wire.write(0x02);  // pointer
  Wire.write(0x00);  // 0xFF = 5V  DDR Port0 bits 0-3 input 4-7 output
  // Wire.write(0x00);  // DDR Port1 all output
  Wire.endTransmission();
  Serial.println("U15PCA9555_ADDRESS, 0x02,0x00,0x00");
  delay(2000);
 
}

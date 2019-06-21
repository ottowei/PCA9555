//#if defined(ARDUINO) && ARDUINO >= 100
//#include "Arduino.h"
//#else
//#include "WProgram.h"
//#endif
//#include <Wire.h>
//char incomingByte = 0;
//#define U14PCA9555_ADDRESS 0x20
//#define U15PCA9555_ADDRESS 0x21
//#define DATA_SIZE 8
//
//void setup() {
//  Serial.begin(9600);
//  Serial.println("<Aduino is ready>");
//  Serial.println("U14 Address is");
//  Serial.println(U14PCA9555_ADDRESS);//32
//  Wire.begin();
//  Wire.beginTransmission(0x20);
//  Wire.write(0x06);  // pointer
//  Wire.write(0x00);  // DDR Port0 all output
//  Wire.write(0x00);  // DDR Port1 all output
//  Wire.endTransmission(); 
//  Serial.println("U15 Address is");
//  Serial.println(U15PCA9555_ADDRESS);//33
//  Wire.beginTransmission(0x21);
//  Wire.write(0x06);  // pointer
//  Wire.write(0x00);  // DDR Port0 all output
//  Wire.write(0x00);  // DDR Port1 all output
//  Wire.endTransmission(); 
//
//}
//
//void loop() {
//
//  Wire.beginTransmission(0x20);
//  Wire.write(0x02);  // Output Port 0
//  Wire.write(0x00);  // 0xFF = 5V //DDR Port0 bits 0-3 input 4-7 output
//  // Wire.write(0x00);  // DDR Port1 all output
//  Wire.endTransmission();
//  Serial.println("U14PCA9555_ADDRESS, 0x02,0x00,0x00");
//  delay(3000);
//  // Serial.println("U15 Address is");
//  // Serial.println(U15PCA9555_ADDRESS);//33
//  Wire.beginTransmission(0x21);
//  Wire.write(0x02);  // pointer
//  Wire.write(0x00);  // 0xFF = 5V  DDR Port0 bits 0-3 input 4-7 output
//  // Wire.write(0x00);  // DDR Port1 all output
//  Wire.endTransmission();
//  Serial.println("U15PCA9555_ADDRESS, 0x02,0x00,0x00");
//  delay(2000);
// 
//}

/******************************************************************************
Test Program for the 12C PCA9555 Board part number DFR0013 IIC TO GPIO module from dfrobot.com
16 outputs that I used to drive this relay board made in Bulgaria
http://www.denkovi.com/product/21/16-relay-board-for-your-pic-avr-project-12v.html
it's a great little expansion board that can be used to drive LEDs or anything you want.
made by peter@testelectronics.com
January 07th 2011
My biggest problem was figuring out the I2C address of the PCA9555.
If there are no jumpers the address is 1 0 0 '1 1 1'
Jumpers make the address 1 0 0 '0 0 0'. This is opposite of what I expected.
******************************************************************************/

#include <Wire.h>

//  with no jumpers the full address is   1 0 0 1 1 1    1 0 0 A2 A1 A0  0x27 is the default address for the DFR0013 board with no jumpers.
#define PCA9555 0x20 // 0x27 is default address for the DFR0013 board with no jumpers.
                     // 0x20 is address for the DFR0013 board with all jumpers.
// COMMAND BYTE TO REGISTER RELATIONSHIP FROM PCA9555 DATA SHEET
// At reset, the device's ports are inputs with a high value resistor pull-ups to VDD
// If relays turning on during power up are a problem. Add a pull down resistor to each relay transistor base.

#define IN_P0 0x00 // Read Input port0
#define IN_P1 0x01 // Read Input port1
#define OUT_P0 0x02 // Write Output port0
#define OUT_P1 0x03 // Write Output port1
#define INV_P0 0x04 // Input Port Polarity Inversion port0 if B11111111 is written input polarity is inverted
#define INV_P1 0x05 // Input Port Polarity Inversion port1 if B11111111 is written input polarity is inverted
#define CONFIG_P0 0x06 // Configuration port0 configures the direction of the I/O pins 0 is output 1 is input
#define CONFIG_P1 0x07 // Configuration port1 configures the direction of the I/O pins 0 is output 1 is input

#define PAUSE 200

void setup()
{
  Wire.begin(PCA9555); // join i2c bus (address optional for master) tried to get working
  write_io (CONFIG_P0, B00000000); //defines all pins on Port0 are outputs
  write_io (CONFIG_P1, B00000000); //defines all pins on Port1 are outputs
  write_io (OUT_P0, B00000000); //clears all relays
  write_io (OUT_P1, B00000000); //clears all relays
  delay (PAUSE);
}


void loop()
{
  write_io (OUT_P0, B00000001);
  delay (PAUSE);
  write_io (OUT_P0, B00000010);
  delay (PAUSE);
  write_io (OUT_P0, B00000100);
  delay (PAUSE);
  write_io (OUT_P0, B00001000);
  delay (PAUSE);
  write_io (OUT_P0, B00010000);
  delay (PAUSE);
  write_io (OUT_P0, B00100000);
  delay (PAUSE);
  write_io (OUT_P0, B01000000);
  delay (PAUSE);
  write_io (OUT_P0, B10000000);
  delay (PAUSE);
  write_io (OUT_P0, B00000000);


  write_io (OUT_P1, B00000001);
  delay (PAUSE);
  write_io (OUT_P1, B00000010);
  delay (PAUSE);
  write_io (OUT_P1, B00000100);
  delay (PAUSE);
  write_io (OUT_P1, B00001000);
  delay (PAUSE);
  write_io (OUT_P1, B00010000);
  delay (PAUSE);
  write_io (OUT_P1, B00100000);
  delay (PAUSE);
  write_io (OUT_P1, B01000000);
  delay (PAUSE);
  write_io (OUT_P1, B10000000);
  delay (PAUSE);
  write_io (OUT_P1, B00000000);

}


 void write_io(int command, int value)
{
  Wire.beginTransmission(PCA9555);
  Wire.write(command),Wire.write(value);
  Wire.endTransmission();
}

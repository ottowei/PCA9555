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

#include <Wire.h>

#define chip1 0x20
#define chip2 0x21

#define IN_P0 0x00 // Read Input port0
#define IN_P1 0x01 // Read Input port1
#define OUT_P0 0x02 // Write Output port0
#define OUT_P1 0x03 // Write Output port1
#define INV_P0 0x04 // Input Port Polarity Inversion port0 if B11111111 is written input polarity is inverted
#define INV_P1 0x05 // Input Port Polarity Inversion port1 if B11111111 is written input polarity is inverted
#define CONFIG_P0 0x06 // Configuration port0 configures the direction of the I/O pins 0 is output 1 is input
#define CONFIG_P1 0x07 // Configuration port1 configures the direction of the I/O pins 0 is output 1 is input

#define PAUSE 200

String myString,tempString;
int Position1,Position2,Position3;
int chip,port,port_status; // Chip 1(0x20), 2(0x21) ; port  0x(0-7)) ,1x(0-7);port_status High or Low

void setup()
{ 
  Serial.begin(9600); // initialize serial interface for print()
  Serial.setTimeout(10);
  Wire.begin(chip1); // join i2c bus (address optional for master) tried to get working
  write_io (chip1,CONFIG_P0, B00000000); //defines all pins on Port0 are outputs
  write_io (chip1,CONFIG_P1, B00000000); //defines all pins on Port1 are outputs
  write_io (chip1,OUT_P0, B00000000); //clears all relays
  write_io (chip1,OUT_P1, B00000000); //clears all relays
  Wire.begin(chip2); // join i2c bus (address optional for master) tried to get working
  write_io (chip2,CONFIG_P0, B00000000); //defines all pins on Port0 are outputs
  write_io (chip2,CONFIG_P1, B00000000); //defines all pins on Port1 are outputs
  write_io (chip2,OUT_P0, B00000000); //clears all relays
  write_io (chip2,OUT_P1, B00000000); //clears all relays
  delay (PAUSE);
}


void loop()
{ 
  if (Serial.available()) {
     myString=Serial.readString();
     split();
     //chip=chip-32;
     Serial.print("1st chip=");
     Serial.println(chip);
  }
  switch(chip){
      case 1 :            // chip1 , port 0 , pin0
        switch(port){
          case 0 :     // port 0 ,pin 0
              switch(port_status){
                 case 0:      // 0 Low
                     write_io (chip1, OUT_P0, B00000000);
                     Serial.println("Chip 1 Port0 Pin0 Off");
                     Serial.println(chip1);
                     break;
                 case 1:     // 1 High
                     write_io (chip1, OUT_P0, B00000001);
                     Serial.println("Chip 1 Port0 Pin0 ON");
                     break;
              }
              break;         
            
          case 1 : // chip1 , port 0 , pin1
              switch(port_status){
                 case 0:
                     write_io (chip1, OUT_P0, B00000000);
                     Serial.println("Chip 1 Port0 Pin1 Off");
                     break;
                 case 1:
                     write_io (chip1, OUT_P0, B00000010);
                     Serial.println("Chip 1 Port0 Pin1 ON");
                     break;
              }
              break; 
              
          case 2 : // chip1 , port 0 , pin2
                 switch(port_status){
                 case 0:
                     write_io (chip1, OUT_P0, B00000000);
                     Serial.println("Chip 1 Port0 Pin2 Off");
                     break;
                 case 1:
                     write_io (chip1, OUT_P0, B00000100);
                     Serial.println("Chip 1 Port0 Pin2 ON");
                     break;
              }
              break; 
              
          case 3 :// chip1 , port 0 , pin3
                 switch(port_status){
                 case 0:
                     write_io (chip1, OUT_P0, B00000000);
                     Serial.println("Chip 1 Port0 Pin3 Off");
                     break;
                 case 1:
                     write_io (chip1, OUT_P0, B00001000);
                     Serial.println("Chip 1 Port0 Pin3 ON");
                     break;
              }
              break; 
              
          case 4 : // chip1 , port 0 , pin4
                  switch(port_status){
                 case 0:
                     write_io (chip1, OUT_P0, B00000000);
                     Serial.println("Chip 1 Port0 Pin4 Off");
                     break;
                 case 1:
                     write_io (chip1, OUT_P0, B00010000);
                     Serial.println("Chip 1 Port0 Pin4 ON");
                     break;
              }
              break; 
              
          case 5 : // chip1 , port 0 , pin5
                  switch(port_status){
                 case 0:
                     write_io (chip1, OUT_P0, B00000000);
                     Serial.println("Chip 1 Port0 Pin5 Off");
                     break;
                 case 1:
                     write_io (chip1, OUT_P0, B00100000);
                     Serial.println("Chip 1 Port0 Pin5 On");
                     break;
              }
              break; 
              
          case 6 : // chip1 , port 0 , pin6
                  switch(port_status){
                 case 0:
                     write_io (chip1, OUT_P0, B00000000);
                     Serial.println("Chip 1 Port0 Pin6 Off");
                     break;
                 case 1:
                     write_io (chip1, OUT_P0, B01000000);
                     Serial.println("Chip 1 Port0 Pin6 On");
                     break;
              }
              break; 
              
          case 7 :  // chip1 , port 0 , pin7
                  switch(port_status){
                 case 0:
                     write_io (chip1, OUT_P0, B00000000);
                     Serial.println("Chip 1 Port0 Pin7 Off");
                     break;
                 case 1:
                     write_io (chip1, OUT_P0, B10000000);
                     Serial.println("Chip 1 Port0 Pin7 On");
                     break;
              }
              break; 
              
          case 8 :  // chip1 , port 1 , pin0
                  switch(port_status){
                 case 0:
                     write_io (chip1, OUT_P1, B00000000);
                     Serial.println("Chip 1 Port1 Pin0 Off");
                     break;
                 case 1:
                     write_io (chip1, OUT_P1, B00000001);
                     Serial.println("Chip 1 Port1 Pin0 On");
                     break;
              }
              break; 
              
          case 9 :  // chip1 , port 1 , pin1
              switch(port_status){
                 case 0:
                     write_io (chip1, OUT_P1, B00000000);
                     Serial.println("Chip 1 Port1 Pin1 Off");
                     break;
                 case 1:
                     write_io (chip1, OUT_P1, B00000010);
                     Serial.println("Chip 1 Port1 Pin1 On");
                     break;
              }
              break; 
              
          case 10 :  // chip1 , port 1 , pin2
              switch(port_status){
                 case 0:
                     write_io (chip1, OUT_P1, B00000000);
                     Serial.println("Chip 1 Port1 Pin2 Off");
                     break;
                 case 1:
                     write_io (chip1, OUT_P1, B00000100);
                     Serial.println("Chip 1 Port1 Pin2 On");
                     break;
              }
              break; 
                 
          case 11 :  // chip1 , port 1 , pin3
              switch(port_status){
                 case 0:
                     write_io (chip1, OUT_P1, B00000000);
                     Serial.println("Chip 1 Port1 Pin3 Off");
                     break;
                 case 1:
                     write_io (chip1, OUT_P1, B00001000);
                     Serial.println("Chip 1 Port1 Pin3 On");
                     break;
              }
              break; 
              
          case 12 :  // chip1 , port 1 , pin4
              switch(port_status){
                 case 0:
                     write_io (chip1, OUT_P1, B00000000);
                     Serial.println("Chip 1 Port1 Pin4 Off");
                     break;
                 case 1:
                     write_io (chip1, OUT_P1, B00010000);
                     Serial.println("Chip 1 Port1 Pin4 On");
                     break;
              }
              break; 
              
          case 13 :  // chip1 , port 1 , pin5
              switch(port_status){
                 case 0:
                     write_io (chip1, OUT_P1, B00000000);
                     Serial.println("Chip 1 Port1 Pin5 Off");
                     break;
                 case 1:
                     write_io (chip1, OUT_P0, B00100000);
                     Serial.println("Chip 1 Port1 Pin5 On");
                     break;
              }
              break; 
              
          case 14 : // chip1 , port 1 , pin6
              switch(port_status){
                 case 0:
                     write_io (chip1, OUT_P1, B00000000);
                     Serial.println("Chip 1 Port1 Pin6 Off");
                     break;
                 case 1:
                     write_io (chip1, OUT_P1, B01000000);
                     Serial.println("Chip 1 Port1 Pin6 On");
                     break;
              }
              break; 
              
          case 15 : // chip1 , port 1 , pin7
              switch(port_status){
                 case 0:
                     write_io (chip1, OUT_P1, B00000000);
                     Serial.println("Chip 1 Port1 Pin7 Off");
                     break;
                 case 1:
                     write_io (chip1, OUT_P1, B10000000);
                     Serial.println("Chip 1 Port1 Pin7 On");
                     break;
              }
          break;
         
        }
        break;
        
     case 2 :    // chip2 , port 0 , pin0
        switch(port){
          case 0 :     // port 0 ,pin 0
              switch(port_status){
                 case 0:      // 0 Low
                     write_io (chip2, OUT_P0, B00000000);
                     Serial.println("Chip 2 Port0 Pin0 Off");
                     break;
                 case 1:     // 1 High
                     write_io (chip2, OUT_P0, B00000001);
                     Serial.println("Chip 2 Port0 Pin0 On");
                     break;
              }
              break;              
            
          case 1 : // chip2 , port 0 , pin1
              switch(port_status){
                 case 0:
                     write_io (chip2, OUT_P0, B00000000);
                     Serial.println("Chip 2 Port0 Pin1 Off");
                     break;
                 case 1:
                     write_io (chip2, OUT_P0, B00000010);
                     Serial.println("Chip 2 Port0 Pin1 On");
                     break;
              }
              break; 
              
          case 2 : // chip1 , port 0 , pin2
                 switch(port_status){
                 case 0:
                     write_io (chip2, OUT_P0, B00000000);
                     Serial.println("Chip 2 Port0 Pin2 Off");
                     break;
                 case 1:
                     write_io (chip2, OUT_P0, B00000100);
                     Serial.println("Chip 2 Port0 Pin2 On");
                     break;
              }
              break; 
              
          case 3 :// chip1 , port 0 , pin3
                 switch(port_status){
                 case 0:
                     write_io (chip2, OUT_P0, B00000000);
                     Serial.println("Chip 2 Port0 Pin3 Off");
                     break;
                 case 1:
                     write_io (chip2, OUT_P0, B00001000);
                     Serial.println("Chip 2 Port0 Pin3 On");
                     break;
              }
              break; 
              
          case 4 : // chip1 , port 0 , pin4
                  switch(port_status){
                 case 0:
                     write_io (chip2, OUT_P0, B00000000);
                     Serial.println("Chip 2 Port0 Pin4 Off");
                     break;
                 case 1:
                     write_io (chip2, OUT_P0, B00010000);
                     Serial.println("Chip 2 Port0 Pin4 On");
                     break;
              }
              break; 
              
          case 5 : // chip1 , port 0 , pin5
                  switch(port_status){
                 case 0:
                     write_io (chip2, OUT_P0, B00000000);
                     Serial.println("Chip 2 Port0 Pin5 Off");
                     break;
                 case 1:
                     write_io (chip2, OUT_P0, B00100000);
                     Serial.println("Chip 2 Port0 Pin5 On");
                     break;
              }
              break; 
              
          case 6 : // chip1 , port 0 , pin6
                  switch(port_status){
                 case 0:
                     write_io (chip2, OUT_P0, B00000000);
                     Serial.println("Chip 2 Port0 Pin6 Off");
                     break;
                 case 1:
                     write_io (chip2, OUT_P0, B01000000);
                     Serial.println("Chip 2 Port0 Pin6 On");
                     break;
              }
              break; 
              
          case 7 :  // chip1 , port 0 , pin7
                  switch(port_status){
                 case 0:
                     write_io (chip2, OUT_P0, B00000000);
                     Serial.println("Chip 2 Port0 Pin7 Off");
                     break;
                 case 1:
                     write_io (chip2, OUT_P0, B10000000);
                     Serial.println("Chip 2 Port0 Pin7 On");
                     break;
              }
              break; 
              
          case 8 :  // chip1 , port 1 , pin0
                  switch(port_status){
                 case 0:
                     write_io (chip2, OUT_P1, B00000000);
                     Serial.println("Chip 2 Port1 Pin0 Off");
                     break;
                 case 1:
                     write_io (chip2, OUT_P1, B00000001);
                     Serial.println("Chip 2 Port1 Pin0 On");
                     break;
              }
              break; 
              
          case 9 :  // chip1 , port 1 , pin1
              switch(port_status){
                 case 0:
                     write_io (chip2, OUT_P1, B00000000);
                     Serial.println("Chip 2 Port1 Pin1 Off");
                     break;
                 case 1:
                     write_io (chip2, OUT_P1, B00000010);
                     Serial.println("Chip 2 Port1 Pin1 On");
                     break;
              }
              break; 
              
          case 10 :  // chip1 , port 1 , pin2
              switch(port_status){
                 case 0:
                     write_io (chip2, OUT_P1, B00000000);
                     Serial.println("Chip 2 Port1 Pin2 Off");
                     break;
                 case 1:
                     write_io (chip2, OUT_P1, B00000100);
                     Serial.println("Chip 2 Port1 Pin2 On");
                     break;
              }
              break; 
                 
          case 11 :  // chip1 , port 1 , pin3
              switch(port_status){
                 case 0:
                     write_io (chip2, OUT_P1, B00000000);
                     Serial.println("Chip 2 Port1 Pin3 Off");
                     break;
                 case 1:
                     write_io (chip2, OUT_P1, B00001000);
                     Serial.println("Chip 2 Port1 Pin3 On");
                     break;
              }
              break; 
              
          case 12 :  // chip1 , port 1 , pin4
              switch(port_status){
                 case 0:
                     write_io (chip2, OUT_P1, B00000000);
                     Serial.println("Chip 2 Port1 Pin4 Off");
                     break;
                 case 1:
                     write_io (chip2, OUT_P1, B00010000);
                     Serial.println("Chip 2 Port1 Pin4 On");
                     break;
              }
              break; 
              
          case 13 :  // chip1 , port 1 , pin5
              switch(port_status){
                 case 0:
                     write_io (chip2, OUT_P1, B00000000);
                     Serial.println("Chip 2 Port1 Pin5 Off");
                     break;
                 case 1:
                     write_io (chip2, OUT_P0, B00100000);
                     Serial.println("Chip 2 Port1 Pin5 On");
                     break;
              }
              break; 
              
          case 14 : // chip1 , port 1 , pin6
              switch(port_status){
                 case 0:
                     write_io (chip2, OUT_P1, B00000000);
                     Serial.println("Chip 2 Port1 Pin6 Off");
                     break;
                 case 1:
                     write_io (chip2, OUT_P1, B01000000);
                     Serial.println("Chip 2 Port1 Pin6 On");
                     break;
              }
              break; 
              
          case 15 : // chip1 , port 1 , pin7
              switch(port_status){
                 case 0:
                     write_io (chip2, OUT_P1, B00000000);
                     Serial.println("Chip 2 Port1 Pin7 Off");
                     break;
                 case 1:
                     write_io (chip2, OUT_P1, B10000000);
                     Serial.println("Chip 2 Port1 Pin7 On");
                     break;
              }
              break; 
         
        }
        break;
  }
  chip=0;
}


 void write_io(int a ,int command, int value1)
{ 
  Serial.print("chip=");
  Serial.println(a);
  Serial.println(command);
  Serial.println(value1);
  if(a==32){
  Wire.beginTransmission(0x20);
  //Serial.println("Chip 1 Tx");
  }else if(a==33){
  Wire.beginTransmission(0x21); 
  //Serial.println("Chip 2 Tx");
  } else {
  Serial.println("No Output IC");
  }
  Wire.write(command);
  Wire.write(value1);
  Wire.endTransmission();
  Serial.println(command);
  Serial.println(value1);
}


void split(){
     Position1=myString.indexOf(',');
     Position2=myString.indexOf(',',Position1+1);
     Position3=myString.indexOf(',',Position2+1);
     //Position4=myString.indexOf(',',Position3+1);
     //Position5=myString.indexOf(',',Position4+1);
     tempString=myString.substring(0,Position1);
     chip=tempString.toInt();
     tempString=myString.substring(Position1+1,Position2);
     port=tempString.toInt();
     tempString=myString.substring(Position2+1,Position3);
     port_status=tempString.toInt();

     Serial.print("chip:");
     Serial.println(chip); 
     Serial.print("Port:"); 
     Serial.println(port); 
     Serial.print("Port_Status:"); 
     Serial.println(port_status);
   
     
     
}



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
//
//#include <Wire.h>
//
////  with no jumpers the full address is   1 0 0 1 1 1    1 0 0 A2 A1 A0  0x27 is the default address for the DFR0013 board with no jumpers.
//#define PCA9555 0x20 // 0x27 is default address for the DFR0013 board with no jumpers.
//                     // 0x20 is address for the DFR0013 board with all jumpers.
//// COMMAND BYTE TO REGISTER RELATIONSHIP FROM PCA9555 DATA SHEET
//// At reset, the device's ports are inputs with a high value resistor pull-ups to VDD
//// If relays turning on during power up are a problem. Add a pull down resistor to each relay transistor base.
//
//#define IN_P0 0x00 // Read Input port0
//#define IN_P1 0x01 // Read Input port1
//#define OUT_P0 0x02 // Write Output port0
//#define OUT_P1 0x03 // Write Output port1
//#define INV_P0 0x04 // Input Port Polarity Inversion port0 if B11111111 is written input polarity is inverted
//#define INV_P1 0x05 // Input Port Polarity Inversion port1 if B11111111 is written input polarity is inverted
//#define CONFIG_P0 0x06 // Configuration port0 configures the direction of the I/O pins 0 is output 1 is input
//#define CONFIG_P1 0x07 // Configuration port1 configures the direction of the I/O pins 0 is output 1 is input
//
//#define PAUSE 200
//
//int incomingByte = 0; // Store recieved data byte, ottowei, 2019062402
//
//
//void setup()
//{
//  Serial.begin(9600);
//  Wire.begin(PCA9555); // join i2c bus (address optional for master) tried to get working
//  write_io (CONFIG_P0, B00000000); //defines all pins on Port0 are outputs
//  write_io (CONFIG_P1, B00000000); //defines all pins on Port1 are outputs
//  write_io (OUT_P0, B00000000); //clears all relays
//  write_io (OUT_P1, B00000000); //clears all relays
//  delay (PAUSE);
//}
//
//
//void loop()
//{
//  Serial.println("Please Enter Commands : ");	  // Open Serial port, speed is 9600 bps, ottowei, 2019062401
//
//  // Read incoming byte, ottowei, 2019062403
//  if (Serial.available() > 0)
//  {
//	  incomingByte = Serial.read();
//   	  // print entered data
//	  Serial.print("data received: ");
//	  Serial.print(incomingByte, DEC);
//	  Serial.println(" (DEC)");
//	  Serial.print(", ");
//	  Serial.print(incomingByte, HEX);
//	  Serial.println(" (HEX)");
//	  delay(3000);
//  }
//  write_io (OUT_P0, B00000001);
//  delay (PAUSE);
//  write_io (OUT_P0, B00000010);
//  delay (PAUSE);
//  write_io (OUT_P0, B00000100);
//  delay (PAUSE);
//  write_io (OUT_P0, B00001000);
//  delay (PAUSE);
//  write_io (OUT_P0, B00010000);
//  delay (PAUSE);
//  write_io (OUT_P0, B00100000);
//  delay (PAUSE);
//  write_io (OUT_P0, B01000000);
//  delay (PAUSE);
//  write_io (OUT_P0, B10000000);
//  delay (PAUSE);
//  write_io (OUT_P0, B00000000);
//
//
//  write_io (OUT_P1, B00000001);
//  delay (PAUSE);
//  write_io (OUT_P1, B00000010);
//  delay (PAUSE);
//  write_io (OUT_P1, B00000100);
//  delay (PAUSE);
//  write_io (OUT_P1, B00001000);
//  delay (PAUSE);
//  write_io (OUT_P1, B00010000);
//  delay (PAUSE);
//  write_io (OUT_P1, B00100000);
//  delay (PAUSE);
//  write_io (OUT_P1, B01000000);
//  delay (PAUSE);
//  write_io (OUT_P1, B10000000);
//  delay (PAUSE);
//  write_io (OUT_P1, B00000000);
//
//}
//
//
// void write_io(int command, int value)
//{
//  Wire.beginTransmission(PCA9555);
//  Wire.write(command),Wire.write(value);
//  Wire.endTransmission();
//}
//
//void setup() {
//  Serial.begin(9600);
//}
//
//void loop() {
//  int a = 65;
//  boolean b = true;
//  Serial.println(a);             //頛詨 65 (��身 DEC)
//  Serial.println(a, DEC);   //頛詨 65
//  Serial.println(a, BIN);    //頛詨 1000001
//  Serial.println(a, HEX);   //頛詨 41
//  Serial.println(a, OCT);   //頛詨 101
//  Serial.println(b);             //頛詨 1
//  Serial.println(false);        //頛詨 0
//  delay(2000);
//}

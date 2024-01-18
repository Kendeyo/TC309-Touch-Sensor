/*
*  Description : Codebase for  working with the TC309 Touch Sensor IC
* Author       : Kennedy Odeyo
*
* (c) Phinalabs
* Licence : MIT
*/

#include <Wire.h>
#include <stdio.h>
#include <stdint.h>

void setup() {
  Wire.begin(); // Initialize I2C communication
  Serial.begin(9600); // Start serial communication for debugging
}

void loop() {
  Wire.requestFrom(0x40, 2); // Request 2 bytes of data from the device :0x40
  
  while (Wire.available()) {
    // Read data from the device
  byte highByte = Wire.read(); // Read the most significant byte
  byte lowByte = Wire.read();  // Read the least significant byte

  int data1 = highByte;
  int data2 = lowByte;

// Typecasting the data to 16 bits, shifting the LSB and ORing to get a single value
  uint16_t touch1 = (uint16_t)data1;
  uint16_t touch2 = ((uint16_t)data2) << 8;
  uint16_t touch = touch1 | touch2;
  
 // Hex Value for the various pads Touched
  typedef enum {
    Touch1 = 0xFFEF,
    Touch2 = 0xFFE7, 
    Touch3 = 0xFFFB,
    Touch4 = 0xFFFD,
    Touch5 = 0xFFFE,
    Touch6 = 0x7FFF,
    Touch7 = 0xBFFF,
    Touch8 = 0xDFFF,
    Touch9 = 0xEFFF
    }numtouch;
   
  numtouch myTouchPad;   // creating an enum of numtouch

  myTouchPad = touch; 
    
  char buff[18] = {0}; // an array buffer to hold the string showcasing  the touched pad
  //memset(buff,0,16);
    
  switch (myTouchPad){
    
    case Touch1:
    strcpy(buff,(const char*)"Touch 1");  
    break;
    case Touch2:
    strcpy(buff,(const char*)"Touch 2");
    break;
    case Touch3:
    strcpy(buff,(const char*)"Touch 3"); 
    break;  
    case Touch4:
    strcpy(buff,(const char*)"Touch 4"); 
    break;
    case Touch5:
    strcpy(buff,(const char*)"Touch 5"); 
    break; 
    case Touch6:
    strcpy(buff,(const char*)"Touch 6");
    break; 
    case Touch7:
    strcpy(buff,(const char*)"Touch 7"); 
    break;  
    case Touch8:
    strcpy(buff,(const char*)"Touch 8"); 
    break;  
    case Touch9:
    strcpy(buff,(const char*)"Touch 9"); 
    break; 
    default:
    strcpy(buff,(const char*)"No Pad Pressed"); 
    break;
    }

 Serial.println(buff);

  
  delay(1000); //delay to prevent continuous reading
}
}



 

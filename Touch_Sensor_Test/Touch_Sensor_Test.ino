#include <Wire.h>

void setup() {
  Wire.begin(); // Initialize I2C communication
  Serial.begin(9600); // Start serial communication for debugging
}

void loop() {
  Wire.requestFrom(0x40, 2); // Request 2 bytes of data from the device :0x40
  
  while (Wire.available()) {
    // Read data from the device
   byte data = Wire.read();
   Serial.println(data);

  }

  delay(1000); //delay to prevent continuous reading
}




 

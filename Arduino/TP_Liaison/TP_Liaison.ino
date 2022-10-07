#include <SoftwareSerial.h> 
SoftwareSerial mySerial(3, 4);
void setup() 
 {
  Serial.begin(9600);
  mySerial.begin(9600);
 }

void loop() 
 {
  mySerial.print('Z');
  delay(500);
 }

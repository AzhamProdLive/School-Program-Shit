#include <SoftwareSerial.h>
SoftwareSerial Transmission(2,3);
SoftwareSerial Reception(8,9);
char recu;

void setup() {
  Serial.begin(9600);
  while(!Serial){ //Pour USB Arduino Natif
    ;
  }
Transmission.begin(9600);
Reception.begin(9600);
delay(1000);
}

void loop() {

  Transmission.listen();
  Serial.print("Data from port one :");
  while(Transmission.available()>0)
  {
     char inByte = Transmission.read();
     delay(100);
     Serial.write(inByte);
  }
  Serial.println();
  Reception.listen();
  Serial.print("Data from port two");
  while(Reception.available()>0);
}

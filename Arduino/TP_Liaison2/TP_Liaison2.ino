#include <SoftwareSerial.h>
SoftwareSerial mySerial(3, 2);
char recu;
boolean etat=LOW;

void setup()
{
 pinMode(8,OUTPUT);
 digitalWrite(8, LOW);
 mySerial.begin(9600);
 delay(1000);
 
}

void loop() 
{
 if(mySerial.available())
 {
 recu = mySerial.read();
  if (recu = "Z")
  digitalWrite(8, etat);
  etat = ! etat;
 }
 delay(1000);
}

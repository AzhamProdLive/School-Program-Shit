#include <SoftwareSerial.h>
SoftwareSerial mySerial = SoftwareSerial (2, 3);
int valeur ;
void setup() {
pinMode (2, INPUT);
pinMode (3, OUTPUT);
mySerial.begin (9600);
  Serial.begin(9600);
  while (!Serial) {
    ;
  }
  }
  
  void loop() {
    valeur = mySerial.read ();
    if ( valeur == 'Z') {
      Serial.print("A");
    }
  }

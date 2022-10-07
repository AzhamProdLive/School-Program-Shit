#include <SoftwareSerial.h>
SoftwareSerial mySerial = SoftwareSerial (3, 2);
void setup() {
pinMode (3, INPUT);
pinMode (2, OUTPUT);
mySerial.begin (9600);
  while (!Serial) {
    ;
  }
  }

void loop() {
mySerial.write('Z');
delay(100);
}

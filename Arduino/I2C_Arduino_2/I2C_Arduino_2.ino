#include <Wire.h>
int LED = 13;
int x = 0;

void setup() {
  pinMode (LED, OUTPUT);
  Wire.begin(9);
  Wire.onReceive(receiveEvent);
  Serial.begin(9600);
}

void receiveEvent() {
  x = Wire.read();
}

void loop() {
  if (x % 2 == 0) {
    digitalWrite(LED, HIGH);
  }
  else {
    digitalWrite(LED, LOW);
  }
  Serial.print(x);
  delay(500);
}

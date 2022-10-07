#include <LiquidCrystal.h>

int i;

void setup() {
  Serial.begin(9600);
  i = analogRead(0);
  Serial.print(i, BIN);
  
}

void loop() {
 
}

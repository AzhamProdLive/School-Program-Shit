#include <Wire.h>
int x = 0;

void setup() {
 Wire.begin();
}

void loop() {
  Wire.beginTransmission(0x09);
  Wire.write(x);
  Wire.endTransmission();
  x++;
  delay(500);     
}

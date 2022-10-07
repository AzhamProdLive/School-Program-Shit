#include <LiquidCrystal.h>
int i;
float b;

const int rs = 13, rw = 12, e = 11, d4 = 10, d5 = 9, d6 = 8, d7 = 7;
LiquidCrystal lcd(rs, rw, e, d4, d5, d6, d7);

void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(0, 0); 
  Serial.begin(9600);
  i = analogRead(0);
  b = 5/1024*a;
  Serial.print(i, BIN);
  lcd.print(b);
}

void loop() {
}

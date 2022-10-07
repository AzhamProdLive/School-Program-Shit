#include <LiquidCrystal_I2C.h>

const int rs = 13, rw = 12, e = 11, d4 = 10, d5 = 9, d6 = 8, d7 = 7;
LiquidCrystal lcd(rs, rw, e, d4, d5, d6, d7);

void setup() {
  lcd.begin(16,2); 
}

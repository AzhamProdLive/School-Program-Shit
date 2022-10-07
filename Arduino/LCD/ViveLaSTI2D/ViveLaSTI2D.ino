
// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 13, rw = 12, e = 11, d4 = 10, d5 = 9, d6 = 8, d7 = 7;
LiquidCrystal lcd(rs, rw, e, d4, d5, d6, d7);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(0, 2);
  // Print a message to the LCD.
  lcd.print("Vive la STI2D!");
}

void loop() {

  lcd.scrollDisplayRight();
  delay(55);
 
}

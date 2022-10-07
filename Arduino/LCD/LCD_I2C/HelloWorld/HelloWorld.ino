//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  

void setup()
{
  lcd.init();                     
  lcd.backlight();
}


void loop()
{
  lcd.setCursor(0,0);
  lcd.print("RomainTheCAT B-)");
  lcd.scrollDisplayRight();
  delay(50);
  lcd.setCursor(0,1);
  lcd.print("_(^-^)/ -(UwU)/");
  lcd.scrollDisplayRight();
  delay(50);
}

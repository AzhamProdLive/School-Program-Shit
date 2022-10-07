
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  

int valeur ;
int analogPin = 0 ; // Définit quelle broche analogique va être utilisée

void setup()
{
  lcd.init();                     
  lcd.backlight();
  Serial.begin(19200); // Mets en place le terminal en décimal
}


void loop()
{
  valeur = analogRead(analogPin); // Mettre la valeur de la broche à la variable

  Serial.println(valeur); // Ecrire sur le terminal la valeur

  lcd.print(valeur); // Ecrire sur le LCD la valeur

  delay(500);

  lcd.clear();

  delay(10); 
}

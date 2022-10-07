#include <LiquidCrystal.h>

boolean BoutonOuverture=LOW;
boolean BoutonFermeture=LOW;
const int rs = 7, rw = 6, e = 5, d4 = 4, d5 = 3, d6 = 2, d7 = 1;
LiquidCrystal lcd(rs, rw, e, d4, d5, d6, d7);

void setup() {
  lcd.begin(16, 2);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,INPUT);
  pinMode(11,INPUT);
}

void loop() {
  
BoutonOuverture = digitalRead(10);

while (BoutonOuverture==HIGH)
    {
    digitalWrite(8,HIGH);
    BoutonOuverture= digitalRead(10);
    }
    delay(100);
    digitalWrite(8,LOW);

BoutonFermeture = digitalRead(11);

while (BoutonFermeture==HIGH) 
    {
    digitalWrite(9,HIGH);
    BoutonFermeture= digitalRead(11);
    }
    delay(100);
    digitalWrite(9,LOW);
  }

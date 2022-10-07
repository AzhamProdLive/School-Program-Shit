
#include <LiquidCrystal.h> // inclure la librairie LiquidCrystal qui permet de faire fonctionner un écran LCD

const int rs = 13, rw = 12, e = 11, d4 = 10, d5 = 9, d6 = 8, d7 = 7; // attribue les broches de la carte aux broches de l'écran
LiquidCrystal lcd(rs, rw, e, d4, d5, d6, d7); // définit quelles broches seront utilisées pour afficher le texte

boolean etat_bouton1 = LOW ;
boolean etat_bouton2 = LOW ;

void setup () 
{

  lcd.begin(16, 2); // définit le nombre de colonnes et lignes que l'on souhaite utiliser sur l'écran
  lcd.clear(); // efface le texte présent sur l'écran
  
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);

}


void loop () 
{

  etat_bouton1 = digitalRead (3) ;
  etat_bouton2 = digitalRead (4) ;

  if (etat_bouton1 == HIGH) // Si le bouton 1 est activé 
  {
    lcd.print("Sens trigo"); // écrire "Sens trigo" sur l'écran
    etat_bouton1 = digitalRead (3) ;
    while (etat_bouton1 == HIGH) // tant que le bouton est activé
    {
    digitalWrite(5, HIGH); // activer le relais 1 (moteur sens trigo)
    etat_bouton1 = digitalRead (3) ;
    }
  }  
  lcd.clear(); // efface le texte présent sur l'écran
  digitalWrite(5, LOW); // désactiver le relais 1
  
 if (etat_bouton2 == HIGH) // Si le bouton 2 est activé
  {
    lcd.print("Sens horaire"); // écrire "Sens horaire" sur l'écran
    etat_bouton2 = digitalRead (4) ;
    while (etat_bouton2 == HIGH) // tant que le bouton est activé
    {
    digitalWrite(6, HIGH); // activer le relais 2 (moteur sens horaire)
    etat_bouton2 = digitalRead (4) ;
    }
  }
  lcd.clear(); // efface le texte présent sur l'écran
  digitalWrite(6, LOW); // désactiver le relais 2
 
}

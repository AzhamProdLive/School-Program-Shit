#include <SoftwareSerial.h>
SoftwareSerial HC05(0, 1);

void setup() 
{
  HC05.begin(9600);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop()
{
  char commande;

  if(HC05.available())
  {
    commande = HC05.read();

    if(commande == 'r')
    {
      digitalWrite(10, HIGH);
      HC05.print("Couleur Rouge");
    }
    
    if(commande == 'g')
    {
      digitalWrite(11, HIGH);
      HC05.print("Couleur Verte");
    }

    if(commande == 'b')
    {
      digitalWrite(9, HIGH);
      HC05.print("Couleur Bleue");
    }

    if(commande == 's')
    {
      digitalWrite(10, LOW);
      digitalWrite(11, LOW);
      digitalWrite(9, LOW);
      HC05.print("Arrêt des LEDs");
    }
  }
}


boolean etat_bouton1 = LOW ;
boolean etat_bouton2 = LOW ;

void setup () 
{

  pinMode(9, INPUT);
  pinMode(10, INPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);

}


void loop () 
{

  etat_bouton1 = digitalRead (9) ;
  etat_bouton2 = digitalRead (10) ;

  if (etat_bouton1 == HIGH)
  {
    digitalWrite(11, HIGH);
  }
  
  if (etat_bouton1 == LOW)
  {
    digitalWrite(11, LOW);
  }
  
  if (etat_bouton2 == HIGH)
  {
    digitalWrite(12, HIGH);
  }

  if (etat_bouton2 == LOW)
  {
    digitalWrite(12, LOW);
  }
  
}

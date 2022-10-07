
boolean etat_bouton1 = LOW ;
boolean etat_bouton2 = LOW ;
boolean etat_int1 = HIGH ;
boolean etat_int2 = HIGH ;

void setup () 
{

  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(9, INPUT);
  pinMode(10, INPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);

}


void loop () 
{

  etat_bouton1 = digitalRead (9) ;
  etat_bouton2 = digitalRead (10) ;
  etat_int1 = digitalRead (3) ;
  etat_int2 = digitalRead (4) ;

  if (etat_bouton1 == HIGH)
  {
    digitalWrite (11, HIGH) ;
    etat_int1 = digitalRead (3) ;
  }

  if (etat_int1 == LOW)
  {
    etat_int1 = digitalRead (3) ;
    digitalWrite (11, LOW) ;
  }
  
  if (etat_bouton2 == HIGH)
  {
    digitalWrite (12, HIGH) ;
    etat_int2 = digitalRead (4) ;
  }

  if (etat_int2 == LOW)
  {
    etat_int1 = digitalRead (4) ;
    digitalWrite (12, LOW) ;
  }
}

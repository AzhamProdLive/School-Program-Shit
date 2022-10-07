
boolean etat_bouton = LOW ;

void setup () 
{
  
  pinMode(10, INPUT);
  pinMode(11, OUTPUT);

}


void loop () 
{

  etat_bouton = digitalRead (10) ;

  if (etat_bouton == HIGH)
  {
    digitalWrite(11, HIGH);
    delay(2000);
    digitalWrite(11, LOW);
    delay(2000);
  }
  
}


boolean etat_bouton1 = LOW ; // Variable qui représente l'état du bouton d'ouverture
boolean etat_bouton2 = LOW ; // Variable qui représente l'état du bouton de fermeture
boolean etat_int1 = HIGH ; // Variable qui représente l'état de l'interrupteur d'arrêt d'ouverture
boolean etat_int2 = HIGH ; // Variable qui représente l'état de l'interrupteur d'arrêt de fermeture

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

  if (etat_bouton1 == HIGH) // Si le bouton d'ouverture est appuyé, ouvrir le portail (Moteur sens horaire)
  {
    digitalWrite (11, HIGH) ;
    etat_int1 = digitalRead (3) ;
  }

  if (etat_int1 == LOW) // Si l'interrupteur d'arrêt d'ouverture est appuyé, arrêter le moteur
  {
    etat_int1 = digitalRead (3) ;
    digitalWrite (11, LOW) ;
  }
  
  if (etat_bouton2 == HIGH) // Si le bouton de fermeture est appuyé, fermer le portail (Moteur sens trigonométrique)
  {
    digitalWrite (12, HIGH) ;
    etat_int2 = digitalRead (4) ;
  }

  if (etat_int2 == LOW) // Si l'interrupteur d'arrêt de fermeture est appuyé, arrêter le moteur
  {
    etat_int1 = digitalRead (4) ;
    digitalWrite (12, LOW) ;
  }
}

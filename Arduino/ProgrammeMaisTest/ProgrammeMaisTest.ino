int BPOFF;                //Création de la variable BPOFF
int BPON;                 //Création de la variable BPON
int STATE;                //Création de la variable STATE

void setup(){             //Initialisation des broches du programme
  pinMode(8,OUTPUT);      //Broche 8 (LED) = Sortie
  pinMode(11,OUTPUT);
  pinMode(3,INPUT);       //Broche 3 = Entrée
  pinMode(2,INPUT);
  digitalWrite(8,LOW);    //Eteindre LED 8
  digitalWrite(11,HIGH);  //Eteindre LED 11
  STATE = HIGH;
  
}
void loop() {              //Boucle du programme
BPON = digitalRead(2);     //Lecture de BPON sur la broche 2
BPOFF = digitalRead(3);    //Lecture de BPOFF sur la broche 3

  if (BPON==HIGH) {        //Variable "Si... Alors" avec le bouton BPON poussé
  digitalWrite(8,HIGH);    //Allumage de la LED
  digitalWrite(11,LOW);
  }
delay(10);                 //Délai d'attente avant la suite du programme
  if (BPOFF==LOW) {
  digitalWrite(8,LOW);     //Extinction de la LED
  }
STATE = digitalRead(3);    //Lecture de la broche 3 pour situer l'état (STATE) de BPOFF
delay(10);
BPOFF = digitalRead(3);    //Lecture de l'état de BPOFF
delay(10);
  if (BPOFF != STATE){     //Si BPOFF n'est pas égal a STATE, alors le programme continue, sinon, la boucle passe outre
  digitalWrite(11,HIGH);
  }
}

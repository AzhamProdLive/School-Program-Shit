  int bpon ;  // Mets en place une variable ayant pour valeur un nombre entier naturel
  int bpoff ;  // Mets en place une variable ayant pour valeur un nombre entier naturel
  boolean ETAT ; // Mets en place un variable ayant pour valeur un nombre entier naturel

void setup() {
  
  pinMode(8, OUTPUT); // Définit que la patte numéro 8 est une sortie 
  pinMode(11, OUTPUT); // Définit que la patte numéro 11 est une sortie
  pinMode(2, INPUT); // Définit que la patte numéro 2 est une entrée
  pinMode(3, INPUT); // Définit que la patte numéro 3 est une entrée
  digitalWrite (8, HIGH); // Mets le niveau logique de la patte 8 à 0
  digitalWrite (11, LOW); // Mets le niveau logique de la patte 11 à 1
  ETAT = 0 ;
}

void loop() {

  bpon = digitalRead (2); // Attribue à la variable bpon la valeur logique de la patte numéro 2
  bpoff = digitalRead (3); // Attribue à la variable bpoff la valeur logique de la patte numéro 3 
  
  if (bpoff == LOW and ETAT == 0) { // Si la valeur de la variable bpon est de 1
    digitalWrite(8, LOW); // Attribuer le niveau logique 1 à la patte 8
    delay(200);
    if (bpoff == HIGH) {
      ETAT = ETAT + 1 ;
      delay(100);
    }
  bpoff == digitalRead (3);
  if (bpoff == LOW and ETAT == 1) {
    digitalWrite(11, HIGH);
    delay(200);
    if (bpoff == HIGH)
      ETAT = ETAT - 1 ;
      delay(100);
  }
}
}
   

  
                

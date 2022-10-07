  int bpon ;  // Mets en place une variable ayant pour valeur un nombre entier naturel
  int bpoff ;  // Mets en place une variable ayant pour valeur un nombre entier naturel
  boolean etat_bpoff = HIGH;
  boolean etat_led_1 = LOW;

void setup() {
  
  pinMode(8, OUTPUT); // Définit que la patte numéro 8 est une sortie
  pinMode(11, OUTPUT); // Définit que la patte numéro 11 est une sortie
  pinMode(2, INPUT); // Définit que la patte numéro 2 est une entrée
  pinMode(3, INPUT); // Définit que la patte numéro 3 est une entrée
  digitalWrite (8, LOW); // Mets le niveau logique de la patte 8 à 0
  digitalWrite (11, HIGH); // Mets le niveau logique de la patte 11 à 1
  
}

void loop() {

  bpon = digitalRead (2); // Attribue à la variable bpon la valeur logique de la patte numéro 2
  bpoff = digitalRead (3); // Attribue à la variable bpoff la valeur logique de la patte numéro 3 
  
  if (bpon == HIGH) // Si la valeur de la variable bpon est de 1
  { 
  digitalWrite(8, HIGH); // Attribuer le niveau logique 1 à la patte 8
  digitalWrite(11, LOW); // Attribuer le niveau logique 0 à la patte 11
  etat_led_1 = HIGH;
  }
  
  delay(10); 
  
  if (bpoff == LOW)  
  {
  digitalWrite(8, LOW);
  delay (10); 
  etat_bpoff = LOW ;
  etat_led_1 = LOW ;
  }

  delay(10);
  
  while (bpoff == LOW && etat_bpoff == LOW)
  {
  digitalRead (3);
  }
  
  etat_bpoff = HIGH;
  delay(10);

  if (bpoff == LOW && etat_led_1 == LOW && etat_bpoff == HIGH)
  {
  digitalWrite(11, HIGH);
  delay(10);
  }

  delay(10);

  }

 

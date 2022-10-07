
int EtatBouton1 = 0;   //definition de la variable "EtatBouton1"
int EtatBouton2 = 0;

void setup() 
{
  pinMode(11, OUTPUT);     //led = sortie
  pinMode(8, OUTPUT);     //led = sortie
  pinMode(2, INPUT); //bouton1 = entrée d'info
  pinMode(3, INPUT); //bouton2 = entrée d'info
  digitalWrite(8, LOW);//  alors led = 0
  digitalWrite(11, HIGH);//  alors led = 0
}

void loop() 
{

EtatBouton1= digitalRead(2);  // lire la valeur du "bouton1" puis la placer dans "EtatBouton1"
EtatBouton2= digitalRead(3);  // lire la valeur du "bouton2" puis la placer dans "EtatBouton2"
delay(300);

  if( EtatBouton1 == HIGH) // si le bouton1 = 1
  {      
    digitalWrite(8, HIGH);   // alors led = allumée
    digitalWrite(11, LOW);   // alors led = allumée
  }
  
  if (EtatBouton2 == LOW) //  si le bouton2 = 0
  {    
    digitalWrite(8, LOW);//  alors led = 0
    digitalWrite(11, HIGH);//  alors led = 0
  }
  
}

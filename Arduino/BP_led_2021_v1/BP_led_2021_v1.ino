
int etat_bpon = 0;   
int etat_bpoff = 0;
int etat_led1=1;

void setup() 
{
  pinMode(11, OUTPUT);     //led = sortie
  pinMode(8, OUTPUT);     //led = sortie
  pinMode(2, INPUT); //bpon = entrée d'info
  pinMode(3, INPUT); //bpoff = entrée d'info
  
  digitalWrite(8, HIGH);   // alors led = allumée
  digitalWrite(11, LOW);   // alors led = allumée
}

void loop() 
{

etat_bpon= digitalRead(2);  // lire la valeur du "bouton1" puis la placer dans "EtatBouton1"
etat_bpoff= digitalRead(3);  // lire la valeur du "bouton2" puis la placer dans "EtatBouton2"

//si le bpon actif alors allumage des deux leds
  if (etat_bpon ==1)
  {      
   digitalWrite(8, HIGH);   
   digitalWrite(11, LOW);  
  } 
  
  if(( etat_bpoff == 0) && (etat_led1==1)) // si bpoff actif et led1 allumée
  {      
   digitalWrite(8, LOW);   // alors led = eteinte
   etat_led1 = 0;
   while (etat_bpoff == 0) // attendre relachement bpoff
   {
   etat_bpoff= digitalRead(3);
   }
  }
     
  if ((etat_bpoff == LOW)&& (etat_led1==0))//  si le bpoff actif et led1 eteinte
  {    
   digitalWrite(11, HIGH);//  alors led = 0 // alors extinction led2
   etat_led1=1;
   while (etat_bpoff == 0) // attendre relachement bpoff
   {
   etat_bpoff= digitalRead(3);
   }
  }
  
}

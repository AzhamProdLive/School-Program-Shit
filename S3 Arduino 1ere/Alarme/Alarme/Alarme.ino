const int Pin_contact=2;
const int Pin_feux=3;
const int Pin_porte=4;
const int Pin_alarme=5;

bool Contact;
bool Feux;
bool Porte;
bool Alarme;


void setup() {
  pinMode(Pin_contact, INPUT);
  pinMode(Pin_feux,INPUT);
  pinMode(Pin_porte,INPUT);
  pinMode(Pin_alarme,OUTPUT);
}

void loop() {
  Porte=digitalRead(Pin_porte);
  Feux=digitalRead(Pin_feux);
  Contact=digitalRead(Pin_contact);
  
  if (Porte==1&&Feux==1||Contact==0&&Feux==1)
  {
    Alarme=1;
  }else
  {
    Alarme=0;
  }
digitalWrite(Pin_alarme, Alarme);
}

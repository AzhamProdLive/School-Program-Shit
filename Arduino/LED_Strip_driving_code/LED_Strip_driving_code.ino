int RedPin = 10;      //Broche de pilotage Arduino pour la couleur rouge
int GreenPin = 11;    //Broche de pilotage Arduino pour la couleur verte
int BluePin = 9;      //Broche de pilotage Arduino pour la couleur bleue
void setColor(int red, int green, int blue)
{
  analogWrite(RedPin, red);
  analogWrite(GreenPin, green);
  analogWrite(BluePin, blue);

}

void setup()
{
  pinMode(RedPin, OUTPUT);    //Initier les broches de pilotage Arduino
  pinMode(GreenPin, OUTPUT);
  pinMode(BluePin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  for (int i=0;i<255;i++)  //Modification de la luminosité rouge
  {
    setColor(i, 0, 0);
    delay (10);
  }
  delay(2000);
  for (int i=0;i<255;i++)  //Modification de la luminosité verte
  {
    setColor(0, i, 0);
    delay (10);
  }
  delay(2000);
  for (int i=0;i<255;i++)  //Modification de la luminosité bleue
  {
    setColor(0, 0, i);
    delay (10);
  }
  delay(2000);
  for (int i=0;i<255;i++)
  {
    setColor(i, 0, 255-i);
    delay (10);
  }
  for (int i=0;i<255;i++)
  {
    setColor(255-i, i, 0);
    delay (10);
  }
  for (int i=0;i<255;i++)
  {
    setColor(0, 255-i, i);
    delay (10);
  }
}

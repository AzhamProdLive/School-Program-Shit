void setup()
{
  Serial.begin(9600);
  
  int i;

  for(i=8; i>=0; i=i-2)
  {
    Serial.print(i);
    Serial.print(' ');
  }

  Serial.println();
}
void loop()
{
  
}

  

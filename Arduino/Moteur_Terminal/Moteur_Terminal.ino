int Values;
int analogPin = 0;

void setup() {
  Serial.begin(19200);
}

void loop() {
  Values = analogRead(0);
  Serial.print(Values);
  delay(100);
}

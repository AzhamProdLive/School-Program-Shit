  int bpon ;
  int bpoff ;  

void setup() {
  
  pinMode(8, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  digitalWrite (8, LOW);
  digitalWrite (11, HIGH);

  
}

void loop() {

  bpon = digitalRead (2);
  bpoff = digitalRead (3); 
  
  if (bpon == HIGH) {
  digitalWrite(8, HIGH);
  digitalWrite(11, LOW);
  }
  
  delay(30);
  
  if (bpoff == LOW) {
  digitalWrite(8, LOW);
  while (bpoff == LOW); {
    if (bpoff == HIGH); 
      break;
    
  }
  }
  delay (100);
  if (bpoff == LOW
  

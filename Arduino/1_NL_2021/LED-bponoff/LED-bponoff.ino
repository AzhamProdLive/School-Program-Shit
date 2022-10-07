  int bpon ;
  int bpoff ;  
  int C ;

void setup() {
  
  pinMode(8, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  digitalWrite (8, LOW);
  digitalWrite (11, HIGH);
  C = 0 ;
  
}

void loop() {

  bpon = digitalRead (2);
  bpoff = digitalRead (3); 
  
  if (bpon == HIGH) {
  digitalWrite(8, HIGH);
  C = C + 1 ;
  delay (200);
  }
  bpon = digitalRead (2);
  if (bpon == HIGH and C >= 1) {
  digitalWrite(11, LOW);
  delay (50);
  
  }
  
  delay(30);
  
  if (bpoff == LOW) {
  digitalWrite(8, LOW);
  digitalWrite(11, HIGH); 
  }
  
  delay(30);                     
}

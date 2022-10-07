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

  digitalRead (2 == bpon);
  digitalRead (3 == bpoff);
  
  if (bpon == HIGH) {
  digitalWrite(8, HIGH);
  digitalWrite(11, LOW);
  }
            
}

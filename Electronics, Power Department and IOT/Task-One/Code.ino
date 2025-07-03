void setup() {
  pinMode(3, INPUT); 
  pinMode(4, INPUT); 
  pinMode(5, INPUT); 
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);   
}

void loop() {
  
  if (digitalRead(3) == HIGH) {
    digitalWrite(10, HIGH);  
  } else {
    digitalWrite(10, LOW);   
  }
  
  if (digitalRead(4) == HIGH) {
    digitalWrite(11, HIGH);  
  } else {
    digitalWrite(11, LOW);  
  }
  
  if (digitalRead(5) == HIGH) {
    digitalWrite(12, HIGH);  
  } else {
    digitalWrite(12, LOW);  
  }
}

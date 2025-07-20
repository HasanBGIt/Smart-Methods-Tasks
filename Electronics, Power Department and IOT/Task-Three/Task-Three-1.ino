const int setButton = 3;
const int resetButton = 4;
const int outputPin = 10;

bool state = false;

void setup() {
  pinMode(setButton, INPUT);
  pinMode(resetButton, INPUT);
  pinMode(outputPin, OUTPUT);
}

void loop() {
  if (digitalRead(setButton) == HIGH) {
    state = true;            
    delay(200);              
    while(digitalRead(setButton) == HIGH); 
  }

  if (digitalRead(resetButton) == HIGH) {
    state = false;           
    delay(200);              
    while(digitalRead(resetButton) == HIGH); 
  }

  digitalWrite(outputPin, state ? HIGH : LOW);
}

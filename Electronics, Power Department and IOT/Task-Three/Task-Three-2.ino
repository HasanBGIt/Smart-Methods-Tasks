const int pirPin = 2;
const int ledPin = 13;
const int potPin = A0;
const int ledPin1 = 10;

void setup() {
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int motion = digitalRead(pirPin);
  Serial.println(motion);
  digitalWrite(ledPin, motion);
  delay(100);
  int val = analogRead(potPin);
  Serial.println(val);
  int brightness = map(val, 0, 1023, 0, 255);
  analogWrite(ledPin1, brightness);
  delay(50);
}

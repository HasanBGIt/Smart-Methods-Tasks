int motor1_pin1 = 2;
int motor1_pin2 = 3;
int motor2_pin1 = 4;
int motor2_pin2 = 5;
int motor3_pin1 = 6;
int motor3_pin2 = 7;
int motor4_pin1 = 8;
int motor4_pin2 = 9;

void setup() {
  int pins[] = {2,3,4,5,6,7,8,9};
  for (int i=0; i<8; i++) pinMode(pins[i], OUTPUT);
}

void loop() {
  forward();
  delay(30000);

  backward();
  delay(60000);

  unsigned long start = millis();
  while (millis() - start < 60000) {
    turnLeft(); delay(500);
    turnRight(); delay(500);
  }

  stopMotors();
  while (1);
}

void forward() {
  digitalWrite(motor1_pin1, HIGH); digitalWrite(motor1_pin2, LOW);
  digitalWrite(motor2_pin1, HIGH); digitalWrite(motor2_pin2, LOW);
  digitalWrite(motor3_pin1, HIGH); digitalWrite(motor3_pin2, LOW);
  digitalWrite(motor4_pin1, HIGH); digitalWrite(motor4_pin2, LOW);
}

void backward() {
  digitalWrite(motor1_pin1, LOW); digitalWrite(motor1_pin2, HIGH);
  digitalWrite(motor2_pin1, LOW); digitalWrite(motor2_pin2, HIGH);
  digitalWrite(motor3_pin1, LOW); digitalWrite(motor3_pin2, HIGH);
  digitalWrite(motor4_pin1, LOW); digitalWrite(motor4_pin2, HIGH);
}

void turnLeft() {
  digitalWrite(motor1_pin1, LOW); digitalWrite(motor1_pin2, HIGH);
  digitalWrite(motor2_pin1, HIGH); digitalWrite(motor2_pin2, LOW);
  digitalWrite(motor3_pin1, LOW); digitalWrite(motor3_pin2, HIGH);
  digitalWrite(motor4_pin1, HIGH); digitalWrite(motor4_pin2, LOW);
}

void turnRight() {
  digitalWrite(motor1_pin1, HIGH); digitalWrite(motor1_pin2, LOW);
  digitalWrite(motor2_pin1, LOW); digitalWrite(motor2_pin2, HIGH);
  digitalWrite(motor3_pin1, HIGH); digitalWrite(motor3_pin2, LOW);
  digitalWrite(motor4_pin1, LOW); digitalWrite(motor4_pin2, HIGH);
}

void stopMotors() {
  for (int pin=2; pin<=9; pin++) digitalWrite(pin, LOW);
}

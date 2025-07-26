#include <Servo.h>

Servo myServo;

int motorA1 = 2;
int motorA2 = 3;
int motorB1 = 4;
int motorB2 = 5;
int trigPin = 10;
int echoPin = 11;
long duration;
int distance;

void setup() {
  Serial.begin(9600);
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  myServo.attach(9);
  moveForward();
}

void loop() {
  distance = getFilteredDistance();
  Serial.print("Distance: ");
  Serial.println(distance);

  if (distance > 0 && distance <= 100) {
    Serial.println("Obstacle detected!");
    stopMotors();
    sweepServo();
    moveBackward();
    delay(1000);
    moveForward();
  }
}

void moveForward() {
  digitalWrite(motorA1, HIGH); digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, HIGH); digitalWrite(motorB2, LOW);
}

void moveBackward() {
  digitalWrite(motorA1, LOW); digitalWrite(motorA2, HIGH);
  digitalWrite(motorB1, LOW); digitalWrite(motorB2, HIGH);
}

void stopMotors() {
  digitalWrite(motorA1, LOW); digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, LOW); digitalWrite(motorB2, LOW);
}


void sweepServo() {
  myServo.write(0); delay(300);
  myServo.write(90); delay(300);
  myServo.write(180); delay(300);

}

int getFilteredDistance() {
  long total = 0; int validCount = 0;
  for (int i = 0; i < 5; i++) {
    long d = singleRead();
    if (d > 0 && d < 400) { 
      total += d;
      validCount++;
    }
    delay(10);
  }
  if (validCount == 0) return -1; 
  return total / validCount; 
}

int singleRead() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH, 30000); 
  return duration * 0.034 / 2;
}

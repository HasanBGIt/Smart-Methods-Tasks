#include <Servo.h>

Servo servo_6;
Servo servo_5;
Servo servo_4;
Servo servo_3;

void setup() {
  servo_6.attach(6, 500, 2500);
  servo_5.attach(5, 500, 2500);
  servo_4.attach(4, 500, 2500);
  servo_3.attach(3, 500, 2500);
}

void loop() {
  for (int pos = 0; pos <= 90; pos++) {
    servo_6.write(pos);
    delay(10);
  }

  for (int pos = 0; pos <= 90; pos++) {
    servo_5.write(pos);
    delay(10);
  }

  for (int pos = 0; pos <= 90; pos++) {
    servo_4.write(pos);
    delay(10);
  }

  for (int pos = 0; pos <= 90; pos++) {
    servo_3.write(pos);
    delay(10);
  }

  delay(1);  

 
  for (int pos = 90; pos >= 0; pos--) {
    servo_3.write(pos);
    delay(10);
  }

  for (int pos = 90; pos >= 0; pos--) {
    servo_4.write(pos);
    delay(10);
  }

  for (int pos = 90; pos >= 0; pos--) {
    servo_5.write(pos);
    delay(10);
  }

  for (int pos = 90; pos >= 0; pos--) {
    servo_6.write(pos);
    delay(10);
  }

  delay(1); 
}

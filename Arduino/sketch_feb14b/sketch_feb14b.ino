#include <Servo.h>

Servo myservo;
#define n 3
void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
    myservo.attach(9);
    myservo.write(0);
    Serial.println(0);
    delay(500);
    myservo.write(60);
    Serial.println(60);
    delay(500);
    myservo.write(120);
    Serial.println(120);
    delay(500);
    myservo.write(180);
    Serial.println(180);
    delay(500);
}

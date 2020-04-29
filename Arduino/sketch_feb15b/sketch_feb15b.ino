#include <Servo.h>

Servo myservo;
#define n 3
int analogPin=0;
int val=0;
int deg=0;
void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
    pinMode(7, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
    myservo.attach(9);
    val = analogRead(analogPin);
    // 得たアナログ値を1/4して、0〜1023の値を0〜255に変換
    deg=val/4;
    Serial.println(deg);
    myservo.write(deg);
    digitalWrite(7,LOW);
    digitalWrite(7,HIGH);
    delay(100);
}

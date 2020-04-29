//echoPin=2
//trigPin=3
#include<Servo.h>
Servo myservo;
int deg=0;
int i=0;
double Duration=0;
double Distance=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(2,INPUT);
  pinMode(3,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  myservo.attach(7);
  myservo.write(deg);
  digitalWrite(3,LOW);
  delayMicroseconds(2);
  digitalWrite(3,HIGH);
  delayMicroseconds(10);
  digitalWrite(3,LOW);
  Duration = pulseIn( 2, HIGH ); //センサからの入力
  if (Duration > 0) {
    Duration = Duration/2; //往復距離を半分にする
    Distance = Duration*340*100/1000000; // 音速を340m/sに設定
    Serial.print("i");
    Serial.print(i);
    Serial.print(" deg:");
    Serial.print(deg);
    Serial.print(" Distance:");
    Serial.print(Distance);
    Serial.println(" cm");
    
  }
  i=i+1;
  if (i==10){
    deg=deg+10;
    i=0;
  }
  if (deg>180){
    deg=0;
  }
  if (deg==0){
    delay(500);
  }
  delay(100);
}

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
int start1=0;
int stop1=0;
void loop() {
  // put your main code here, to run repeatedly:
  int inputchar;
  inputchar=Serial.read();
  if (inputchar!=-1){
    switch(inputchar){
      case 's':
        start1=1;
        Serial.println("start");
        break;
    }
  }
  if (start1==1){
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
      Serial.print(deg);
      Serial.print(" ");
      Serial.println(Distance);
      
    }
    i=i+1;
    if (i==10){
      deg=deg+10;
      i=0;
    }
    if (stop1==1){
      start1=0;
      stop1=0;
      Serial.println("stop");
    }
    if (deg>180){
      deg=0;
      stop1=1;
    }
    delay(100);
  }
}

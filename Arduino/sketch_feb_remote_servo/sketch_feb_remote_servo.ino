#include<IRremote.h>
#include <Servo.h>
Servo myservo1;
Servo myservo2;
Servo myservo3;
int RECV_PIN=11;
int deg1=0;
int deg2=0;
int deg3=0;
IRrecv irrecv(RECV_PIN);
decode_results results;
void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
    irrecv.enableIRIn();
}
int num;
String side;
void loop() {
  // put your main code here, to run repeatedly:
    String key;
    myservo1.attach(7);
    myservo2.attach(8);
    myservo3.attach(9);
    if (irrecv.decode(&results)){
        //Serial.println(results.value,HEX);
        //Serial.println(results.value);
        key=results.value;
        //Serial.println(key);
        if(deg1<0){
            deg1=0;
        }
        if(deg2<0){
            deg2=0;
        }
        if(deg3<0){
            deg3=0;
        }
        if(deg1>180){
            deg1=180;
        }
        if(deg2>180){
            deg2=180;
        }
        if(deg3>180){
            deg3=180;
        }
        if(key=="4294967295"){
            if(num==1){
                //Serial.println(1);
            }
            if(num==2){
                //Serial.println(2);
            }
            if(num==3){
                //Serial.println(3);
            }
            //Serial.println(side);
            if(side=="r"){
                Serial.println("R");
                if(num==1){
                    Serial.println(1);
                    deg1+=5;
                    myservo1.write(deg1);
                }
                if(num==2){
                    Serial.println(2);
                    deg2+=5;
                    myservo2.write(deg2);
                }
                if(num==3){
                    Serial.println(3);
                    deg3+=5;
                    myservo3.write(deg3);
                }
            }
            if(side=="l"){
                Serial.println("L");
                if(num==1){
                    Serial.println(1);
                    deg1-=5;
                    myservo1.write(deg1);
                }
                if(num==2){
                    Serial.println(2);
                    deg2-=5;
                    myservo2.write(deg2);
                }
                if(num==3){
                    Serial.println(3);
                    deg3-=5;
                    myservo3.write(deg3);
                }
            }
        }
        if(key=="16738455"){
            Serial.println(1);
            num=1;
        }
        if(key=="16750695"){
            Serial.println(2);
            num=2;
        }
        if(key=="16756815"){
            Serial.println(3);
            num=3;
        }
        if(key=="16761405"){
            Serial.println("R");
            side="r";
        }
        if(key=="16720605"){
            Serial.println("L");
            side="l";
        }
        irrecv.resume();
    }
}

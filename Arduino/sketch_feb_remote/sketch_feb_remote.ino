#include<IRremote.h>
int RECV_PIN=11;
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
    if (irrecv.decode(&results)){
        //Serial.println(results.value,HEX);
        //Serial.println(results.value);
        key=results.value;
        //Serial.println(key);
        if(key=="4294967295"){
            if(num==1){
                Serial.println(1);
            }
            if(num==2){
                Serial.println(2);
            }
            if(num==3){
                Serial.println(3);
            }
            //Serial.println(side);
            if(side=="r"){
                Serial.println("R");
            }
            if(side=="l"){
                Serial.println("L");
            }
            if(side=="u"){
                Serial.println("U");
            }
            if(side=="d"){
                Serial.println("D");
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
        if(key=="16736925"){
            Serial.println("U");
            side="u";
        }
        if(key=="16754775"){
            Serial.println("D");
            side="d";
        }
        irrecv.resume();
    }
    
}

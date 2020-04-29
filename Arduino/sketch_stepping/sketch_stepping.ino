#include <Stepper.h>
const int stepsPerRotate = 200;//ステップ数 = 200 / ステップ角 = 200 / 1.8 = 111
Stepper myStepper(stepsPerRotate, 8, 9, 10, 11);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myStepper.setSpeed(50);
}
int st;
void loop() {
  // put your main code here, to run repeatedly:
  
  for(st=0;st<20;st++){
    myStepper.step(10);
    Serial.print("ステップ: ");
    Serial.println(st+1);
  }
  delay(500);
  for(st=0;st<20;st++){
    myStepper.step(-10);
    Serial.print("ステップ: ");
    Serial.println(-st-1);
  }
  delay(500);
  //myStepper.setSpeed(50);
  //myStepper.step(-100);
  //delay(500);
}

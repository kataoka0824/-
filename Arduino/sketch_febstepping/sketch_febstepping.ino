#include <Stepper.h>
const int stepsPerRotate = 48;//ステップ数 = 360 / ステップ角 = 360 / 7.5 = 48
Stepper myStepper(stepsPerRotate, 8, 9, 10, 11);
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
    myStepper.setSpeed(15);
    myStepper.step(48);
    delay(500);
    myStepper.step(-48);
    myStepper.setSpeed(30);
    myStepper.step(48);
    delay(500);
    myStepper.setSpeed(50);
    myStepper.step(-48);
    delay(500);
    myStepper.setSpeed(80);
    myStepper.step(96);
    delay(500);
}

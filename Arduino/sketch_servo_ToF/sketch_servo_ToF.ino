#include <Wire.h>
#include <VL53L1X.h>
#include <Servo.h>
VL53L1X sensor;
Servo myservo;
int deg=0;

void setup()
{
  Serial.begin(115200);
  Wire.begin();
  Wire.setClock(400000); // use 400 kHz I2C

  sensor.setTimeout(500);
  if (!sensor.init())
  {
    Serial.println("Failed to detect and initialize sensor!");
    while (1);
  }
  
  // Use long distance mode and allow up to 50000 us (50 ms) for a measurement.
  // You can change these settings to adjust the performance of the sensor, but
  // the minimum timing budget is 20 ms for short distance mode and 33 ms for
  // medium and long distance modes. See the VL53L1X datasheet for more
  // information on range and timing limits.
  sensor.setDistanceMode(VL53L1X::Long);
  sensor.setMeasurementTimingBudget(50000);

  // Start continuous readings at a rate of one measurement every 50 ms (the
  // inter-measurement period). This period should be at least as long as the
  // timing budget.
  sensor.startContinuous(50);
}
int start1=0;
int stop1=0;
void loop()
{
  int inputchar;
  inputchar=Serial.read();
  if (inputchar!=-1){
    switch(inputchar){
      case 's':
        start1=1;
        //Serial.println("start");
        break;
    }
  }
  //Serial.print(sensor.read());
  if (sensor.timeoutOccurred()) { Serial.print(" TIMEOUT"); }
  if  (start1==1){
    myservo.attach(9);
    myservo.write(deg);
    //Serial.print("deg:");
    Serial.print(deg);
    //Serial.print(" dist:");
    Serial.print(" ");
    Serial.println(sensor.read());
    deg=deg+1;
  }
  //Serial.println();  
  if (deg>180){
    deg=0;
    stop1=1;
  }
  if (stop1==1){
    start1=0;
    stop1=0;
    Serial.println("stop");
    myservo.write(0);
  }

}

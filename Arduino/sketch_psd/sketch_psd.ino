const int analogInPin=A0;
const float Vcc=5.0;
int AD;
float dist;
String AD_s;
String dist_s;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  AD=analogRead(analogInPin);
  dist=Vcc*AD/1023;
  dist=26.549*pow(dist,-1.2091);
  Serial.print("AD=");
  AD_s=String(AD);
  Serial.print(AD_s);
  Serial.print(" , ");
  Serial.print("Dist=");
  dist_s=String(dist);
  Serial.print(dist_s);
  Serial.println(" cm");
  delay(1000);
}

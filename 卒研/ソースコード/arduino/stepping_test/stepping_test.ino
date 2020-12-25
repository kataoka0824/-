int PUL=7; //define Pulse pin
int DIR=6; //define Direction pin
int ENA=5; //define Enable Pin
int PUL2=10;
int DIR2=9;
int ENA2=8;
void setup() {
  pinMode (PUL, OUTPUT);
  pinMode (DIR, OUTPUT);
  pinMode (ENA, OUTPUT);
  pinMode (PUL2, OUTPUT);
  pinMode (DIR2, OUTPUT);
  pinMode (ENA2, OUTPUT);
}

void loop() {
  for (int i=0; i<6400; i++)    //Forward 5000 steps
  {
    digitalWrite(DIR,LOW);
    digitalWrite(DIR2,HIGH);
    digitalWrite(ENA,HIGH);
    digitalWrite(ENA2,HIGH);
    digitalWrite(PUL,HIGH);
    digitalWrite(PUL2,HIGH);
    delayMicroseconds(500);
    digitalWrite(PUL,LOW);
    digitalWrite(PUL2,LOW);
    delayMicroseconds(500);
  }
  for (int i=0; i<6400; i++)   //Backward 5000 steps
  {
    digitalWrite(DIR,HIGH);
    digitalWrite(DIR2,LOW);
    digitalWrite(ENA,HIGH);
    digitalWrite(ENA2,HIGH);
    digitalWrite(PUL,HIGH);
    digitalWrite(PUL2,HIGH);
    delayMicroseconds(500);
    digitalWrite(PUL,LOW);
    digitalWrite(PUL2,LOW);
    delayMicroseconds(500);
  }
}

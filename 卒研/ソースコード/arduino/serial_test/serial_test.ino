char val;
int PUL=7; //define Pulse pin
int DIR=6; //define Direction pin
int ENA=5; //define Enable Pin
int PUL2=10;
int DIR2=9;
int ENA2=8;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  val='n';
  pinMode (PUL, OUTPUT);
  pinMode (DIR, OUTPUT);
  pinMode (ENA, OUTPUT);
  pinMode (PUL2, OUTPUT);
  pinMode (DIR2, OUTPUT);
  pinMode (ENA2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0){
    val=Serial.read();
    if(val == 'u'){
      Serial.println("u");
    }
    if(val == 'd'){
      Serial.println("d");
    }
    if(val == 'r'){
      Serial.println("r");
    }
    if(val == 'l'){
      Serial.println("l");
    }
  }
  if(val == 'u'){
      Serial.println("u");
      digitalWrite(DIR,LOW);
      digitalWrite(DIR2,HIGH);
      digitalWrite(ENA,HIGH);
      digitalWrite(ENA2,HIGH);
      digitalWrite(PUL,HIGH);
      digitalWrite(PUL2,HIGH);
      delayMicroseconds(100);
      digitalWrite(PUL,LOW);
      digitalWrite(PUL2,LOW);
      delayMicroseconds(100);
    }
  if(val == 'd'){
      Serial.println("d");
      digitalWrite(DIR,HIGH);
      digitalWrite(DIR2,LOW);
      digitalWrite(ENA,HIGH);
      digitalWrite(ENA2,HIGH);
      digitalWrite(PUL,HIGH);
      digitalWrite(PUL2,HIGH);
      delayMicroseconds(100);
      digitalWrite(PUL,LOW);
      digitalWrite(PUL2,LOW);
      delayMicroseconds(100);
    }
    if(val == 'r'){
      Serial.println("r");
      digitalWrite(DIR,HIGH);
      digitalWrite(DIR2,HIGH);
      digitalWrite(ENA,HIGH);
      digitalWrite(ENA2,HIGH);
      digitalWrite(PUL,HIGH);
      digitalWrite(PUL2,HIGH);
      delayMicroseconds(100);
      digitalWrite(PUL,LOW);
      digitalWrite(PUL2,LOW);
      delayMicroseconds(100);
    }
    if(val == 'l'){
      Serial.println("l");
      digitalWrite(DIR,LOW);
      digitalWrite(DIR2,LOW);
      digitalWrite(ENA,HIGH);
      digitalWrite(ENA2,HIGH);
      digitalWrite(PUL,HIGH);
      digitalWrite(PUL2,HIGH);
      delayMicroseconds(100);
      digitalWrite(PUL,LOW);
      digitalWrite(PUL2,LOW);
      delayMicroseconds(100);
    }
  Serial.println(val);
}

#include <SoftwareSerial.h>
SoftwareSerial BT(3,2); //TX, RX respectively
char x='0';
const int pingPin = 7;
 
void setup() {
  BT.begin(9600);

  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT);

  pinMode(5,OUTPUT);
  pinMode(4,OUTPUT);

  digitalWrite(5,LOW);
  digitalWrite(4,LOW);

  Serial.begin(9600);
}

void loop() {

long duration, cm;
  
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);

  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);


if (cm<100) {
    digitalWrite(5,LOW);
    digitalWrite(4,HIGH);
    analogWrite(10,255);
    analogWrite(9,255);
    delay(400);
    digitalWrite(5,LOW);
    digitalWrite(4,LOW);
    analogWrite(10,0);
    analogWrite(9,0);
    delay(7000);
    digitalWrite(5,HIGH);
    digitalWrite(4,LOW);
    analogWrite(10,255);
    analogWrite(9,255);
    delay(400);
    digitalWrite(5,LOW);
    digitalWrite(4,LOW);
    analogWrite(10,0);
    analogWrite(9,0);
  }

  while(BT.available())
  {
    x=BT.read();
    if(x=='1') //move up
    {
      digitalWrite(5,LOW);
      digitalWrite(4,HIGH);
      analogWrite(10,255);
      analogWrite(9,255);
    }

        if(x=='2') //move down
    {
      digitalWrite(5,HIGH);
      digitalWrite(4,LOW);
      analogWrite(10,255);
      analogWrite(9,255);
    }
    
        if(x=='0') //stop
    {
      digitalWrite(5,LOW);
      digitalWrite(4,LOW);
      analogWrite(10,0);
      analogWrite(9,0);
    }
  }
}

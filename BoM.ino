int analogPin = A3; // potentiometer wiper (middle terminal) connected to analog pin 3
int analogPin2 = A1;                   // outside leads to ground and +5V
int val;
int val2;

#define echoPin 7
#define trigPin 6
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement

#include <SoftwareSerial.h>
SoftwareSerial BT(3,2); //TX, RX respectively
char x='0';

void setup() {
  BT.begin(9600);
  Serial.begin(9600);           //  setup serial
  pinMode(9,OUTPUT); // PWM of motor
  pinMode(5,OUTPUT); // First motor connection
  pinMode(4,OUTPUT); // Secon motor connection

  digitalWrite(5,LOW);
  digitalWrite(4,LOW);

  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
}

void loop() {
val = analogRead(analogPin);
val2 = analogRead(analogPin2);

//------------------Ultrasonic Sensor------------------
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

if(distance > 20){

  }
    while (val==0){
    digitalWrite(5,LOW);
    digitalWrite(4,HIGH);
    analogWrite(9,127);
    delay(10);
   }

   while (val2==0){
    digitalWrite(5,HIGH);
    digitalWrite(4,LOW);
    analogWrite(9,225);
    delay(10);
   }

     if(BT.available())
  {
    x=BT.read();
    if(x=='1') //move up
    {
      digitalWrite(5,LOW);
      digitalWrite(4,HIGH);
      analogWrite(9,127);
    }
        if(x=='2') //move down
    {
      digitalWrite(5,HIGH);
      digitalWrite(4,LOW);
      analogWrite(9,127);
    }
     if(x=='0') //stop
    {
      digitalWrite(5,LOW);
      digitalWrite(4,LOW);
      analogWrite(9,0);
    }
    delay(10);
}  

else if(distance <= 20){


  while (val==0){
    digitalWrite(5,LOW);
    digitalWrite(4,HIGH);
    analogWrite(9,225);
    delay(10);
   }


    if(BT.available())
  {
    x=BT.read();
    if(x=='1') //move up
    {
      digitalWrite(5,LOW);
      digitalWrite(4,HIGH);
      analogWrite(9,127);
    }

    if(x=='0') //stop
    {
      digitalWrite(5,LOW);
      digitalWrite(4,LOW);
      analogWrite(9,0);
    }
     delay(10);
  }

 }
}

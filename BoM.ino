#include <SoftwareSerial.h>
#define echoPin 6
#define trigPin 7

SoftwareSerial BT(3,2); //TX, RX respectively
char x='0';

long duration;
int distance;

int button1 = 12;     // the pin of the first touch sensor
int button2 =  13;      // the pin of the second touch sensor
int buttonState1 = 0;
int buttonState2 = 0;


void setup() {
  BT.begin(9600);
  pinMode(9,OUTPUT); // PWM of motor
  pinMode(5,OUTPUT); // First motor connection
  pinMode(4,OUTPUT); // Secon motor connection

  digitalWrite(5,LOW);
  digitalWrite(4,LOW);

  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  Serial.begin(9600);
  
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);

}

void loop() {
  
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
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");


if (distance<7) {
    digitalWrite(5,LOW);
    digitalWrite(4,HIGH);
    analogWrite(9,255);
    delay(4000);
    digitalWrite(5,LOW);
    digitalWrite(4,LOW);
    analogWrite(9,0);
    delay(7000);
    digitalWrite(5,HIGH);
    digitalWrite(4,LOW);
    analogWrite(9,255);
    delay(4000);
    digitalWrite(5,LOW);
    digitalWrite(4,LOW);
    analogWrite(9,0);
  }



  //------------------NXT Touch Sensor------------------
  buttonState1 = digitalRead(button1);
  buttonState2 = digitalRead(button2);

  if (buttonState1 == HIGH){
    digitalWrite(5,LOW);
    digitalWrite(4,LOW);
    analogWrite(9,0);
    delay(7000);
    digitalWrite(5,HIGH);
    digitalWrite(4,LOW);
    analogWrite(9,255);
  }

  if (buttonState2 == HIGH){
    digitalWrite(5,LOW);
    digitalWrite(4,LOW);
    analogWrite(9,0);
    delay(7000);
    digitalWrite(5,LOW);
    digitalWrite(4,HIGH);
    analogWrite(9,255);
  }

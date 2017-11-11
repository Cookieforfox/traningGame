/*
 HC-SR04 Ping distance sensor]
 VCC to arduino 5v GND to arduino GND
 Echo to Arduino pin 13 Trig to Arduino pin 12
 Red POS to Arduino pin 11
 
 */
#include <Servo.h>

#define trigPin 4 // blau
#define echoPin 5 // violet
#define ServPin 3  // orange
#define led A5

Servo Servo1;

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(led,OUTPUT);
  pinMode(echoPin, INPUT);
  Servo1.attach(ServPin); 
}

void loop() {
  long distance;
  digitalWrite(led,LOW);
  distance = MesseEntfernung();
  if (distance >= 200 || distance <= 0){
    Serial.println("Out of range");
  }
  else {
    Serial.print(distance);
    Serial.println(" mm");
  }
  delay(500);
  digitalWrite(led,HIGH);
  delay(500);
}

long MesseEntfernung()
{ // Messe Entfernung in mm
  long duration;
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  return (duration/2)* 10 / 29.1;

}

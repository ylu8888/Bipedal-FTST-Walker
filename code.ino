#include <Servo.h>

const int motorOne_InputTwo = 4;
const int motorOne_InputOne = 5;
const int motorOne_Enable = 9;
const int motorTwo_Enable = 10;
const int motorTwo_InputOne = 6;
const int motorTwo_InputTwo = 7;
const int trig = 8;
const int echo = 12;
const int buzzer = 2;
const int laserPin = 13;
int switchPin = 3;
int switchState = 0;
int duration;
int distance;
Servo myServo;
 
void setup()
{
 Serial.begin(9600);
 myServo.attach(11);

 pinMode(laserPin, OUTPUT);
 pinMode(4, OUTPUT);
 pinMode(buzzer, OUTPUT);
 pinMode(5, OUTPUT);
 pinMode(9, OUTPUT);
 pinMode(10, OUTPUT);
 pinMode(6, OUTPUT);
 pinMode(7, OUTPUT);
 pinMode(trig, OUTPUT);
 pinMode(echo, INPUT);
 pinMode(switchPin, INPUT);
digitalWrite(motorOne_Enable, HIGH);
digitalWrite(motorTwo_Enable, HIGH);
digitalWrite(laserPin, LOW);
for(int degree = 179; degree >= 0; degree--)
  {
    myServo.write(degree);
    delay(5);

  }
}
 
void loop()
{
 pinMode(trig, OUTPUT);
 digitalWrite(trig, LOW);
 delayMicroseconds(2);
 digitalWrite(trig, HIGH);
 delayMicroseconds(5);
 digitalWrite(trig, LOW);

 pinMode(echo, INPUT);
 duration = pulseIn(echo, HIGH);
switchState = digitalRead(switchPin);

 distance = duration*0.034/2;
if (switchState == HIGH)
{
digitalWrite(motorOne_InputOne, HIGH);
digitalWrite(motorOne_InputTwo, LOW);
digitalWrite(motorTwo_InputOne, HIGH);
digitalWrite(motorTwo_InputTwo, LOW);
}

if (distance <= 10)
{
  digitalWrite(motorOne_InputOne, LOW);
  digitalWrite(motorOne_InputTwo, LOW);
  digitalWrite(motorTwo_InputOne, LOW);
  digitalWrite(motorTwo_InputTwo, LOW);

 for(int degree = 0; degree <= 179; degree++)
  {
    myServo.write(degree);
    delay(5);
  }

  //Turn on laser and buzzer makes sound
  tone(buzzer, 200);
  digitalWrite(laserPin, HIGH);
  delay(500);
  noTone(buzzer);
  digitalWrite(laserPin, LOW);
  delay(500);
  tone(buzzer, 400);
  digitalWrite(laserPin, HIGH);
  delay(500);
  noTone(buzzer);
  digitalWrite(laserPin, LOW);
  delay(500);
  tone(buzzer, 600);
  digitalWrite(laserPin, HIGH);
  delay(500);
  noTone(buzzer);
  digitalWrite(laserPin, LOW);
  delay(500);

 for(int degree = 179; degree >= 0; degree--)
  {
    myServo.write(degree);
    delay(5);
  }
digitalWrite(motorOne_InputOne, HIGH);
digitalWrite(motorOne_InputTwo, LOW);
digitalWrite(motorTwo_InputOne, HIGH);
digitalWrite(motorTwo_InputTwo, LOW);


}
}

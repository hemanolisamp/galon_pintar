#include <Servo.h>
#define sensor A0
#define led 13
Servo servoku ;
int trig = 8;
int echo = 9;
long duration, cm, meter;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servoku.attach(6);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //servoku.write(0);
 digitalWrite(trig, LOW);
 delayMicroseconds(5);
 digitalWrite(trig, HIGH);
 delayMicroseconds(10);
 digitalWrite(trig, LOW);
 pinMode(echo, INPUT);
 duration = pulseIn(echo, HIGH);
 cm = (duration/2)/29.1;
if(digitalRead(sensor) == LOW){
  while(digitalRead(sensor) == LOW)
  {
  }
  digitalWrite(led,!digitalRead(led));
}
Serial.println(digitalRead(sensor));
delay(100);


//if( cm >=2 && cm <= 10){
//servoku.write(0);
//Serial.println(sensor);
//}
//
//if (cm >=11){
//  servoku.write(90);
//}
}

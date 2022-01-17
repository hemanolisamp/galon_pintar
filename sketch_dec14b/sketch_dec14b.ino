#include <SoftwareSerial.h>
#define sensor A0
#define led 13
int pompa = 2;

void setup() {
Serial.begin(9600);
pinMode(sensor, INPUT_PULLUP);
pinMode(led, OUTPUT);
}

void loop() {
if(digitalRead(sensor) == LOW){
  while(digitalRead(sensor) == LOW)
  {
  }
  digitalWrite(pompa,!digitalRead(pompa));
}
Serial.println(digitalRead(sensor));
delay(100);
}

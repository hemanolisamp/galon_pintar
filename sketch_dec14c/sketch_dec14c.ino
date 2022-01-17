#include <Servo.h>
#define sensor A0
#define led 13
#include <LiquidCrystal_I2C.h> 
Servo servoku ;  
int trig = 8;
int echo = 9;
int pompa = 2;
long duration, cm, meter;
LiquidCrystal_I2C lcd(0x3F,16,2); 
void setup() {
Serial.begin(9600);
pinMode(trig, OUTPUT);
pinMode(echo, INPUT);
pinMode(sensor, INPUT_PULLUP);
pinMode(pompa, OUTPUT);
lcd.begin(); //LCD 16x2  
lcd.setBacklight(HIGH);
}

void loop() {
 digitalWrite(trig, LOW);
 delayMicroseconds(5);
 digitalWrite(trig, HIGH);
 delayMicroseconds(10);
 digitalWrite(trig, LOW);
 pinMode(echo, INPUT);
 duration = pulseIn(echo, HIGH);
 cm = (duration/2)/29.1;
 if( cm >=2 && cm <= 10){
  lcd.clear();   
  lcd.home(); // set cursor to 0,0 
  lcd.print("yeehhh Minum Air");
  lcd.setCursor(0,3); 
  delay(1000); 
 }
 else{
  lcd.clear();   
  lcd.home(); // set cursor to 0,0 
  lcd.print("Ayo Minum Air :(");
  lcd.setCursor(0,1); 
  delay(1000); 
 }
 
 if( cm >=2 && cm <= 10)
 {
    if(digitalRead(sensor) == HIGH)
    {
          while(digitalRead(sensor) == HIGH)
          {
             digitalWrite(pompa, HIGH);
            }
     }
     else 
     {
       digitalWrite(pompa, LOW);
     }  
 }
else
{
   digitalWrite(pompa, LOW);
}
   Serial.println(cm);
}

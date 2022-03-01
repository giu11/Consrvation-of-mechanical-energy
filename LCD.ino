#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
#define trigPin 6
#define echo1Pin 7
#define echo2Pin 13
long durata, cm, cm2;
void setup()
{
lcd.begin(16, 2);
lcd.clear();
 
Serial.begin(9600);
 
pinMode(8, INPUT);
digitalWrite(8, HIGH);
pinMode(9, INPUT);
digitalWrite(9, HIGH);
pinMode(trigPin, OUTPUT);
pinMode(echo1Pin, INPUT);
pinMode(echo2Pin, OUTPUT);

}
double i = 0;
double a = millis();
double c ;
 
void loop()
{
  trig();
  durata = pulseIn(echo1Pin, HIGH);
  cm = durata / 58;
  delayMicroseconds(50);
  trig();
  durata = pulseIn(echo2Pin, HIGH);
  cm2 = durata / 58;
  delayMicroseconds(50); 
lcd.print("Posiziona l'oggetto");
delay(100);
 
if(digitalRead(8) == LOW)
{
 
lcd.clear();
a = millis();
while(digitalRead(9) == HIGH && cm > 8 && cm < 15)
{
 
c = millis();
i = (c - a) / 1000;
lcd.print(i);
lcd.setCursor(7,0);
lcd.print("Sec's");
lcd.setCursor(0,0);
Serial.println(c);
Serial.println(a);
Serial.println(i);
Serial.println("......");
delay(100);
}
 
if(digitalRead(9) == LOW)
{
while(digitalRead(8) == HIGH && cm2 > 3 && cm2 < 6)
{
lcd.setCursor(0,0);
lcd.print(i);
lcd.setCursor(11,0);
lcd.print("");
lcd.setCursor(0,0);
delay(100);
}
}
}
}
void trig () {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
}

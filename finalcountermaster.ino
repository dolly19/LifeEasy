#include<LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,10,9,8);
#define in 14
#define out 19
#define relay 2
int val;
//#define button 3
int count=0;
void IN()
{
count++;
lcd.clear();
lcd.print('People:');
lcd.setCursor(0,1);
lcd.print(count);
delay(1000);
}
void OUT()
{
count--;
lcd.clear();
lcd.print('People:');
lcd.setCursor(0,1);
lcd.print(count);
delay(1000);
}
void setup()
{
lcd.begin(16,2);
//lcd.print('Visitor Counter');
delay(2000);
pinMode(in, INPUT);
pinMode(out, INPUT);
pinMode(relay, OUTPUT);
lcd.clear();
lcd.print('People:');
lcd.setCursor(0,1);
lcd.print(count);
Serial.begin(38400);
}
void loop()
{
if(digitalRead(in))
IN();
if(digitalRead(out))
OUT();
if(count<=0)
{
lcd.clear();
digitalWrite(relay, LOW);
lcd.clear();
//lcd.print('Nobody In Room');
lcd.setCursor(0,1);
//lcd.print('Light Is Off');
delay(200);
}    
else
digitalWrite(relay, HIGH);
Serial.println(count);
delay(500);
Serial.write(count); // Sends potValue to servo motor
delay(10);
//val = digitalRead(button);
//if (val == HIGH)
//{
//Serial.write(count);
//delay(500);
//}
//delay(50);
}

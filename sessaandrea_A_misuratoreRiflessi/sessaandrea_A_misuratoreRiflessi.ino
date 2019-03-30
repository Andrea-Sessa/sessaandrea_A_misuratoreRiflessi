#include <LiquidCrystal.h>

int led = 13;
int button = 4;
int buzzer = 8;
int tempo = 1000;
int tempo1 = 0;
int tempo2 = 0;
const int a = 2, b = 6, c = 3, d = 5, e = 9, f = 10;
LiquidCrystal lcd(a, b, c, d, e, f);

void setup() {
  // put your setup code here, to run once
  pinMode(led, OUTPUT);
  pinMode(button, OUTPUT);
  pinMode(buzzer, OUTPUT);
  lcd.begin(16,2);
}
void lampeggio()
{
  bool vero = true;
  delay(tempo);
  digitalWrite(led, HIGH);
  tempo1 = millis();
  while (digitalRead(button) == LOW);
  digitalWrite(led, LOW);
  while (digitalRead(button) == HIGH);
  {
    if (vero)
    {
      tempo2 = millis() - tempo1;
      vero = false;
    }
  }
  lcd.setCursor(0,0);
  lcd.print(tempo2);
}
void suono()
{
 bool vero = true;
 delay(tempo);
 tone(buzzer, 1000, 5000);
 tempo1 = millis();
 while (digitalRead(button) == LOW);
 noTone(buzzer);
 while (digitalRead(button) == HIGH);
 {
  if (vero)
    {
      tempo2 = millis() - tempo1;
      vero = false;
    }
 }
  lcd.setCursor(0,1);
  lcd.print(tempo2);}
 
}


void loop() {
  // put your main code here, to run repeatedly:
  lampeggio();
  suono();
  

}

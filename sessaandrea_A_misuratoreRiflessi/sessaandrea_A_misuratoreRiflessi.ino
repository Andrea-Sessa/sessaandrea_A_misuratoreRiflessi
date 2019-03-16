#include <LiquidCrystal.h>

int led = 13;
int button = 4;
int buzzer = 8;
int tempo = 1000;
int a = 0;

void setup() {
  // put your setup code here, to run once
  pinMode(led, OUTPUT);
  pinMode(button, OUTPUT);
  pinMode(buzzer, OUTPUT);
}
void lampeggio()
{
  delay(tempo);
  digitalWrite(led, HIGH);
  while (digitalRead(button) == LOW);
  digitalWrite(led, LOW);
  while (digitalRead(button) == HIGH);
}
void suono()
{
 delay(tempo);
 tone(buzzer, 1000, 5000);
 while (digitalRead(button) == LOW);
 noTone(buzzer);
 while (digitalRead(button) == HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  lampeggio();
  suono();

}

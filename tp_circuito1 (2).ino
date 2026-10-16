#define LED 3
#define boton 8
#define sensorLuz A4
#include <Servo.h>
Servo servo;

void setup()
{
   pinMode(LED, OUTPUT);
   pinMode(boton, INPUT_PULLUP);
  
   servo.attach(A1);
   servo.write(0);
  
   Serial.begin(9600);
}

void avanzar()
{
  for(int i = 0; i <= 180; i += 10)
  {
    servo.write(i);
    delay(1000);
  }
}

void loop()
{
  int lecturaLuz = analogRead(sensorLuz);
  int porcentajeLuz = map(lecturaLuz, 0, 1023, 0, 100);
  
  Serial.println(porcentajeLuz);
  
  if(porcentajeLuz == 0 && digitalRead(boton)== LOW)
  {
    digitalWrite(LED, HIGH);
  }
  if(digitalRead(boton)== LOW)
  {
    avanzar();
  }
}
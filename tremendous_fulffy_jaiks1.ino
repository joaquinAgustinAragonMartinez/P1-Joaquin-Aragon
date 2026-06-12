#include <Servo.h>
#define sensorTemp A2
#define sensorMov 4
#define boton 2

Servo servo1;
Servo servo2;
int rotacion;
int celsius = 0;
bool sensorMovimiento = LOW;

int boton1 = 2;

void setup()
{
  pinMode(boton, INPUT_PULLUP);
  pinMode(sensorMov, INPUT);
  
  servo1.attach(A0);
  servo1.write(90);
  
  servo2.attach(A1);
  servo2.write(90);
  
  Serial.begin(9600);
}

void loop()
{
  int lecturaTemp = analogRead(sensorTemp);
  celsius = map(((lecturaTemp - 20) * 3.04), 1225, 2025, -40, 125);
  avanzar();
  
  if (sensorMovimiento == true)
  { 
    movTrue();
  }
  
  if (celsius > 90)
  {
    tempTrue();
  }
}

void avanzar()
{
  if (digitalRead(boton1)== LOW)
  {
  	for (int i = 90; i <= 180; i+=10)
    {
      servo1.write(i);
      servo2.write(i);
      delay(3000);
    }
  }
}

void movTrue()
{
  rotacion = rotacion + 0;
  servo1.write(rotacion);
  servo2.write(rotacion);
  delay(6000);
}

void tempTrue()
{
  rotacion = rotacion + 0;
  servo1.write(rotacion);
  servo2.write(rotacion);
}
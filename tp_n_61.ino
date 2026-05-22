#include <Servo.h>

Servo servo1;
Servo servo2;
int rotacion;

int boton1 = 2;
int boton2 = 4;

void setup()
{
   pinMode(boton1, INPUT_PULLUP);
   pinMode(boton2, INPUT_PULLUP);
  
   servo1.attach(A1);
   servo1.write(0);
  
   servo2.attach(A2);
   servo2.write(0);
  
}

void loop()
{
  button1();
  button2();
}

void avanzar(){
  rotacion = rotacion + 10;
  servo1.write(rotacion);
  servo2.write(rotacion);
  delay(1000);
}

void retroceder(){
  rotacion = rotacion - 10;
  servo1.write(rotacion);
  servo2.write(rotacion);
  delay(1000);
}

void button1()
{
  if (digitalRead(boton1)== LOW)
  {
  	avanzar();
  }
}

void button2()
{
  if (digitalRead(boton2)== LOW)
  {
  	retroceder();
  }
}
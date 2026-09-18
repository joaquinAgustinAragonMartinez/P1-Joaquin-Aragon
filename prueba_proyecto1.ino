#include <Servo.h>
//include <Liquid_FruitCrystal> lcd.1

#define LedB 2
#define LedR 4
#define LedG 7
#define piezo 13
#define boton 12

#define pinServo1 A0
#define pot A1
#define sensorTemp A2

#define ARRAY_LEN(array) (sizeof(array) / sizeof(array[0]))
#define Gb3 208
#define C4 262
#define F3 175
#define A3 220

bool cancioncita = false;
int celsius = analogRead(sensorTemp);
int potenciometro = analogRead(pot);


const int midi1[10][3] = {
 {Gb3, 115, 0},
 {C4, 115, 0},
 {Gb3, 115, 0},
 {F3, 115, 0},
 {A3, 115, 115},
 {Gb3, 115, 0},
 {C4, 115, 0},
 {Gb3, 115, 0},
 {F3, 115, 0},
 {A3, 115, 0},
};

void playMidi(int pin, const int notes[][3], size_t len){
 for (int i = 0; i < len; i++) {
    tone(pin, notes[i][0]);
    delay(notes[i][1]);
    noTone(pin);
    delay(notes[i][2]);
  }
}

void setup()
{
  pinMode(LedB, OUTPUT);
  pinMode(LedR, OUTPUT);
  pinMode(LedG, OUTPUT);
  pinMode(piezo, OUTPUT);
  pinMode(boton, INPUT_PULLUP);
  
  map(celsius, 823, 1023, 0, 100);
  map(potencimetro, 0, 1023, 0, 100);
  
  
  //servo.attach(Servo);
  
  //lcd1.setCursor(0,0)
  //lcd1.write("hola");
  
}

void loop()
{ 
  if(potenciometro < 25)
  {
    
  }
  if(potenciometro > 25 && potencimetro < 50)
  {
    
  }
  if(potenciometro > 50)
  {
    
  }
  if(boton == LOW)
  {
    for(int i = 0; i < 10; i++)
    {
      //servo.write(90);
      //servo.write(0);
      delay(2000);
    }
    boton == high;
    cancioncita == true;
  }
  
  while(cancioncita == true)
  {
    playMidi(piezo, midi1, 5);
    digitalWrite(LedG, HIGH);
  }
  if(cancioncita == high)
  {
    
  }
  
  if(cancioncita == false)
  {
    digitalWrite(LedG, LOW);
  }
  
  if(celsius > 40)
  {
    digitalWrite(LedR, HIGH);
  }
  if(celsius < 40)
  {
    digitalWrite(LedB, HIGH);
  }
}
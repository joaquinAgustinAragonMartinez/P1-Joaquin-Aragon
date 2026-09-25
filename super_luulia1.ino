#include <Servo.h>
Servo servo;
#include <Adafruit_LiquidCrystal.h>
Adafruit_LiquidCrystal lcd(0);
#define ledR 11
#define ledB 10
#define ledG 9
#define pin_temp 5
#define pin_mov 4
#define piezo 2

#define pin_pot A1

#define ARRAY_LEN(array) (sizeof(array) / sizeof(array[0]))
#define Gb3 208
#define C4 262
#define F3 175
#define A3 220

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
  lcd.Begin(0, 16);
  servo.attach(A0);
  servo.write(0);
  
  int sensorTemp = analogRead(pin_temp);
  int valor_pot = analogRead(pin_pot);
    
  pinMode(ledR, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(piezo, OUTPUT);
  pinMode(sensorTemp, INPUT);
  pinMode(pin_temp, INPUT);
}

void loop()
{
  int valorPot = map(valor_pot, 1023, 0, 100, 0);
  int sensorMov = digitalRead(pin_mov);
  
  if(sensorMov == HIGH)
  {
     if(valorPot < 10)
     {
        for(int i = 0; i < 8; i++)
     {
        servo.write(90);
        servo.write(0);
     }
    playMidi(piezo, midi1, 5);
    analogWrite(ledG, 255);
    delay(3000);
    analogWrite(ledG, 0);
    }
     if(valorPot > 10 && valorPot < 70)
    {
       for(int i = 0; i < 2; i++)
    {
      servo.write(90);
      servo.write(0);
    }
    playMidi(piezo, midi1, 5);
    analogWrite(ledG, 255);
    delay(3000);
    analogWrite(ledG, 0);
  }
  
  if(valorPot > 70)
  {
    for(int i = 0; i < 5; i++)
    {
      servo.write(90);
      servo.write(0);
    }
    playMidi(piezo, midi1, 5);
    analogWrite(ledG, 255);
    delay(3000);
    analogWrite(ledG, 0);
  }

  }
    
  if(sensorMov == HIGH)
  {
    servo.write(90);
  }
  
  lcd.setCursor(0, 16);
}
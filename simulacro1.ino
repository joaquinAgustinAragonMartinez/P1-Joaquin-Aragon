#include <Servo.h>
#include <Adafruit_LiquidCrystal.h>
Adafruit_LiquidCrystal lcd1(0);

#define LedR 3
#define LedB 5
#define Boton1 2
#define Boton2 4
#define piezo 7

#define servoPin1 A0
#define servoPin2 A1
#define termometro A2

// NOTAS MIDI 1
#define E2 82
#define Fb2 92
#define Gb2 104
#define Ab2 117
#define C3 131

const int midi1[5][3] = {
  {E2, 136, 136},
  {Fb2, 136, 136},
  {Gb2, 136, 136},
  {Ab2, 136, 136},
  {C3, 136, 0}
};

// NOTAS MIDI 2
const int midi2[5][3] = {
  {C3, 136, 136},
  {Ab2, 136, 136},
  {Gb2, 136, 136},
  {Fb2, 136, 136},
  {E2, 136, 136}
};

Servo servo1;
Servo servo2;

bool puertaAbierta = false; 

void playMidi(int pin, const int notes[][3], int len)
{
  for (int i = 0; i < len; i++)
  {
    tone(pin, notes[i][0]);
    delay(notes[i][1]);

    noTone(pin);
    delay(notes[i][2]);
  }
}

void AbrirPuertas()
{
  servo1.write(0);
  servo2.write(0);
  playMidi(piezo, midi1, 5);
}

void CerrarPuertas()
{
  servo1.write(90);
  servo2.write(90);
  playMidi(piezo, midi2, 5);
}

void setup()
{
  lcd1.begin(16,2);
  lcd1.setBacklight(1);
  
  pinMode(LedR, OUTPUT);
  pinMode(LedB, OUTPUT);
  pinMode(Boton1, INPUT_PULLUP);
  pinMode(Boton2, INPUT_PULLUP);
  pinMode(piezo, OUTPUT);
  
  servo1.attach(servoPin1);
  servo2.attach(servoPin2);
  
  servo1.write(90);
  servo2.write(90);
  lcd1.clear();
  lcd1.print("Cerrada");
  
  Serial.begin(9600);
}

void loop()
{
  int porcentajeTemp = analogRead(termometro);
  int grados = map(porcentajeTemp, 0, 1023, 0, 100);
  Serial.print(grados);

  if(digitalRead(Boton1) == LOW && puertaAbierta == false)
  {
    lcd1.clear();
    lcd1.setCursor(0, 0);
    lcd1.print("Abriendo...");
    
    AbrirPuertas();
    puertaAbierta = true;
    
    lcd1.clear();
    lcd1.setCursor(0, 0);
    lcd1.print("Abierta");
    lcd1.setCursor(0, 1);
    lcd1.print("Temperatura:");
    lcd1.print(grados);
  }
  
  if(digitalRead(Boton2) == LOW && puertaAbierta == true)
  {
    lcd1.clear();
    lcd1.setCursor(0, 0);
    lcd1.print("Cerrando...");
    
    CerrarPuertas();
    puertaAbierta = false;
    
    lcd1.clear();
    lcd1.setCursor(0, 0);
    lcd1.print("Cerrada");
    lcd1.setCursor(0, 1);
    lcd1.print("Temperatura:");
    lcd1.print(grados);
    
  }
  if(grados < 10)
  {
    analogWrite(LedR, 0);
    analogWrite(LedB, 255);
  }
  if(grados > 30)
  {
    analogWrite(LedB, 0);
    analogWrite(LedR, 255);
  }
  
  delay(50); 
}
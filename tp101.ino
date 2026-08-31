#include <Servo.h>
#include <Adafruit_LiquidCrystal.h>
Adafruit_LiquidCrystal lcd1(0);

#define sensorMov1 2
#define sensorMov2 4
#define LedR 5
#define LedV 6
#define sensorLuz A2
#define buzzer 8

#define servoPin1 A0
#define servoPin2 A1

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

int valorMov1 = 0;
int valorMov2 = 0;
int porcentajeLuz = 0;

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


bool detectarMovimiento(int pin)
{
  int movimiento = digitalRead(pin);

  if (movimiento == HIGH)
  {
    return true;
  }

  return false;
}


int detectarLuz(int pin)
{
  int lectura = analogRead(pin);

  int porcentaje = map(lectura, 803, 1022, 0, 100);

  return porcentaje;
}


void controlarLuz(int porcentaje)
{
  if (porcentaje <= 20)
  {
    analogWrite(LedR, 255);
    analogWrite(LedV, 255);
  }
  else
  {
    analogWrite(LedR, 0);
    analogWrite(LedV, 0);
  }
}


void abrirPuertas()
{
  servo1.write(0);
  servo2.write(0);

  playMidi(buzzer, midi1, 5);
}


void cerrarPuertas()
{
  servo1.write(90);
  servo2.write(90);

  playMidi(buzzer, midi2, 5);
}


void setup()
{
  lcd1.begin(16,2);
  
  pinMode(sensorMov1, INPUT);
  pinMode(sensorMov2, INPUT);

  pinMode(LedR, OUTPUT);
  pinMode(LedV, OUTPUT);

  pinMode(buzzer, OUTPUT);

  servo1.attach(servoPin1);
  servo2.attach(servoPin2);

  servo1.write(90);
  servo2.write(90);

  Serial.begin(9600);
}

void loop()
{
  lcd1.setBacklight(1);

  porcentajeLuz = detectarLuz(sensorLuz);

  valorMov1 = detectarMovimiento(sensorMov1);
  valorMov2 = detectarMovimiento(sensorMov2);

  controlarLuz(porcentajeLuz);

  if (valorMov1 == true && puertaAbierta == false)
  {
    abrirPuertas();

    puertaAbierta = true;

    lcd1.clear();
    lcd1.setCursor(0, 0);
    lcd1.print("Abierta");
  }

  if (valorMov2 == true && puertaAbierta == true)
  {
    cerrarPuertas();

    puertaAbierta = false;

    lcd1.clear();
    lcd1.setCursor(0, 0);
    lcd1.print("Cerrada");
  }
}
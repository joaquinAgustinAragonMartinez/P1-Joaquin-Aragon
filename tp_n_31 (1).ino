int sensorLuz = A0;
int sensorTemp = A1;

int ledB = 6;
int ledG = 5;
int ledR = 3;

int celsius = 0;
int porcentajeLuz = 0;

void setup()
{
  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledB, OUTPUT);

  Serial.begin(9600);
}

void loop()
{
  int lecturaTemp = analogRead(sensorTemp);
  int lecturaLuz = analogRead(sensorLuz);

  celsius = map(((lecturaTemp - 20) * 3.04), 1225, 2025, -40, 125);

  porcentajeLuz = map(lecturaLuz, 803, 1022, 0, 100);
  
  Serial.print("El nivel de luz actual es: ");
  Serial.print(porcentajeLuz);
  Serial.print("% y la temperatura actual es: ");
  Serial.print(celsius);
  Serial.println(" °C");

  digitalWrite(ledR, LOW);
  digitalWrite(ledG, LOW);
  digitalWrite(ledB, LOW);

  if (porcentajeLuz >= 30 && porcentajeLuz <= 70)
  {
    if (celsius > 90)
    {
      digitalWrite(ledR, HIGH);
    }
    else if (celsius < 18)
    {
      digitalWrite(ledB, HIGH);
    }
    else
    {
      digitalWrite(ledG, HIGH);
    }
  }

  delay(500);
}
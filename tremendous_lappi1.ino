bool sensorMovimiento = LOW;
int detectSonido = 4;
int ledR = 8;
int ledG = 7;


void setup()
{
  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(sensorMovimiento, INPUT);
  pinMode(detectSonido, OUTPUT);

}

void loop()
{
  sensorMovimiento = digitalRead(2);
  digitalWrite(ledR, LOW);
  digitalWrite(ledG, LOW);
  
  if (sensorMovimiento == true)
  { 
    digitalWrite(ledR, HIGH);
    digitalWrite(detectSonido, HIGH);
  }
  else
  {
    digitalWrite(ledG, HIGH);
    digitalWrite(detectSonido, LOW);
  }
  delay (100);
}
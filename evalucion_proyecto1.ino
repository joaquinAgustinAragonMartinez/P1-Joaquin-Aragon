#define LEDG 6
#define LEDB 5

#define sensorM A0
#define POT A1
#define sensorT A2

void setup()
{
  pinMode(LEDG, OUTPUT);
  pinMode(LEDB, OUTPUT);
  pinMode(sensorM, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  int lecturaMov = digitalRead(sensorM);
  int lecturaPOT = digitalRead(POT);
  int lecturaTemp = digitalRead(sensorT);
  
  lecturaPOT = map(lecturaPOT,0,1023,0,100);
  
  lecturaTemp = map(lecturaTemp,823,1023,-50,50);
  
  Serial.print("ajuste el potenciometro");
  
  if(lecturaPOT > 50 && lecturaTemp > 20)
  {
    if (lecturaMov == HIGH)
    {
      digitalWrite(LEDG, 150);
      digitalWrite(LEDB, 100);
    }
  }
}
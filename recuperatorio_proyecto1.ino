int sensor_mov = 2;
int LEDR = 3;
int LEDG = 5;
int G = 6;
int R = 9;

int sensor_temp = A0;
int POT = A1;
int nivel_luz = A2;
int celsius = 0;

void setup()
{
  pinMode(LEDR, OUTPUT);
  pinMode(LEDG, OUTPUT);
  pinMode(sensor_mov, INPUT);
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  
  Serial.begin(9600);
}

void loop()
{
  int valor_mov = digitalRead(sensor_mov);
  int valor_temp = analogRead(sensor_temp);
  int valor_POT = analogRead(POT);
  int valor_luz = analogRead(nivel_luz);
    
  celsius = map (((valor_temp - 20)* 3.04), 200, 1023, 0, 100);
  int valorf_POT = map (valor_POT, 0, 1023, 0, 100);
  int valorf_luz = map (valor_luz, 0, 1023, 0, 100);
  
  if(valorf_POT >= 50 && valorf_POT <= 75 && celsius < 15)
  {
    if(valor_mov == HIGH){
      analogWrite(LEDR, 255);
      delay(1000);
      analogWrite(LEDG, 255);
      delay(1000);
      analogWrite(R, 255);
      analogWrite(G, 255);
      delay(1000);
    }
    else{
      analogWrite(LEDR, 0);
      analogWrite(LEDG, 0);
      analogWrite(G, 0);
      analogWrite(R, 0);
    }
  }
  if(valorf_luz == 99){
    analogWrite(LEDR, 255);
    analogWrite(LEDG, 255);
    analogWrite(R, 255);
    analogWrite(G, 255);
  }
  else{
    analogWrite(LEDR, 0);
    analogWrite(LEDG, 0);
    analogWrite(R, 0);
    analogWrite(G, 0);
  }
}
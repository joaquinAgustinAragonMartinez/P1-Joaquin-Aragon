int potR = A0;
int potG = A1;
int potB = A2;

int ledR = 11;
int ledG = 10;
int ledB = 9;

int boton = 2;

bool enProceso = false;

void setup() {
  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(boton, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop() {

  if (digitalRead(boton) == LOW && !enProceso) {
    enProceso = true;

    Serial.println("Tiene 10 s para configurar el color del led...");

    delay(10000);
    
    int inicio = millis();

    int valorR = 0;
    int valorG = 0;
    int valorB = 0;

    while (millis() - inicio < 10000){

      valorR = analogRead(potR);
      valorG = analogRead(potG);
      valorB = analogRead(potB);

      valorR = map(valorR, 0, 1023, 0, 255);
      valorG = map(valorG, 0, 1023, 0, 255);
      valorB = map(valorB, 0, 1023, 0, 255);

      analogWrite(ledR, valorR);
      analogWrite(ledG, valorG);
      analogWrite(ledB, valorB);
    }

    Serial.print("El led esta usando esta configuracion de colores RGB: (");
    Serial.print(valorR);
    Serial.print(", ");
    Serial.print(valorG);
    Serial.print(", ");
    Serial.print(valorB);
    Serial.println(")");
    
    analogWrite(ledR, 0);
    analogWrite(ledG, 0);
    analogWrite(ledB, 0);

    enProceso = false;
  }
}
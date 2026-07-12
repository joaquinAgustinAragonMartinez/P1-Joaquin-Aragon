#define POT A0

int rojo = 9;
int verde = 10;
int azul = 11;

int valores[30];

void setup()
{
  pinMode(rojo, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(azul, OUTPUT);
  
  Serial.begin(9600);

  randomSeed(analogRead(A1));
}

void loop()
{
  int valor = analogRead(POT);
  int porcentaje = map(valor, 0, 1023, 0, 100);
  
  if (porcentaje >= 0 && porcentaje <= 20)
  {
    ejercicio1();
  }
  else if (porcentaje > 20 && porcentaje <= 40)
  {
    ejercicio2();
  }
  else if (porcentaje > 40 && porcentaje <= 60)
  {
    ejercicio3();
  }
  else if (porcentaje > 60 && porcentaje <= 80)
  {
    ejercicio4();
  }
  else
  {
    ejercicio5();
  }
}


void ejercicio1()
{
  int lista[] = {20, 40, 60, 80};
  int nuevaLista[4];

  int factor = 3;

  for (int i = 0; i < 4; i++)
  {
    nuevaLista[i] = lista[i] * factor;

    Serial.println(nuevaLista[i]);

    analogWrite(rojo, nuevaLista[i]);
    analogWrite(verde, nuevaLista[i]);
    analogWrite(azul, nuevaLista[i]);

    delay(1000);
  }
}


void ejercicio2()
{
  int notas[10] = {7, 8, 6, 9, 5, 8, 7, 10, 6, 9};
  int suma = 0;

  for (int i = 0; i < 10; i++)
  {
    suma += notas[i];
  }

  float promedio = suma / 10.0;

  Serial.print("el promedio es ");
  Serial.println(promedio);

  if (promedio <= 5)
  {
    analogWrite(rojo, 255);
    analogWrite(verde, 0);
    analogWrite(azul, 0);
  }
  else if (promedio <= 8)
  {
    analogWrite(rojo, 0);
    analogWrite(verde, 255);
    analogWrite(azul, 0);
  }
  else
  {
    analogWrite(rojo, 0);
    analogWrite(verde, 255);
    analogWrite(azul, 255);
  }
}


void ejercicio3()
{
  int numeros[15] = {7, 8, 6, 9, 5, 8, 7, 10, 6, 9, 5, 2, 9, 3, 1};
  
  for (int i = 0; i < 15; i++)
  {
    if (numeros[i] % 2 == 0)
    {
      analogWrite(verde, 255);
      analogWrite(rojo, 0);
    }
    else
    {
      analogWrite(rojo, 255);
      analogWrite(verde, 0);
    }

    Serial.println(numeros[i]);
    delay(1000);
  }
}


void ejercicio4()
{
  int max1 = -1;
  int max2 = -1;
  int max3 = -1;
  
  for(int i = 0; i < 30; i++)
  {
    valores[i] = random(0,256);
   
    if(valores[i] > max1)
    {
      max3 = max2;
      max2 = max1;
      max1 = valores[i];
    }
    else if(valores[i] > max2)
    {
      max3 = max2;
      max2 = valores[i];
    }
    else if(valores[i] > max3)
    {
      max3 = valores[i];
    }
  }
  
  Serial.print("el valor max1 en rojo es ");
  Serial.println(max1);
  
  Serial.print("el valor max2 en verde es ");
  Serial.println(max2);
  
  Serial.print("el valor max3 en azul es ");
  Serial.println(max3);
  
  analogWrite(rojo, max1);
  analogWrite(verde, max2);
  analogWrite(azul, max3);
  
  delay(1000);
}


void ejercicio5()
{
  int min1 = 256;
  int min2 = 256;
  int min3 = 256;
  
  for(int i = 0; i < 30; i++)
  {
    valores[i] = random(0,256);
   
    if(valores[i] < min1)
    {
      min3 = min2;
      min2 = min1;
      min1 = valores[i];
    }
    else if(valores[i] < min2)
    {
      min3 = min2;
      min2 = valores[i];
    }
    else if(valores[i] < min3)
    {
      min3 = valores[i];
    }
  }
  
  Serial.print("el valor min1 en rojo es ");
  Serial.println(min1);
  
  Serial.print("el valor min2 en verde es ");
  Serial.println(min2);
  
  Serial.print("el valor min3 en azul es ");
  Serial.println(min3);
  
  analogWrite(rojo, min1);
  analogWrite(verde, min2);
  analogWrite(azul, min3);
  
  delay(1000);
}
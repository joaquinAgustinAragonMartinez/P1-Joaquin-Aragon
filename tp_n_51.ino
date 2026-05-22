int LEDR = 6;
int LEDG = 5;
int LEDB = 3;

void setup()
{
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(3, OUTPUT);
}

void loop()
{
  for (int G = 0; G <= 255; G += 50)
  {
    analogWrite(LEDG, G);
    delay(200);
    for (int B = 0; B <= 255; B += 50)
    {
      analogWrite(LEDB, B);
      delay(200);
      for (int R = 0; R <= 255; R += 50)
      {
        analogWrite(LEDR, R);
        delay(200);
      }
    }
  }
}

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
  for (int R = 0; R < 256; R ++)
  {
    for (int G = 0; G < 256; G ++)
    {
      for (int B = 0; B < 256; B ++)
      {
        analogWrite(LEDR, R);
        analogWrite(LEDG, G);
        analogWrite(LEDB, B);
        delay(1);
      }
    }
  }
}
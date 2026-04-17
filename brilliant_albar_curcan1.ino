void setup()
{
  pinMode(11, OUTPUT); pinMode(10, OUTPUT); pinMode(9, OUTPUT); 
  pinMode(13, OUTPUT); pinMode(12, OUTPUT); pinMode(8, OUTPUT); 
  pinMode(6, OUTPUT); pinMode(5, OUTPUT); pinMode(3, OUTPUT); 
}
void ApagarTodo()
{
  analogWrite(11, 0); analogWrite(10, 0); analogWrite(9, 0); 
  digitalWrite(13, LOW); digitalWrite(12, LOW); digitalWrite(8, LOW); 
  analogWrite(6, 0); analogWrite(5, 0); analogWrite(3, 0);
}
void ParpadeoNaranja()
{
  for (int i = 0; i < 4; i++){
    analogWrite(11, 255); analogWrite(10, 100); analogWrite(9,0);
    digitalWrite(13, HIGH); digitalWrite(12, HIGH); digitalWrite(8, LOW);
    analogWrite(6, 255); analogWrite(5, 100); analogWrite(3, 0);
    
    delay(100);
    ApagarTodo();
    delay(100);
  }
}
void loop()
{
  ApagarTodo();
  analogWrite(11, 255);
  delay (1000);
  ParpadeoNaranja();
  
  ApagarTodo();
  digitalWrite(13, HIGH);
  digitalWrite(8, HIGH);
  delay(1000);
  ParpadeoNaranja();
  
  ApagarTodo();
  analogWrite(5, 80);
  analogWrite(3, 80);
  delay(1000);
  ParpadeoNaranja();
}
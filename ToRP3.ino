int TempPin = A0;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int Val = analogRead(TempPin);
  Val = Val * 1000/10 * 5/1024;

  Serial.print("Temp : ");
  Serial.println(Val);
  delay(500);
}


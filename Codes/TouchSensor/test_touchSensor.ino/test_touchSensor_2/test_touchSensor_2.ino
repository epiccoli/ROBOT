int pin = 2;

void setup()
{
  Serial.begin(9600);
  attachInterrupt(0, touch, CHANGE); // 0 => digital pin 2 = int.0
}

void loop()
{
//  Serial.println("NO TOUCH");
//  delay(250);
}

void touch()
{
  Serial.println("TOUCH");
}


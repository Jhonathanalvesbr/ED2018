//IR Obstacle Collision Detection Module

int MotorDireita = 8; // Motor Direita
int MotorEsquerda = 9; // Motor Esquerda
int SensorDireita = 7;  // Sensor Direita
int SensorEsquerda = 6;  // Sensor Esquerda

void setup()
{
  for(int x = 8; x <= 9; x++)
  {
    pinMode(x, OUTPUT);
  }

  for(int x = 6; x <= 7; x++)
  {
    pinMode(x, INPUT);
  }
  
  Serial.begin(9600);
}

void loop()
{
    
  if (digitalRead(SensorDireita) == HIGH)
  {
    Serial.println("Direita");
  }
  else if(digitalRead(SensorEsquerda) == HIGH)
  {
    Serial.println("Esquerda");
  }
  else
  {
    Serial.println("Frente");
  }
    
  delay(200);
}

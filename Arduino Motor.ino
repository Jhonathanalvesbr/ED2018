// IR Obstacle Collision Detection Module

int MotorDireita = 8; // Motor Direita
int MotorEsquerda = 9; // Motor Esquerda
int isObstaclePin = 7;  // This is our input pin
int isObstacle = HIGH;  // HIGH MEANS NO OBSTACLE

void setup() {
  pinMode(MotorDireita, OUTPUT);
  pinMode(MotorEsquerda, OUTPUT);
  pinMode(isObstaclePin, INPUT);
  Serial.begin(9600);
  
}

void loop() {
  isObstacle = digitalRead(isObstaclePin);
  if (isObstacle == LOW)
  {
    Serial.println("OBSTACLE!!, OBSTACLE!!");
   // digitalWrite(LED, HIGH);
  }
  else
  {
    Serial.println("clear");
//    digitalWrite(LED, LOW);
  }

  digitalWrite(MotorDireita, HIGH);
  digitalWrite(MotorEsquerda, HIGH);

  
  delay(200);
}


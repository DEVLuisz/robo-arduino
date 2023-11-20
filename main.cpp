#include <NewPing.h>

#define ECHO_PIN_1 2 
#define ECHO_PIN_2 11
#define ECHO_PIN_3 6

#define TRIGGER_PIN_1 3
#define TRIGGER_PIN_2 12
#define TRIGGER_PIN_3 7

#define MAX_DISTANCE 200 // Distância máxima para detecção em centímetros

#define MOTOR_ENA 5// Pino de controle do motor 1 esquerdo
#define MOTOR_ENB 10// Pino de controle do motor 1 direito
#define MOTOR_ENA_2 4// Pino de controle do motor 2 esquerdo
#define MOTOR_ENB_2 9// Pino de controle do motor 2 direito

NewPing sonar1(TRIGGER_PIN_1, ECHO_PIN_1, MAX_DISTANCE);
NewPing sonar2(TRIGGER_PIN_2, ECHO_PIN_2, MAX_DISTANCE);
NewPing sonar3(TRIGGER_PIN_3, ECHO_PIN_3, MAX_DISTANCE);

void setup() {
  Serial.begin(9600);
  Serial.println("Lendo dados dos sensores...");
  pinMode(MOTOR_ENA, OUTPUT);
  pinMode(MOTOR_ENB, OUTPUT);
  pinMode(MOTOR_ENA_2, OUTPUT);
  pinMode(MOTOR_ENB_2, OUTPUT);
}

void loop() {
  delay(2000);
  unsigned int distance1 = sonar1.ping_cm(); // Medir a distância do sensor 1 em centímetros
  unsigned int distance2 = sonar2.ping_cm(); // Medir a distância do sensor 2 em centímetros
  unsigned int distance3 = sonar3.ping_cm();
  // Exibe informações no serial monitor
  Serial.print("Distancia Sensor 1 em cm: ");
  Serial.println(distance1);
  Serial.print("Distancia Sensor 2 em cm: ");
  Serial.println(distance2);
  Serial.print("Distancia Sensor 3 em cm: ");
  Serial.println(distance3);
  // Verificar o movimento e controlar os motores com base nas leituras dos sensores
  if (distance1 < 50) { // Se o sensor 1 detectar movimento
    digitalWrite(MOTOR_ENA, HIGH); // Ligar o motor 1 esquerdo
    digitalWrite(MOTOR_ENB, HIGH); // Ligar o motor 1 direito
  } else {
    digitalWrite(MOTOR_ENA, LOW); // Desligar o motor 1 esquerdo
    digitalWrite(MOTOR_ENB, LOW); // Desligar o motor 1 direito
  }

  if (distance2 < 50) { // Se o sensor 2 detectar movimento
    digitalWrite(MOTOR_ENA_2, HIGH); // Ligar o motor 2 esquerdo
    digitalWrite(MOTOR_ENB_2, HIGH); // Ligar o motor 2 direito
  } else {
    digitalWrite(MOTOR_ENA_2, LOW); // Desligar o motor 2 esquerdo
    digitalWrite(MOTOR_ENB_2, LOW); // Desligar o motor 2 direito
  }
  if (distance3 < 50) { // Se o sensor 3 detectar movimento
    digitalWrite(MOTOR_ENB, HIGH); // Ligar o motor 1 esquerdo
    digitalWrite(MOTOR_ENA, HIGH); // Ligar o motor 2 direito
  } else {
    digitalWrite(MOTOR_ENA, LOW); // Desligar o motor 1 esquerdo
    digitalWrite(MOTOR_ENB, LOW); // Desligar o motor 2 direito
  }
}
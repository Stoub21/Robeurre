#include <SoftwareSerial.h>

#define FORWARD 'F'
#define BACKWARD 'B'
#define LEFT 'L'
#define RIGHT 'R'
#define CIRCLE 'C'
#define CROSS 'X'
#define TRIANGLE 'T'
#define SQUARE 'S'
#define START 'A'
#define PAUSE 'P'

// Création d'une instance de la bibliothèque SoftwareSerial pour la communication avec le module Bluetooth
SoftwareSerial bluetooth(10, 11); // RX | TX

// Variable booléenne pour suivre l'état de la connexion Bluetooth
bool connected = false;
bool start = false;

//Motor 1
const int motorPin1 = 9;
const int motorPin2 = 8;
//Motor 2
const int motorPin3 = 7;
const int motorPin4 = 6;
int speed = 180;

void setup() {
  // Initialisation de la communication série avec le moniteur série
  Serial.begin(9600);

  // Initialisation de la communication série avec le module Bluetooth
  bluetooth.begin(9600);

  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);

  digitalWrite(LED_BUILTIN, LOW); 

  //Set pins as outputs
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);

  analogWrite(motorPin1, 0);
  analogWrite(motorPin2, 0);
  analogWrite(motorPin3, 0);
  analogWrite(motorPin4, 0);

  // Affichage d'un message dans le moniteur série pour indiquer que la carte Arduino est prête à recevoir des connexions Bluetooth
  Serial.println("Arduino prêt à recevoir des connexions Bluetooth");
}

void loop() {
  // Vérification si des données sont disponibles en entrée sur le module Bluetooth
  if (bluetooth.available()) {
    // Lecture de la donnée disponible en entrée sur le module Bluetooth
    char c = bluetooth.read();

    // Affichage de la donnée lue dans le moniteur série
    Serial.println(c);

    // Mise à jour de la variable booléenne pour indiquer que la connexion Bluetooth est établie
    connected = true;
    executeCommande(c);
  }
}

void executeCommande(char command){
  if (start){
    stopRobot();
    delay(10);
  }
  switch (command){
    case FORWARD:
      if (start){
        analogWrite(motorPin1, speed);
        analogWrite(motorPin3, speed);
      }
      break;
    case BACKWARD:
      if (start){
        analogWrite(motorPin2, speed);
        analogWrite(motorPin4, speed);
      }
      break;
    case LEFT:
      if (start){
        analogWrite(motorPin1, speed);
        analogWrite(motorPin4, speed);
      }
      break;
    case RIGHT:
      if (start){
        analogWrite(motorPin2, speed);
        analogWrite(motorPin3, speed);
      }
      break;
    case CIRCLE:
      if (start){
      }
      break;
    case CROSS:
      if (start){
      }
      break;
    case TRIANGLE:
      if (start){
      }
      break;
    case SQUARE:
      if (start){
      }
      break;
    case START:
      start = true;
      digitalWrite(LED_BUILTIN, HIGH);
      break;
    case PAUSE:
      start = false;
      digitalWrite(LED_BUILTIN, LOW);
      stopRobot();
      break;
  }
}

void stopRobot(){
  analogWrite(motorPin1, 0);
  analogWrite(motorPin2, 0);
  analogWrite(motorPin3, 0);
  analogWrite(motorPin4, 0);
}
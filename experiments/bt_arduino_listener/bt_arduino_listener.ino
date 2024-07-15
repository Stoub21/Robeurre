#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10, 11); // RX | TX

void setup() {
  Serial.begin(57600);
  BTSerial.begin(57600); // Assurez-vous que le baudrate correspond à celui du HC-05
  Serial.println("Bluetooth HC-05 initialized.");
}

void loop() {
  // Si des données sont disponibles sur le port série du Bluetooth
  if (BTSerial.available()) {
    Serial.write(BTSerial.read());
  }

  // Si des données sont disponibles sur le port série de l'Arduino
  if (Serial.available()) {
    BTSerial.write(Serial.read());
  }
}

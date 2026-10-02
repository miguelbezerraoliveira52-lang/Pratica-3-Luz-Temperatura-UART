#include <Arduino.h>

#define RX_PIN 26
#define TX_PIN 27

HardwareSerial UART(1);

void setup() {
  Serial.begin(115200);

  UART.begin(9600, SERIAL_8N1, RX_PIN, TX_PIN);

  Serial.println("ESP32 B - Terminal iniciado");
  Serial.println("Digite uma mensagem no Monitor Serial.");
}

void loop() {

  if (UART.available()) {
    String mensagem = UART.readStringUntil('\n');
    mensagem.trim();

    if (mensagem.length() > 0) {
      Serial.println("Recebido da ESP32 A: " + mensagem);
    }
  }

  if (Serial.available()) {
    String mensagem = Serial.readStringUntil('\n');
    mensagem.trim();

    if (mensagem.length() > 0) {
      UART.println(mensagem);
      Serial.println("Enviado para ESP32 A: " + mensagem);
    }
  }
}
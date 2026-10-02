#include <Arduino.h>
#include <math.h>

#define LDR_PIN 34
#define NTC_PIN 35

#define RX_PIN 26
#define TX_PIN 27

HardwareSerial UART(1);

const float R_FIXED = 10000.0;
const float R0 = 10000.0;
const float BETA = 3950.0;
const float T0 = 298.15;

void setup() {
  Serial.begin(115200);

  UART.begin(9600, SERIAL_8N1, RX_PIN, TX_PIN);

  analogReadResolution(12);

  Serial.println("ESP32 A - Sensores iniciados");
}

void loop() {

  int valorLDR = analogRead(LDR_PIN);
  int valorNTC = analogRead(NTC_PIN);

  float tensaoNTC = (valorNTC / 4095.0) * 3.3;

  float resistenciaNTC;

  if (tensaoNTC > 0.0 && tensaoNTC < 3.3) {
    resistenciaNTC = R_FIXED * (3.3 / tensaoNTC - 1.0);
  } else {
    resistenciaNTC = R0;
  }

  float temperaturaK = 1.0 /
      ((1.0 / T0) +
       (1.0 / BETA) * log(resistenciaNTC / R0));

  float temperaturaC = temperaturaK - 273.15;

  String dados = "LUZ:" + String(valorLDR) +
                 ";TEMP:" + String(temperaturaC, 2);

  UART.println(dados);

  Serial.println("Enviado: " + dados);

  if (UART.available()) {
    String mensagem = UART.readStringUntil('\n');
    mensagem.trim();

    if (mensagem.length() > 0) {
      Serial.println("Mensagem recebida: " + mensagem);
    }
  }

  delay(2000);
}
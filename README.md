# Prática 3 — Luz e Temperatura por UART

## 📌 Descrição

Nesta prática foi desenvolvido um sistema utilizando duas placas **ESP32**, programadas através da **Arduino IDE**, para realizar a leitura de grandezas ambientais e realizar a comunicação entre as placas por meio da comunicação serial **UART**.

A **ESP32 A** realiza a leitura de um sensor **LDR**, utilizado para medir a luminosidade, e de um **termistor NTC de 10 kΩ**, utilizado para medir a temperatura.

Os valores obtidos são enviados para a **ESP32 B** através da comunicação UART. A segunda ESP32 recebe os dados e também permite o envio de mensagens para a primeira placa, funcionando como um pequeno chat serial.

## 🔧 Componentes utilizados

* 2x ESP32 DevKit V1
* 1x LDR
* 1x Termistor NTC 10 kΩ (B = 3950 K)
* 2x Resistores de 10 kΩ
* 1x Protoboard
* Jumpers
* 2x Cabos USB

## ⚙️ Funcionamento

### ESP32 A

A ESP32 A é responsável por:

* Realizar a leitura do LDR;
* Realizar a leitura do NTC;
* Calcular a temperatura em °C;
* Enviar os valores pela UART;
* Receber mensagens enviadas pela ESP32 B.

### ESP32 B

A ESP32 B é responsável por:

* Receber os valores de luminosidade e temperatura;
* Exibir os dados no Monitor Serial;
* Permitir o envio de mensagens para a ESP32 A.

## 🔌 Comunicação UART

A comunicação entre as placas utiliza:

* **Baud rate:** 9600
* **Formato:** 8N1
* **TX da ESP32 A → RX da ESP32 B**
* **RX da ESP32 A ← TX da ESP32 B**
* **GND → GND**

### Pinos utilizados

| Função | ESP32 A | ESP32 B |
| ------ | ------: | ------: |
| TX     | GPIO 27 | GPIO 27 |
| RX     | GPIO 26 | GPIO 26 |
| GND    |     GND |     GND |

A comunicação utiliza a `Serial1` da ESP32.

## 🌡️ Sensores

O LDR está conectado ao **GPIO 34** e o NTC ao **GPIO 35** da ESP32 A.

Os sensores são utilizados em divisores de tensão com resistores de **10 kΩ**.

## 💻 Arquivos

* `ESP32_A_Sensores.ino` — código responsável pelas leituras dos sensores e comunicação da ESP32 A.
* `ESP32_B_UART.ino` — código responsável pelo recebimento dos dados e pelo chat UART da ESP32 B.

## 🛠️ Ferramenta utilizada

* Arduino IDE
* ESP32 DevKit V1
* Linguagem C/C++ para Arduino

## 🎯 Objetivo

Compreender a utilização de sensores analógicos com a ESP32 e implementar uma comunicação serial UART entre duas placas, permitindo o compartilhamento das informações coletadas e a troca de mensagens entre os dispositivos.

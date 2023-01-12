# Kenshi Blockchain IoT SDK

Kenshi Blockchain IoT SDK enables receiving and processing blockchain events
on IoT devices. Visit the
[Kenshi IoT documentation](https://kenshi.io/docs/services/iot) to learn more.

## Supported blockchains

Currently Ethereum, BNB Smart Chain, Avalanche, Fantom, and Polygon are supported.

## Supported platforms

Currently the Kenshi IoT SDK supports Arduino and ESP32-compatible boards through
the Arduino IDE and ecosystem.

### Supported development boards

The following boards and platforms are supported by this SDK:

#### ESP32 product family

All boards based on the ESP32 SoC and programmable by Arduino IDE, including
ESP32 Devkits, Adafruit HUZZAH32, SparkFun ESP32 Thing Plus, Wemos LOLIN D32,
NodeMCU, ESPduino 32, and others.

#### Arduino product family

Any board with internet connectivity supported by one of the libraries below:

- [WiFiNINA](https://github.com/arduino-libraries/WiFiNINA):
  Arduino MKR WiFi 1010,
  Arduino MKR VIDOR 4000,
  Arduino UNO WiFi Rev.2,
  Arduino Nano 33 IoT,
  Arduino Nano RP2040 Connect
- [WiFi101](https://github.com/arduino-libraries/WiFi101):
  Arduino MKR1000 WiFi,
  Arduino/Genuino Wifi Shield 101
- [Ethernet](https://github.com/arduino-libraries/Ethernet):
  Arduino Ethernet Board,
  Arduino Ethernet Shield
- [MKRGSM](https://github.com/arduino-libraries/MKRGSM):
  Arduino MKR GSM 1400
- [MKRNB](https://github.com/arduino-libraries/MKRNB):
  Arduino MKR NB 1500
- [WiFi](https://github.com/arduino-libraries/WiFi):
  Arduino WiFi Shield
- [GSM](https://github.com/arduino-libraries/GSM):
  Arduino GSM Shield

## Examples

- [Blinky](./SDK/Arduino/examples/blinky/): Blink a LED trigerred by a blockchain event,
  for Arduino MKR WiFi. Example can be easily adapted to other Arduino boards.
- [Blinky32](./SDK/Arduino/examples/blinky32/): Blinky example for ESP32

## License

All libraries are released under Apache-2.0 license.

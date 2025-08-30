#include "SL002_DHT11.h"

SL002_DHT11::SL002_DHT11(uint8_t pin) {
  _pin = pin;
  humidity = 0;
  temperature = 0;
}

int8_t SL002_DHT11::read() {
  uint8_t i;
  for (i = 0; i < 5; i++) data[i] = 0;
  pinMode(_pin, OUTPUT);
  digitalWrite(_pin, LOW);
  delay(20);
  digitalWrite(_pin, HIGH);
  delayMicroseconds(40);
  pinMode(_pin, INPUT);
  unsigned int loopCnt = 10000;
  while (digitalRead(_pin) == HIGH) if (--loopCnt == 0) return DHT_ERROR_TIMEOUT;
  loopCnt = 10000;
  while (digitalRead(_pin) == LOW) if (--loopCnt == 0) return DHT_ERROR_TIMEOUT;
  loopCnt = 10000;
  while (digitalRead(_pin) == HIGH) if (--loopCnt == 0) return DHT_ERROR_TIMEOUT;
  for (i = 0; i < 40; i++) {
    loopCnt = 10000;
    while (digitalRead(_pin) == LOW) if (--loopCnt == 0) return DHT_ERROR_TIMEOUT;
    unsigned long t = micros();
    loopCnt = 10000;
    while (digitalRead(_pin) == HIGH) if (--loopCnt == 0) return DHT_ERROR_TIMEOUT;
    unsigned long pulseLen = micros() - t;
    data[i / 8] <<= 1;
    if (pulseLen > 40) data[i / 8] |= 1;
  }
  if (data[4] != (uint8_t)(data[0] + data[1] + data[2] + data[3])) {
    return DHT_ERROR_CHECKSUM;
  }
  humidity    = data[0] + data[1] * 0.1;
  temperature = data[2] + data[3] * 0.1;
  return DHT_OK;
}

float SL002_DHT11::getHumidity() {
  return humidity;
}

float SL002_DHT11::getTemperature() {
  return temperature;
}
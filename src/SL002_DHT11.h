#ifndef SL002_DHT11_H
#define SL002_DHT11_H
#include <Arduino.h>
#define DHT_OK              0
#define DHT_ERROR_CHECKSUM -1
#define DHT_ERROR_TIMEOUT  -2

class SL002_DHT11 {
  public:
    SL002_DHT11(uint8_t pin);
    int8_t read();
    float getHumidity();
    float getTemperature();

  private:
    uint8_t _pin;
    uint8_t data[5];
    float humidity;
    float temperature;
};
#endif
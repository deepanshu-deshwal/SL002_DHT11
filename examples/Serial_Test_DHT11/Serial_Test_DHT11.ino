#include <SL002_DHT11.h>
#define DHTPIN 2

SL002_DHT11 dht(DHTPIN);

void setup() {
  Serial.begin(9600);
}

void loop() {
  int8_t chk = dht.read();
  if (chk == DHT_OK) {
    Serial.print("Humidity: ");
    Serial.print(dht.getHumidity());
    Serial.print(" %\t");
    Serial.print("Temperature: ");
    Serial.print(dht.getTemperature());
    Serial.println(" *C");
  } else {
    Serial.print("Error: ");
    Serial.println(chk);
  }
  delay(2000);
}
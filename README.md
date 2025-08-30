# SL002_DHT11
- Simple Arduino library for reading DHT11 temperature & humidity sensor.  
- Provides a minimal API with error codes.  

---

## Features
- Supports DHT11 sensor.  
- Returns humidity and temperature as float.  

---

## Error codes
- `DHT_OK` → Success  
- `DHT_ERROR_CHECKSUM` → Data corruption  
- `DHT_ERROR_TIMEOUT` → No response  

---

## Installation

### Arduino IDE
- Open Arduino IDE → Sketch → Include Library → Manage Libraries…  
- Search for **SL002_DHT11** and install.  

### Manual
- Download the latest release.  
- Open Arduino IDE → Sketch → Include Library → Add .ZIP Library….  
- Select the downloaded ZIP.  

---

## Usage Example: for DHT11

```cpp
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
```

## License
This library is licensed under the MIT License.  
Copyright (c) 2025  
Deepanshu Deshwal

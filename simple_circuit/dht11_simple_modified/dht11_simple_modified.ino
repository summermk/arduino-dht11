// Example testing sketch for various DHT humidity/temperature sensors
// Written by ladyada, public domain
// Modified by Mira Kim

#include "DHT.h"

DHT dht(2, DHT11);

void setup() {
  Serial.begin(9600);
  Serial.println("Program Start");
  dht.begin();
}

void loop() {
  delay(2000);

  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed");
    return;
  }

  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println(" *C ");
}

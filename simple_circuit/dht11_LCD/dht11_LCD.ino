// Example testing sketch for various DHT humidity/temperature sensors
// Written by ladyada, public domain
// Modified by Mira Kim


#include "DHT.h"
#include <LiquidCrystal.h>

DHT dht(7, DHT11);
LiquidCrystal lcd(12,11,5,4,3,2);

void setup() {
  Serial.begin(9600);
  Serial.println("Program Start");
  dht.begin();
  
  lcd.begin(16, 2);
  lcd.clear();
  lcd.print("START ");
}

void loop() {
  delay(2000);
               
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    
    Serial.println("Failed");
    
    lcd.clear();
    lcd.print("Humidity: - ");
  
    lcd.setCursor(0,1);
    lcd.print("Temp:  -");
    
  } else {
    
    Serial.print("Humidity: ");
    Serial.print(h);
    Serial.print(" %\t");
    Serial.print("Temperature: "); 
    Serial.print(t);
    Serial.println(" *C ");

    lcd.clear();
    lcd.print("Humidity: ");
    lcd.print(h);
  
    lcd.setCursor(0,1);
    lcd.print("Temp: ");
    lcd.print(t);
    
  }
}


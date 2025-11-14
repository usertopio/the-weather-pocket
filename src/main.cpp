// Libraries
// Arduino framework
#include <Arduino.h>

// Components’ header files
// BME280
#include <bme280.h>

void setup() {
  Serial.begin(115200);
  delay(1000);

  // BME280
  Serial.println("Initializing BME280 via SPI...");
  if (!bme.begin()) {
    Serial.println("Could not find BME280! Check wiring.");
    while (1);
  }
  Serial.println("BME280 initialized successfully!");
}

void loop() {
  // BME280
  Serial.print("Temperature = ");
  Serial.print(bme.readTemperature());
  Serial.println(" °C");

  Serial.print("Humidity = ");
  Serial.print(bme.readHumidity());
  Serial.println(" %");

  Serial.print("Pressure = ");
  Serial.print(bme.readPressure() / 100.0F);
  Serial.println(" hPa");

  Serial.print("Altitude = ");
  Serial.print(bme.readAltitude(SEA_LEVEL_PRESSURE_HPA));
  Serial.println(" m");

  Serial.println();
  delay(2000);
}

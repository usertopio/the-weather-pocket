// Libraries
// Arduino framework
#include <Arduino.h>

// BME280
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

// Define component connection pins
// BME280
#define BME_SCK  18 //SCL
#define BME_MISO 19 //SDA
#define BME_MOSI 23 //SDO
#define BME_CS   5 //CSB

#define SEA_LEVEL_PRESSURE_HPA 1010

Adafruit_BME280 bme(BME_CS, BME_MOSI, BME_MISO, BME_SCK);

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

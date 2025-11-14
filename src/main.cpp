// Libraries
// Arduino framework
#include <Arduino.h>

// Components’ header files
// BME280
#include <bme280.h>
// NEO6M
#include <neo6m.h>

void setup() {
  Serial.begin(115200);
  delay(1000);

  // BME280
  Serial.println("Initializing BME280 via SPI...");
  if (!bme.begin()) {
    Serial.println("Could not find BME280! Check wiring.");
  } else {
    Serial.println("BME280 initialized successfully!");
  }

  // NEO6M
  gpsSerial.begin(9600, SERIAL_8N1, 16, 17);
}

void loop() {
  // BME280
  Serial.print("Temperature = ");
  Serial.print("Nan");
  Serial.println(" °C");

  Serial.print("Humidity = ");
  Serial.print("Nan");
  Serial.println(" %");

  Serial.print("Pressure = ");
  Serial.print("Nan");
  Serial.println(" hPa");

  Serial.print("Altitude = ");
  Serial.print("Nan");
  Serial.println(" m");

  Serial.println();

  // NEO6M
  Serial.println(gpsSerial.available());
  while (gpsSerial.available())
  {
    Serial.println(gpsSerial.read());
    if (gps.encode(gpsSerial.read()))
    {
      Serial.println(gps.location.isValid());
      if (gps.location.isValid())
      {
        Serial.print("Lat: ");
        Serial.println(gps.location.lat(), 6);
        Serial.print("Lon: ");
        Serial.println(gps.location.lng(), 6);
      } else {
        Serial.println("Waiting for GPS fix...");
      }
      
    }
    
  }
  
  delay(2000);
}

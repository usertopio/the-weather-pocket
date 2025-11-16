#include <TinyGPSPlus.h>
#include <Arduino.h>

TinyGPSPlus gps;
HardwareSerial GPSModule(1); // UART1

#define GPS_RX 20
#define GPS_TX 21
#define GPS_BAUD 9600

// --- Move this above loop() ---
void displayLocationInfo() {
  Serial.println(F("-------------------------------------"));
  Serial.println("Location Info:");

  Serial.print("Latitude:  ");
  Serial.print(gps.location.lat(), 6);
  Serial.print(" ");
  Serial.println(gps.location.rawLat().negative ? "S" : "N");

  Serial.print("Longitude: ");
  Serial.print(gps.location.lng(), 6);
  Serial.print(" ");
  Serial.println(gps.location.rawLng().negative ? "W" : "E");

  Serial.print("Fix Quality: ");
  Serial.println(gps.location.isValid() ? "Valid" : "Invalid");

  Serial.print("Satellites: ");
  Serial.println(gps.satellites.value());

  Serial.print("Altitude:   ");
  Serial.print(gps.altitude.meters());
  Serial.println(" m");

  Serial.print("Speed:      ");
  Serial.print(gps.speed.kmph());
  Serial.println(" km/h");

  Serial.print("Course:     ");
  Serial.print(gps.course.deg());
  Serial.println("°");

  Serial.print("Date:       ");
  if (gps.date.isValid()) {
    Serial.printf("%02d/%02d/%04d\n", gps.date.day(), gps.date.month(), gps.date.year());
  } else {
    Serial.println("Invalid");
  }

  Serial.print("Time (UTC): ");
  if (gps.time.isValid()) {
    Serial.printf("%02d:%02d:%02d\n", gps.time.hour(), gps.time.minute(), gps.time.second());
  } else {
    Serial.println("Invalid");
  }

  Serial.println(F("-------------------------------------\n"));
}

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("Waiting for GPS fix and satellites...");
  GPSModule.begin(GPS_BAUD, SERIAL_8N1, GPS_RX, GPS_TX);
}

void loop() {
  while (GPSModule.available() > 0) {
    char c = GPSModule.read();
    Serial.write(c);  // Optional: see raw NMEA sentences
    gps.encode(c);
  }

  static unsigned long lastPrint = 0;
  if (millis() - lastPrint > 1000) {
    lastPrint = millis();
    displayLocationInfo(); // now compiler knows about it
  }

  if (millis() > 5000 && gps.charsProcessed() < 10) {
    Serial.println(F("Warning: No GPS detected. Check wiring and power."));
  }
}

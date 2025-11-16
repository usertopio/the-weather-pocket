#include <Arduino.h>

#define LED_PIN 8

void setup(){
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, HIGH);
}

void loop(){
  digitalWrite(LED_PIN, LOW);  // LED ON
  Serial.println("On");
  delay(1000);

  digitalWrite(LED_PIN, HIGH); // LED OFF
  Serial.println("Off");
  delay(1000);
}
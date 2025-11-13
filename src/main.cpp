#include <Arduino.h>

const int ledPin = 8; 

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  digitalWrite(ledPin, HIGH); 
  Serial.println("LED OFF");
  delay(1000);                     
  digitalWrite(ledPin, LOW); 
  Serial.println("LED ON");  
  delay(1000);                     
}
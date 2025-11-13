#ifndef BME280_H
#define BME280_H

// Libraries
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

extern Adafruit_BME280 bme;

#endif
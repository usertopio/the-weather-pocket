#ifndef BME280_H
#define BME280_H

// Libraries
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

// Define variables
// Pinouts
#define BME_SCK  18 //SCL
#define BME_MISO 19 //SDA
#define BME_MOSI 23 //SDO
#define BME_CS   5 //CSB

// Data
#define SEA_LEVEL_PRESSURE_HPA 1010

// Declare variables
// Sensor object
extern Adafruit_BME280 bme;

#endif
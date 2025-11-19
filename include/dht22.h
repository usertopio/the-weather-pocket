#ifndef DHT22_H
#define DHT22_H

// Libraries
#include <DHT.h>
#include <Wire.h>

// Header files
#include <sensor.h>

class DHT22 : public Sensor {
    private:
        const int DHT22_PIN;
    public:
        DHT22(int dht22_pin);
        void begin() override;
};

#endif
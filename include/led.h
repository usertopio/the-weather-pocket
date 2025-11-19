#ifndef LED_H
#define LED_H

// Libraries
#include <Arduino.h>

// Header files
#include <sensor.h>

class LED : public Sensor {
    private:
        const int LED_PIN;
    public:
        LED(int led_pin);
        void begin() override;
};

#endif
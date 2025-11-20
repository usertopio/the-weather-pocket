#ifndef DHT22_H
#define DHT22_H

// Libraries
#include <DHT.h>
#include <Wire.h>

// Header files
#include <sensor.h>

class DHT22 : public Sensor {
    // Constructor
    public:
        // Methods
        DHT22(int dht22_pin, int dht_type);

    // Initialization
    public:
        // Methods
        void begin() override;

    // Pins
    private:
        // Variables
        const int DHT22_PIN;

    // State
    protected:
        // Variables
        enum class State {
            INIT,
            MEASURE_TEMPERATURE,
            MEASURE_HUMIDITY
        };
  
        State state;
    public:
        // Methods
        State getState() const;
    
    // Data
    private:
        // Variables
        // Library constants
        const int DHT_TYPE;
        DHT dht;
};

#endif
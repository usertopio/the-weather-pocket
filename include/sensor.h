#ifndef SENSOR_H
#define SENSOR_H

class Sensor {
    // Initialization
    public:
        // Methods
        virtual void begin() = 0;

    // Status
    public:
        // Variables
        enum class Status {
            ON,
            OFF
        };

        // Methods
        Status getStatus() const;
    
    protected:
        // Variables
        Status status;
};

#endif
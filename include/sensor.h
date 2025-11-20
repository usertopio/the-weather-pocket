#ifndef SENSOR_H
#define SENSOR_H

class Sensor {
    public:
        // Variables
        // Status  
        enum class Status {
            ON,
            OFF
        };

        // Method
        virtual void begin() = 0;
        // Status
        Status getStatus() const;
    protected:
        // Variables
        // Status  
        Status status;
};

#endif
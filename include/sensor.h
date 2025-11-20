#ifndef SENSOR_H
#define SENSOR_H

class Sensor {
    // Constructor
    public:
        Sensor();
        virtual ~Sensor() = default;

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
        Status toggleStatus();
    
    protected:
        // Variables
        Status status;
};

#endif
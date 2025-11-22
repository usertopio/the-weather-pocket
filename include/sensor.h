#ifndef SENSOR_H
#define SENSOR_H

class Sensor {
    public:
        // Constructor
        Sensor();
        virtual ~Sensor() = default;

        // Status
        enum class Status {
            ON,
            OFF
        };

        //  Initialization
        virtual void begin() = 0;

        // Status
        Status getStatus() const;
        Status toggleStatus();

    protected:
        // Status
        Status status;
};

#endif
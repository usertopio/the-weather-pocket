// Header files
#include "sensor.h"

// Constructor
Sensor::Sensor() : status(Status::OFF) {}

// Status
Sensor::Status Sensor::getStatus() const {
    return status;
}

Sensor::Status Sensor::toggleStatus() {
    if (status == Sensor::Status::OFF)
    {
        status == Sensor::Status::ON;
    }
    else
    {
        status == Sensor::Status::OFF;
    }    
}

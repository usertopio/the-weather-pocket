// Header files
#include "sensor.h"

// Constructor
Sensor::Sensor() : 
    status(Status::ON)
{}

// Status
Sensor::Status Sensor::getStatus() const {
    return status;
}

Sensor::Status Sensor::toggleStatus() {
    if (status == Status::OFF) {
        status = Status::ON;
    } else {
        status = Status::OFF;
    }
    return status;
}

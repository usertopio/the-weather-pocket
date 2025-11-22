// Header files
#include "component.h"

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

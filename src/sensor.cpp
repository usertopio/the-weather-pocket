// Header files
#include "sensor.h"

// Constructor
Sensor::Sensor() : status(Status::OFF) {}

// Status
Sensor::Status Sensor::getStatus() const {
    return status;
}
// Header files
// Parent components
#include "component.h"

// Constructor
Component::Component() : 
    status(Status::ON)
{}

// Status
Component::Status Component::getStatus() const {
    return status;
}

Component::Status Component::toggleStatus() {
    if (status == Status::OFF) {
        status = Status::ON;
    } else {
        status = Status::OFF;
    }
    return status;
}

const char* Component::statusToStr(Status status) const {
    switch (status) {
        case Status::ON:  return "ON";
        case Status::OFF: return "OFF";
        default: return "UNKNOWN";
    }
}

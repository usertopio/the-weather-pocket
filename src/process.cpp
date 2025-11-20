// Header files
#include "process.h"

// Constructor
Process::Process(): 
    // State
    state(State::INIT)
{}

// Initialization
void Process::begin() {
}

// State
Process::State Process::getState() const {
    return state;
}
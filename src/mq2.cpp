// Framework
#include <Arduino.h>

// Header files
// Child components
#include "mq2.h"

// Constructor
Mq2::Mq2(int data_pin) :
    // Pins
    DATA_PIN(data_pin),
    // State
    state(State::INIT)
{}

// Initialization
void Mq2::begin() {
    // State
    status = Status::ON;
}

// Status
const char* mq2StatusToString(Mq2::Status status) {
    switch (status) {
        case Mq2::Status::ON:  return "ON";
        case Mq2::Status::OFF: return "OFF";
        default: return "UNKNOWN";
    }
}

const char* mq2LpgStatusToStr(Mq2::LpgStatus lpgStatus) {
    switch (lpgStatus) {
        case Mq2::LpgStatus::NORMAL:  return "NORMAL";
        case Mq2::LpgStatus::WARNING: return "WARNING";
        case Mq2::LpgStatus::DANGER: return "DANGER";
        default: return "UNKNOWN";
    }
}

const char* mq2CoStatusToStr(Mq2::CoStatus coStatus) {
    switch (coStatus) {
        case Mq2::CoStatus::NORMAL:  return "NORMAL";
        case Mq2::CoStatus::WARNING: return "WARNING";
        case Mq2::CoStatus::DANGER: return "DANGER";
        case Mq2::CoStatus::SEVERE: return "SEVERE";
        default: return "UNKNOWN";
    }
}

const char* mq2SmokeStatusToStr(Mq2::SmokeStatus smokeStatus) {
    switch (smokeStatus) {
        case Mq2::SmokeStatus::NORMAL:  return "NORMAL";
        case Mq2::SmokeStatus::WARNING: return "WARNING";
        case Mq2::SmokeStatus::DANGER: return "DANGER";
        default: return "UNKNOWN";
    }
}

// State
Mq2::State Mq2::getState() const {
    return state;
}

Mq2::LpgStatus Mq2::getLpgStatus() const {
    return lpgStatus;
}

Mq2::CoStatus Mq2::getCoStatus() const {
    return coStatus;
}

Mq2::SmokeStatus Mq2::getSmokeStatus() const {
    return smokeStatus;
}

void Mq2::setState(State newState) {
    state = newState;
}

void Mq2::setLpgStatus(LpgStatus newLpgStatus) {
    lpgStatus = newLpgStatus;
}

void Mq2::setCoStatus(CoStatus newCoStatus) {
    coStatus = newCoStatus;
}

void Mq2::setSmokeStatus(SmokeStatus newSmokeStatus) {
    smokeStatus = newSmokeStatus;
}

const char* mq2StateToString(Mq2::State state) {
    switch (state) {
        case Mq2::State::INIT: return "INIT";
        case Mq2::State::READ: return "READ";
        case Mq2::State::FAIL: return "FAIL";
        default: return "RUN_OUT_OF_STATE";
    }
}

void Mq2::readRaw() {
    raw = analogRead(DATA_PIN);

    // Update state
    setState(State::READ);
}

// Generic formula for gas estimation
float Mq2::calculatePPM(float ratio, float a, float b) {
    // ppm = a * (ratio ^ b)
    return a * pow(ratio, b);
}

void Mq2::readLPG() {
    readRaw();
    ratio = raw / 1023.0;   // simple scaling

    lpg_ppm = calculatePPM(ratio, 1000, -2.0);

    if (lpg_ppm <= 300){
        setLpgStatus(LpgStatus::NORMAL);
    } else if (lpg_ppm > 300 && lpg_ppm <= 1000){
        setLpgStatus(LpgStatus::WARNING);
    } else if (lpg_ppm > 1000){
        setLpgStatus(LpgStatus::DANGER);
    }

    // Update state
    setState(State::READ);
}

void Mq2::readCO() {
    readRaw();
    ratio = raw / 1023.0;

    co_ppm = calculatePPM(ratio, 50, -1.5);

    if (co_ppm <= 9){
        setCoStatus(CoStatus::NORMAL);
    } else if (co_ppm > 9 && co_ppm <= 50){
        setCoStatus(CoStatus::WARNING);
    } else if (co_ppm > 50 && co_ppm <= 200){
        setCoStatus(CoStatus::DANGER);
    } else if (co_ppm > 200){
        setCoStatus(CoStatus::SEVERE);
    }

    // Update state
    setState(State::READ);
}

void Mq2::readSmoke() {
    readRaw();
    ratio = raw / 1023.0;

    smoke_ppm = calculatePPM(ratio, 200, -1.7);

    if (smoke_ppm <= 100){
        setSmokeStatus(SmokeStatus::NORMAL);
    } else if (smoke_ppm > 100 && smoke_ppm <= 300){
        setSmokeStatus(SmokeStatus::WARNING);
    } else if (smoke_ppm > 300){
        setSmokeStatus(SmokeStatus::DANGER);
    }

    // Update state
    setState(State::READ);
}

// Get data
float Mq2::getRaw(){
    return raw;
}

float Mq2::getLPG(){
    return lpg_ppm;
}

float Mq2::getCO(){
    return co_ppm;
}

float Mq2::getSmoke(){
    return smoke_ppm;
}
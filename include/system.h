#ifndef SYSTEM_H
#define SYSTEM_H

enum class SystemState {
    INIT,
    MEASURE_WEATHER,
    MEASURE_GPS,
    PROCESS_DATA,
    UPLOAD_DATA
};

extern SystemState systemState;

#endif
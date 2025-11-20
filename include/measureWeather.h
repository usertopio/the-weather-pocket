#ifndef MEASUREWEATHER_H
#define MEASUREWEATHER_H

enum class MeasureWeatherState {
    ALL_DOWN,
    ONLY_DHT22,
    ONLY_MQ2,
    ALL_UP
};

extern MeasureWeatherState measureWeatherState;

#endif
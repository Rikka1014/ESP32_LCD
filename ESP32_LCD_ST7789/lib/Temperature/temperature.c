//
// Created by Yuta on 2025/8/16.
//

#include "temperature.h"

#include <Arduino.h>

TEMPERATURE g_temperature = {
    .t = 0.0f,
    .t_set = 30.0f,
    .t_set_low = 25.5f,  // 低温设定值
    .t_set_high = 35.5f, // 高温设定值
};

float get_temperature() {
    return g_temperature.t;
}

void set_temperature(float t) {
    g_temperature.t = t;
}

float get_humidity() {
    return g_temperature.humidity;
}

void set_humidity(float h) {
    g_temperature.humidity = h;
}

float get_temperature_set() {
    return g_temperature.t_set;
}
float get_temperature_set_low() {
    return g_temperature.t_set_low;
}
float get_temperature_set_high() {
    return g_temperature.t_set_high;
}

void set_temperature_set(float t) {
    g_temperature.t_set = t;
}
void set_temperature_set_low(float t) {
    g_temperature.t_set_low = constrain(t, T_SET_LOW_MIN, g_temperature.t_set_high - 0.5f);
}
void set_temperature_set_high(float t) {
    g_temperature.t_set_high = constrain(t, g_temperature.t_set_low + 0.5f, T_SET_HIGH_MAX)    ;
}

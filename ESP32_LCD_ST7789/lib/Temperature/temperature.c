//
// Created by Yuta on 2025/8/16.
//

#include "temperature.h"

TEMPERATURE g_temperature = {
    .t = 0.0f,
    .t_set = 30.0f,
    .t_set_low = 25.0f,  // 低温设定值
    .t_set_high = 35.0f, // 高温设定值
};

float get_temperature() {
    return g_temperature.t;
}

void set_temperature(float t) {
    g_temperature.t = t;
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
    g_temperature.t_set_low = t;
}
void set_temperature_set_high(float t) {
    g_temperature.t_set_high = t;
}

//
// Created by Yuta on 2025/8/16.
//

#include "temperature.h"

TEMPERATURE g_temperature = {
    .t = 0.0f,
    .t_set = 37.0f
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

void set_temperature_set(float t) {
    g_temperature.t_set = t;
}

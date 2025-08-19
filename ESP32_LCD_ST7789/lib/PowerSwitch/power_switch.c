//
// Created by Yuta on 2025/8/19.
//
#include <Arduino.h>
#include "power_switch.h"

void power_switch_init(void) {
    pinMode(MASTER_SWITCH_PIN, OUTPUT);
    pinMode(OUT0_12V_SWITCH_PIN, OUTPUT);
    pinMode(OUT1_12V_SWITCH_PIN, OUTPUT);

    digitalWrite(MASTER_SWITCH_PIN, LOW);
    digitalWrite(OUT0_12V_SWITCH_PIN, LOW);
    digitalWrite(OUT1_12V_SWITCH_PIN, LOW);
}

void power_switch_set_master(bool on) {
    if (on) {
        digitalWrite(MASTER_SWITCH_PIN, HIGH); // 打开主电源开关
    } else {
        digitalWrite(MASTER_SWITCH_PIN, LOW); // 关闭主电源开关
    }

}

void power_switch_set_out0_12v(bool on) {
    if (on) {
        digitalWrite(OUT0_12V_SWITCH_PIN, HIGH); // 打开OUT0 12V输出
    } else {
        digitalWrite(OUT0_12V_SWITCH_PIN, LOW); // 关闭OUT0 12V输出
    }
}

void power_switch_set_out1_12v(bool on) {
    if (on) {
        digitalWrite(OUT1_12V_SWITCH_PIN, HIGH); // 打开OUT1 12V输出
    } else {
        digitalWrite(OUT1_12V_SWITCH_PIN, LOW); // 关闭OUT1 12V输出
    }
}
//
// Created by Yuta on 2025/8/19.
//
#include <Arduino.h>
#include "power_switch.h"

void power_switch_init(void) {
    pinMode(CONFIG_MASTER_SWITCH_PIN, OUTPUT);
    pinMode(CONFIG_12V_OUT2_PIN, OUTPUT);

    digitalWrite(CONFIG_MASTER_SWITCH_PIN, LOW);   // 关闭主电源开关
    digitalWrite(CONFIG_12V_OUT2_PIN, LOW); // 关闭OUT1 12V输出

    // out1 PWM初始化
    ledcSetup(CONFIG_12V_OUT1_PWM_CHANNEL, 100, 10); // 设置PWM频率为100Hz，分辨率为8位
    ledcAttachPin(CONFIG_12V_OUT1_PIN, CONFIG_12V_OUT1_PWM_CHANNEL); // 将PWM通道附加到引脚
    ledcWrite(CONFIG_12V_OUT1_PWM_CHANNEL, 0); // 初始占空比为0，关闭输出
}

void power_switch_set_master(bool on) {
    if (on) {
        digitalWrite(CONFIG_MASTER_SWITCH_PIN, HIGH); // 打开主电源开关
    } else {
        digitalWrite(CONFIG_MASTER_SWITCH_PIN, LOW); // 关闭主电源开关
    }

}

void power_switch_set_out1_pwm(uint8_t percent) {
    if (percent > 100) percent = 100;
    const uint32_t duty = (percent * 1023) / 100; // 计算占空比，10位分辨率
    ledcWrite(CONFIG_12V_OUT1_PWM_CHANNEL, duty);
}

void power_switch_set_out2(bool on) {
    if (on) {
        digitalWrite(CONFIG_12V_OUT2_PIN, HIGH); // 打开OUT1 12V输出
    } else {
        digitalWrite(CONFIG_12V_OUT2_PIN, LOW); // 关闭OUT1 12V输出
    }
}
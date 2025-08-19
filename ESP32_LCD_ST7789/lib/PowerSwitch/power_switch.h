//
// Created by Yuta on 2025/8/19.
//

#ifndef ESP32_LCD_ST7789_POWER_SWITCH_H
#define ESP32_LCD_ST7789_POWER_SWITCH_H

#ifdef __cplusplus
extern "C" {
#endif

#define MASTER_SWITCH_PIN    16 // 电源开关引脚
#define OUT0_12V_SWITCH_PIN 17 // 12V输出开关引脚
#define OUT1_12V_SWITCH_PIN 18 // 12V输出开关引脚

void power_switch_init(void);
void power_switch_set_master(bool on);
void power_switch_set_out0_12v(bool on);
void power_switch_set_out1_12v(bool on);

#ifdef __cplusplus
}
#endif

#endif //ESP32_LCD_ST7789_POWER_SWITCH_H
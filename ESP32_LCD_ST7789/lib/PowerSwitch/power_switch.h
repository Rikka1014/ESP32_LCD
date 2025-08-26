//
// Created by Yuta on 2025/8/19.
//

#ifndef ESP32_LCD_ST7789_POWER_SWITCH_H
#define ESP32_LCD_ST7789_POWER_SWITCH_H

#ifdef __cplusplus
extern "C" {
#endif

#define CONFIG_MASTER_SWITCH_PIN    16  // 主电源开关引脚
#define CONFIG_12V_OUT1_PIN         18  // 12V输出1开关引脚
#define CONFIG_12V_OUT2_PIN         17  // 12V输出2开关引脚
#define CONFIG_12V_OUT1_PWM_CHANNEL     3 // 12V输出1 PWM通道


void power_switch_init(void);
void power_switch_set_master(bool on);
void power_switch_set_out1_pwm(uint8_t percent);
void power_switch_set_out2(bool on);

#ifdef __cplusplus
}
#endif

#endif //ESP32_LCD_ST7789_POWER_SWITCH_H
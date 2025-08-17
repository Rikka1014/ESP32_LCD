//
// Created by Yuta on 2025/8/16.
//

#ifndef ESP32_LCD_ST7789_TEMPERATURE_H
#define ESP32_LCD_ST7789_TEMPERATURE_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    float t;
    float t_set;
} TEMPERATURE;

extern TEMPERATURE g_temperature;

float get_temperature();        // 获取当前温度
void set_temperature(float t);  // 设置当前温度
float get_temperature_set();    // 获取设定温度
void set_temperature_set(float t);  // 设置设定温度


#ifdef __cplusplus
}
#endif

#endif //ESP32_LCD_ST7789_TEMPERATURE_H
//
// Created by Yuta on 2025/8/16.
//

#ifndef ESP32_LCD_ST7789_TEMPERATURE_H
#define ESP32_LCD_ST7789_TEMPERATURE_H

#ifdef __cplusplus
extern "C" {
#endif

#define T_SET_LOW_MIN -10.0f  // 低温设定值最小值
#define T_SET_HIGH_MAX 100.0f // 高温设定值最大值

typedef struct {
    float t;
    float t_set_low;  // 低温设定值
    float t_set_high; // 高温设定值
    float t_set;      // 当前设定温度
    float humidity;   // 当前湿度
} TEMPERATURE;

extern TEMPERATURE g_temperature;

float get_temperature();        // 获取当前温度
void set_temperature(float t);  // 设置当前温度
float get_humidity();
void set_humidity(float h);

float get_temperature_set();    // 获取设定温度
float get_temperature_set_low();
float get_temperature_set_high();
void set_temperature_set(float t);  // 设置设定温度
void set_temperature_set_low(float t);
void set_temperature_set_high(float t);


#ifdef __cplusplus
}
#endif

#endif //ESP32_LCD_ST7789_TEMPERATURE_H
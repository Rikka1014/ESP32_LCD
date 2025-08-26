//
// Created by Yuta on 2025/8/17.
//

#ifndef ESP32_LCD_ST7789_TEMPERATURE_SENSOR_H
#define ESP32_LCD_ST7789_TEMPERATURE_SENSOR_H
#include <Arduino.h>

#ifdef __cplusplus
extern "C" {
#endif

#define DS18B20_PIN 11
#define SHT40_SCL_PIN 19
#define SHT40_SDA_PIN 45

#define USE_SENSOR_DS18B20  1   // 使用DS18B20传感器
#define USE_SENSOR_SHT40    0   // 使用SHT40传感器

void temperature_sensor_init(void);
bool temperature_sensor_read_loop(float *t, float *h);

#ifdef __cplusplus
}
#endif

#endif //ESP32_LCD_ST7789_TEMPERATURE_SENSOR_H
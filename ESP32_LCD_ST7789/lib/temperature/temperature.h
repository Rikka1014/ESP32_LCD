//
// Created by Yuta on 2025/8/16.
//

#ifndef ESP32_LCD_ST7789_TEMPERATURE_H
#define ESP32_LCD_ST7789_TEMPERATURE_H

typedef struct {
    float t;
    float t_set;
} TEMPERATURE;

extern TEMPERATURE g_temperature;

float get_temperature();
void set_temperature(float t);
float get_temperature_set();
void set_temperature_set(float t);


#endif //ESP32_LCD_ST7789_TEMPERATURE_H
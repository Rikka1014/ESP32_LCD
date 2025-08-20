//
// Created by Yuta on 2025/7/31.
//

#ifndef ESP32_LCD_ST7789_MY_UI_H
#define ESP32_LCD_ST7789_MY_UI_H

typedef enum {
    DEVICE_STATE_NORMAL = 0,
    DEVICE_STATE_HEAT,
    DEVICE_STATE_COOL,
    DEVICE_STATE_NULL
} device_state_t;

void my_ui_init();
void my_ui_update();

void my_ui_update_temperature(float temperature);
void my_ui_update_humidity(float humidity);
void my_ui_update_devive_state(device_state_t state);

#endif //ESP32_LCD_ST7789_MY_UI_H

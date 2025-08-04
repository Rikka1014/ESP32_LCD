//
// Created by Yuta on 2025/7/31.
//

#ifndef ESP32_LCD_ST7789_MY_UI_H
#define ESP32_LCD_ST7789_MY_UI_H

void my_ui_init();
void my_ui_update();
void my_ui_set_PC_status(const float cpu, const float gpu, const float ram, float fan);

#endif //ESP32_LCD_ST7789_MY_UI_H

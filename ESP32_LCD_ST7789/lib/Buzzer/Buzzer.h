//
// Created by Yuta on 2025/8/25.
//

#ifndef ESP32_LCD_ST7789_BUZZER_H
#define ESP32_LCD_ST7789_BUZZER_H

#include <Arduino.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Buzzer */
#define CONFIG_BUZZ_PIN             12
#define CONFIG_BUZZ_CHANNEL         2


void Buzzer_Init(void);
void Buzzer_SetEnable(bool en);
void Buzzer_Tone(uint32_t freq, int32_t duration);




#ifdef __cplusplus
}
#endif

#endif //ESP32_LCD_ST7789_BUZZER_H
//
// Created by Rikka on 2025/8/5.
//

#ifndef KEY_H
#define KEY_H

#include <stdint.h>
#include <stdbool.h>

extern volatile uint32_t g_last_key;
extern volatile bool g_key_pressed;

void keypad_init(void);
void key_serial_receive(HardwareSerial &serial);

#endif //KEY_H

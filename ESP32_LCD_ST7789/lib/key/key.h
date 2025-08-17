//
// Created by Rikka on 2025/8/5.
//

#ifndef KEY_H
#define KEY_H

#include <Arduino.h>

#ifdef __cplusplus
extern "C" {
#endif


void keypad_init(void);
void key_serial_receive_loop(HardwareSerial &serial);

#ifdef __cplusplus
}
#endif

#endif //KEY_H

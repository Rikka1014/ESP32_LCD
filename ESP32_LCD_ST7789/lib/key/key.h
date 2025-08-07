//
// Created by Rikka on 2025/8/5.
//

#ifndef KEY_H
#define KEY_H

#include <stdint.h>
#include <stdbool.h>


void keypad_init(void);
void key_serial_receive_loop(HardwareSerial &serial);

#endif //KEY_H

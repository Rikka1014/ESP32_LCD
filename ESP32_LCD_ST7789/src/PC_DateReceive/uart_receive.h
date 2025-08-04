//
// Created by Rikka on 2025/8/4.
//

#ifndef UART_RECEIVE_H
#define UART_RECEIVE_H

#include <Arduino.h>
#include <ArduinoJson.h>

struct SystemStats {
    float cpu;
    float gpu;
    float ram;
    float fan;
};

class ESP32Receiver {
public:
    ESP32Receiver(HardwareSerial &serialPort = Serial);
    // 初始化串口
    void begin(unsigned long baudRate = 115200);
    // 每次循环调用累积串口接收数据
    void update();
    // 尝试解析累积的数据，若成功返回 true 并填充 stats
    bool tryParseStats(SystemStats &stats);

private:
    HardwareSerial &serial;
    String buffer;
};

#endif //UART_RECEIVE_H

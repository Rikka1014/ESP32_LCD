//
// Created by Rikka on 2025/8/4.
//

#include "uart_receive.h"

// #include "gui_guider.h"

ESP32Receiver::ESP32Receiver(HardwareSerial &serialPort) : serial(serialPort) {}

void ESP32Receiver::begin(unsigned long baudRate) {
    serial.begin(baudRate);
    while (!serial) {
        ; // 等待串口初始化完成
    }
}

void ESP32Receiver::update() {
    while (serial.available()) {
        char ch = serial.read();
        buffer += ch;
        // 若检测到数据包结束标志 '}'，退出读取
        if (ch == '}') break;
    }
}
 
// extern lv_ui tft_ui;
bool ESP32Receiver::tryParseStats(SystemStats &stats) {
    // 检查是否存在完整的 JSON 数据包
    int endIndex = buffer.indexOf('}');
    if (endIndex == -1) return false;

    // 提取完整 JSON 数据包
    String jsonData = buffer.substring(0, endIndex + 1);
    // 从缓冲区删除已解析部分
    buffer = buffer.substring(endIndex + 1);

    StaticJsonDocument<200> doc;
    DeserializationError err = deserializeJson(doc, jsonData);
    // lv_label_set_text(tft_ui.screen_label_log, jsonData.c_str()); // 显示原始数据
    if (err) {
        return false;
    }
    stats.cpu = doc["cpu"].as<float>();
    stats.gpu = doc["gpu"].as<float>();
    stats.ram = doc["ram"].as<float>();
    stats.fan = doc["fan"].as<float>();
    return true;
}
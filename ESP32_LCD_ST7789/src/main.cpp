#include <Arduino.h>

#include "gui_guider.h"
#include "my_ui/my_ui.h"
#include "PC_DateReceive/uart_receive.h"

ESP32Receiver receiver(Serial); // 使用默认的 Serial 端口
SystemStats stats;  // 用于存储接收到的系统状态数据

void setup() {
    Serial.begin(115200);
    pinMode(9, INPUT_PULLUP);
    digitalWrite(9, HIGH);
    my_ui_init();
}

void loop() {
    my_ui_update();

    // key_serial_receive(Serial);

    // // 累积串口数据（非阻塞）
    // receiver.update();
    // // 尝试非阻塞解析
    // if (receiver.tryParseStats(stats)) {
    //     Serial.print("CPU: ");
    //     Serial.print(stats.cpu);
    //     Serial.print("%, GPU: ");
    //     Serial.print(stats.gpu);
    //     Serial.print("%, RAM: ");
    //     Serial.print(stats.ram);
    //     Serial.println("MB");
    //
    //     my_ui_set_PC_status(stats.cpu, stats.gpu, stats.ram, stats.fan);   // 更新 UI 显示
    // }
}

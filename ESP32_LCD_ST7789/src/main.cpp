#include <Arduino.h>
#include <FreeRTOS.h>
// #include <Task.h>

#include "my_ui/my_ui.h"
#include "key.h"
#include "temperature.h"
#include "temperature_sensor.h"
#include "power_switch.h"

#define UI_TASK_STACK_SIZE 8192
#define UI_TASK_PRIORITY   5
TaskHandle_t ui_task_handle = nullptr;
void ui_task(void *pvParameters) {
    (void) pvParameters;

    vTaskDelay(pdMS_TO_TICKS(100)); // 等待系统稳定
    // 初始化ui
    Serial.println("UI init start");
    my_ui_init();
    Serial.println("UI initialized");

    while (true) {
        my_ui_update();     // 更新UI
        vTaskDelay(pdMS_TO_TICKS(10)); // 每10毫秒更新一次UI
    }
}

// 温度任务相关定义
#define TEMPERATURE_STACK_SIZE      8192
#define TEMPERATURE_TASK_PRIORITY   3
TaskHandle_t temperature_task_handle = nullptr;

void temperature_task(void *pvParameters) {
    (void) pvParameters;

    static float T_prev = 0.0f; // 上一次读取的温度值

    vTaskDelay(pdMS_TO_TICKS(500)); // 等待UI初始化完成
    // 初始化温度传感器
    Serial.println("temperature initialized");
    temperature_sensor_init();

    while (true) {
        float T_read;
        bool ret = temperature_sensor_read_loop(&T_read);
        if (ret) {
            // 更新当前温度
            set_temperature(T_read);
            // 如果温度变化超过0.2度，则更新UI显示
            if (abs(get_temperature() - T_prev) > 0.1f)
            {
                T_prev = get_temperature();
                my_ui_update_temperature(get_temperature()); // 更新UI显示的温度
            }

            Serial.printf("Current Temperature: %.2f°C\r\n", get_temperature());
        } else {
            Serial.printf("Failed to read temperature, error val: %.2f°C\r\n", T_read);
        }
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

void setup() {
    Serial.begin(115200);
    // while (!Serial) {}; // 等待串口准备好

    power_switch_init();
    power_switch_set_master(true); // 打开主电源开关
    delay(1000);
    power_switch_set_master(false);
    delay(1000);
    power_switch_set_master(true); // 再次打开主电源开关
    // 创建UI任务
    xTaskCreate(
            ui_task,                // 任务函数
            "UI Task",              // 任务名称
            UI_TASK_STACK_SIZE,     // 堆栈大小
            nullptr,                // 任务参数
            UI_TASK_PRIORITY,       // 任务优先级
            &ui_task_handle         // 任务句柄
    );
    // 创建温度任务
    xTaskCreate(
            temperature_task,           // 任务函数
            "T Task",                   // 任务名称
            TEMPERATURE_STACK_SIZE,     // 堆栈大小
            nullptr,                    // 任务参数
            TEMPERATURE_TASK_PRIORITY,  // 任务优先级
            &temperature_task_handle    // 任务句柄
    );

}

void loop() {

}

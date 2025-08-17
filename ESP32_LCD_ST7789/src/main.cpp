#include <Arduino.h>
#include <FreeRTOS.h>
// #include <Task.h>

#include "my_ui/my_ui.h"
#include "key.h"

#define UI_TASK_STACK_SIZE 8192
#define UI_TASK_PRIORITY   5
TaskHandle_t ui_task_handle = nullptr;
void ui_task(void *pvParameters) {
    (void) pvParameters;

    // 初始化ui
    Serial.println("UI init start");
    vTaskDelay(pdMS_TO_TICKS(100)); // 等待系统稳定
    my_ui_init();
    Serial.println("UI initialized");

    while (true) {
        my_ui_update();     // 更新UI
        vTaskDelay(pdMS_TO_TICKS(10)); // 每10毫秒更新一次UI
    }
}


#define TEMPERATURE_STACK_SIZE      1024
#define TEMPERATURE_TASK_PRIORITY   1
TaskHandle_t temperature_task_handle = nullptr;


void temperature_task(void *pvParameters) {
    (void) pvParameters;

    // 初始化按键
    Serial.println("temperature initialized");

    while (true) {

        vTaskDelay(pdMS_TO_TICKS(50));
    }
}

void setup() {
    Serial.begin(115200);
    // while (!Serial) {}; // 等待串口准备好

    // 创建UI任务
    xTaskCreate(
            ui_task,                // 任务函数
            "UI Task",              // 任务名称
            UI_TASK_STACK_SIZE,     // 堆栈大小
            nullptr,                // 任务参数
            UI_TASK_PRIORITY,       // 任务优先级
            &ui_task_handle         // 任务句柄
    );
    // // 创建按键读取任务
    // xTaskCreate(
    //         key_read_task,          // 任务函数
    //         "Key Read Task",        // 任务名称
    //         KEY_READ_TASK_STACK_SIZE, // 堆栈大小
    //         nullptr,                // 任务参数
    //         KEY_READ_TASK_PRIORITY, // 任务优先级
    //         &key_read_task_handle   // 任务句柄
    // );

}

void loop() {

}

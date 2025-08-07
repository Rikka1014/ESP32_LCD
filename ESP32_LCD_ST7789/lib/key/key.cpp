#include <Arduino.h>
#include <lvgl.h>
#include "key.h"
#include "custom.h"


// 按键读取回调函数（需根据你的硬件实现）
void my_keypad_read(lv_indev_t * indev, lv_indev_data_t * data)
{
    static bool key_pressed = false;
    static int level_pre = HIGH;
    int level = digitalRead(9);

    if (level != level_pre)
    {
        if (level == LOW)
        {
            key_pressed = true;
        } else
        {
            key_pressed = false;
        }
        level_pre = level;
    }

    // if (g_key_pressed) {
    //     data->state = LV_INDEV_STATE_PRESSED;
    //     data->key = g_last_key;
    //     g_key_pressed = false; // 只触发一次
    //     // lv_label_set_text(guider_ui.screen_0_label_log, "LV_INDEV_STATE_PRESSED");
    // }
    // else {
    //     data->state = LV_INDEV_STATE_RELEASED;
    // }
    if (key_pressed)
    {
        data->state = LV_INDEV_STATE_PRESSED;
        data->key = LV_KEY_ENTER;
        key_pressed = false;
        LV_LOG_WARN("PRESSED1");
    }
    else
    {
        data->state = LV_INDEV_STATE_RELEASED;
        LV_LOG_WARN("--RELEASED");
    }
}

void my_button_read(lv_indev_t * indev, lv_indev_data_t * data)
{
    if (g_key_pressed) {
        data->state = LV_INDEV_STATE_PRESSED;
        data->btn_id = g_last_key; // 使用 g_last_key 作为按钮 ID
        g_key_pressed = false; // 只触发一次
    }
    else {
        data->state = LV_INDEV_STATE_RELEASED;
    }
}

void keypad_init(void)
{
    static lv_indev_t * indev;
    indev = lv_indev_create(); // 创建一个输入设备
    lv_indev_set_type(indev, LV_INDEV_TYPE_KEYPAD); // 设置为键盘类型
    lv_indev_set_read_cb(indev, my_keypad_read);    // 设置读取回调函数

    // 设置默认组
    lv_indev_set_group(indev, group0);

}
//
// // 串口接收并解析按键信息（在loop中调用）
// void key_serial_receive(HardwareSerial &serial) {
//
//     while (serial.available()) {
//         char ch = serial.read();
//         if (ch == 'K') {
//             String keyStr = "K";
//             for (int i = 0; i < 15 && serial.available(); ++i) {
//                 char nextCh = serial.read();
//                 if (nextCh == ' ' || nextCh == '\n' || nextCh == '\r') break;
//                 keyStr += nextCh;
//             }
//             if (keyStr == "Key.enter") {
//                 g_last_key = 0;
//                 g_key_pressed = true;
//             } else if (keyStr == "Key.left") {
//                 g_last_key = 0;
//                 g_key_pressed = true;
//             } else if (keyStr == "Key.right") {
//                 g_last_key = 1;
//                 g_key_pressed = true;
//             }
//             // else if (keyStr == "Key.up") {
//             //     g_key_pressed = true;
//             // } else if (keyStr == "Key.down") {
//             //     g_key_pressed = true;
//             // } else if (keyStr == "Key.esc") {
//             //     g_key_pressed = true;
//             // }
//         }
//         // else {
//         //     g_last_key = (uint8_t)ch;
//         //     g_key_pressed = false;
//         // }
//     }
// }

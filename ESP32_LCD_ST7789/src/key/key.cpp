#include <Arduino.h>
#include "key.h"
#include <gui_guider.h>

volatile uint32_t g_last_key = 0;
volatile bool g_key_pressed = false;

// 按键读取回调函数（需根据你的硬件实现）
void my_keypad_read(lv_indev_t * indev, lv_indev_data_t * data)
{
    if (g_key_pressed) {
        data->state = LV_INDEV_STATE_PRESSED;
        data->key = g_last_key;
        g_key_pressed = false; // 只触发一次
        // lv_label_set_text(guider_ui.screen_0_label_log, "LV_INDEV_STATE_PRESSED");
    } else {
        data->state = LV_INDEV_STATE_RELEASED;
    }
}

static lv_group_t * g;
void keypad_init(void)
{
    g = lv_group_create();
    lv_group_set_default(g);

    lv_indev_t * indev = lv_indev_create(); // 创建一个输入设备
    lv_indev_set_type(indev, LV_INDEV_TYPE_KEYPAD); // 设置为键盘类型
    lv_indev_set_read_cb(indev, my_keypad_read);    // 设置读取回调函数

    lv_indev_set_group(indev, g); // 设置默认组
}

// 串口接收并解析按键信息（在loop中调用）
void key_serial_receive(HardwareSerial &serial) {
    while (serial.available()) {
        char ch = serial.read();
        if (ch == 'K') {
            String keyStr = "K";
            for (int i = 0; i < 15 && serial.available(); ++i) {
                char nextCh = serial.read();
                if (nextCh == ' ' || nextCh == '\n' || nextCh == '\r') break;
                keyStr += nextCh;
            }
            // lv_label_set_text(guider_ui.screen_0_label_log, keyStr.c_str());
            if (keyStr == "Key.enter") {
                g_last_key = LV_KEY_ENTER;
                g_key_pressed = true;
                // lv_label_set_text(guider_ui.screen_0_label_log, "LV_KEY_ENTER");
            } else if (keyStr == "Key.left") {
                g_last_key = LV_KEY_LEFT;
                g_key_pressed = true;
                // lv_label_set_text(guider_ui.screen_0_label_log, "LV_KEY_LEFT");
            } else if (keyStr == "Key.right") {
                g_last_key = LV_KEY_RIGHT;
                 g_key_pressed = true;
                ui_load_scr_animation(&guider_ui, &guider_ui.screen_1, guider_ui.screen_1_del, &guider_ui.screen_0_del, setup_scr_screen_1, LV_SCR_LOAD_ANIM_NONE, 200, 200, true, true);
            } else if (keyStr == "Key.up") {
                g_last_key = LV_KEY_UP;
                g_key_pressed = true;
            } else if (keyStr == "Key.down") {
                g_last_key = LV_KEY_DOWN;
                g_key_pressed = true;
            } else if (keyStr == "Key.esc") {
                g_last_key = LV_KEY_ESC;
                g_key_pressed = true;
            }
        }
        // else {
        //     g_last_key = (uint8_t)ch;
        //     g_key_pressed = false;
        // }
    }
}

#include <Arduino.h>
#include <lvgl.h>
#include "key.h"
#include "custom.h"

#define KEYPAD_PIN 15 // 模拟按键输入引脚
#define KEYPAD_PIN_2 7 // 模拟按键输入引脚
// 按键读取回调函数（需根据你的硬件实现）
void my_keypad_read(lv_indev_t * indev, lv_indev_data_t * data)
{

    if (analogRead(KEYPAD_PIN) < 2000)
    {
        data->state = LV_INDEV_STATE_PRESSED;
        data->key = LV_KEY_NEXT; // 这里可以根据实际按键设置不同的 key
    }
    else if (digitalRead(KEYPAD_PIN_2) == LOW)
    {
        data->state = LV_INDEV_STATE_PRESSED;
        data->key = LV_KEY_ENTER;
    }
    else
    {
        data->state = LV_INDEV_STATE_RELEASED;
    }
}

static volatile uint32_t g_last_key = 0;
static volatile bool g_key_pressed = false;
void my_uart_keypad_read(lv_indev_t * indev, lv_indev_data_t * data)
{
    if (g_key_pressed) {
        data->state = LV_INDEV_STATE_PRESSED;
        data->key = g_last_key;     // 使用 g_last_key 作为按钮 ID
        g_key_pressed = false;      // 只触发一次
    }
    else {
        data->state = LV_INDEV_STATE_RELEASED;
    }
}

void keypad_init(void)
{
    pinMode(KEYPAD_PIN, INPUT);
    pinMode(KEYPAD_PIN_2, INPUT); // 设置为上拉输入

    static lv_indev_t * indev;
    indev = lv_indev_create(); // 创建一个输入设备
    lv_indev_set_type(indev, LV_INDEV_TYPE_KEYPAD); // 设置为键盘类型
    lv_indev_set_read_cb(indev, my_keypad_read);    // 设置读取回调函数

    // 将KEYPAD与其要控制的组件添加到同一个组
    lv_indev_set_group(indev, group0);

}

// 串口接收并解析按键信息（在loop中调用）
void key_serial_receive_loop(HardwareSerial &serial) {

    while (serial.available()) {
        char ch = serial.read();
        if (ch == 'K') {
            String keyStr = "K";
            for (int i = 0; i < 15 && serial.available(); ++i) {
                char nextCh = serial.read();
                if (nextCh == ' ' || nextCh == '\n' || nextCh == '\r') break;
                keyStr += nextCh;
            }
            if (keyStr == "Key.enter") {
                g_last_key = LV_KEY_ENTER;
                g_key_pressed = true;
            } else if (keyStr == "Key.left") {
                g_last_key = LV_KEY_LEFT;
                g_key_pressed = true;
            } else if (keyStr == "Key.right") {
                g_last_key = LV_KEY_RIGHT;
                g_key_pressed = true;
            }
            else if (keyStr == "Key.up") {
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
        else
        {
            g_key_pressed = false;
        }
        // else {
        //     g_last_key = (uint8_t)ch;
        //     g_key_pressed = false;
        // }
    }
}

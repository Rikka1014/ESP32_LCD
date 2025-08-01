//
// Created by Yuta on 2025/7/31.
//

#include "my_ui.h"
#include "lvgl.h"
#include <Arduino.h>
#include <Adafruit_ST7789.h>
#include <ui.h>

#define TFT_HOR_RES   240   // 屏幕宽度
#define TFT_VER_RES   240   // 屏幕高度
#define TFT_ROTATION  LV_DISPLAY_ROTATION_180 // 屏幕旋转方向
/*LVGL draw into this buffer, 1/10 screen size usually works well. The size is in bytes*/
#define DRAW_BUF_SIZE (TFT_HOR_RES * TFT_VER_RES / 10 * (LV_COLOR_DEPTH / 8))
uint32_t draw_buf[DRAW_BUF_SIZE / 4];

// 定义引脚
#define TFT_SCLK  10    // SPI时钟引脚
#define TFT_MOSI  11    // SPI数据引脚
#define TFT_RST   12    // 复位引脚
#define TFT_DC    13    // 数据/命令选择引脚
#define TFT_CS    14    // 片选引脚
#define TFT_BL    18    // 背光引脚（如果有接线）

Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);

// LVGL系统时间获取的具体实现
static uint32_t my_tick_get_cb(void) {
    return millis();
}

// 日志打印回调函数的具体实现
void my_print( lv_log_level_t level, const char * buf )
{
    LV_UNUSED(level);
    Serial.println(buf);
    Serial.flush();
}

// LVGL显示刷新回调函数的具体实现
void my_disp_flush( lv_display_t *disp, const lv_area_t *area, uint8_t * px_map)
{
    // 将LVGL渲染的像素数据复制到屏幕
    tft.drawRGBBitmap(
            (int16_t)area->x1,
            (int16_t)area->y1,
            (uint16_t *)px_map, // px_map 是 LV_COLOR_DEPTH=16 时的 RGB565 数据，需转换为 uint16_t*
            (int16_t)lv_area_get_width(area),
            (int16_t)lv_area_get_height(area)
    );
    lv_display_flush_ready(disp);
}

void my_ui_init(void) {
    randomSeed(analogRead(0));  // 初始化随机数种子

    Serial.println("UI init start");
    // 初始化屏幕驱动
    SPI.begin(TFT_SCLK, -1, TFT_MOSI, TFT_CS);
    tft.init(TFT_HOR_RES, TFT_VER_RES); // 分辨率
    tft.setRotation(TFT_ROTATION); // 旋转方向
    // 打开背光（如有接线）
    pinMode(TFT_BL, OUTPUT);
    digitalWrite(TFT_BL, HIGH);
    // 初始化LVGL
    lv_init();
    lv_tick_set_cb(my_tick_get_cb);
#if LV_USE_LOG != 0
    lv_log_register_print_cb(my_print);
#endif
    lv_display_t * disp;
    disp = lv_display_create(TFT_HOR_RES, TFT_VER_RES);
    lv_display_set_rotation(disp, TFT_ROTATION);
    lv_display_set_flush_cb(disp, my_disp_flush);
    lv_display_set_buffers(disp, draw_buf, NULL, sizeof(draw_buf), LV_DISPLAY_RENDER_MODE_PARTIAL);
//    // 初始化输入设备
//    lv_indev_t * indev = lv_indev_create();
//    lv_indev_set_type(indev, LV_INDEV_TYPE_POINTER); /*Touchpad should have POINTER type*/
//    lv_indev_set_read_cb(indev, my_touchpad_read);
    Serial.println("UI initialized 3");
//    // 创建一个简单的标签
//    lv_obj_t *label = lv_label_create(lv_screen_active());
//    lv_label_set_text(label, "Hello Rikka, I'm Yuta!");
//    lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);

    Serial.println("UI initialized");

    ui_init(); // 初始化 SquareLine Studio 生成的 UI
}



void my_ui_update(void) {
    // 更新LVGL
    lv_task_handler();
    delay(5); // 延时以便处理任务
    int i, j= 10;
    i = random(0, 15); // 随机生成一个0-14之间的整数
    j = random(0, 250); // 随机生成一个0-249之间的整数
    ui_Screen1_screen_set_chart_valves(i, j); // 更新屏幕内容



}
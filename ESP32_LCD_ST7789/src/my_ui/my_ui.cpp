//
// Created by Yuta on 2025/7/31.
//

#include "my_ui.h"
#include "lvgl.h"
#include <Arduino.h>
//#include <Adafruit_ST7789.h>
#include <Adafruit_ST7735.h>
// #include <ui.h>
#include <gui_guider.h>
#include <custom.h>
#include <key.h>

#define TFT_HOR_RES   128   // 屏幕宽度
#define TFT_VER_RES   128   // 屏幕高度
#define TFT_ROTATION  LV_DISPLAY_ROTATION_0 // 屏幕旋转方向
/*LVGL draw into this buffer, 1/10 screen size usually works well. The size is in bytes*/
#define DRAW_BUF_SIZE (TFT_HOR_RES * TFT_VER_RES / 10 * (LV_COLOR_DEPTH / 8))
uint32_t draw_buf[DRAW_BUF_SIZE / 4];

// 定义引脚
#define TFT_SCLK  5    // SPI时钟引脚
#define TFT_MOSI  4    // SPI数据引脚
#define TFT_RST   9    // 复位引脚
#define TFT_DC    14    // 数据/命令选择引脚
#define TFT_CS    10    // 片选引脚
#define TFT_BL    13    // 背光引脚（如果有接线）

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

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
    // 打开屏幕背光
    pinMode(TFT_BL, OUTPUT);
    digitalWrite(TFT_BL, LOW);
    // 初始化屏幕驱动
    SPI.begin(TFT_SCLK, -1, TFT_MOSI, TFT_CS);
    vTaskDelay(pdMS_TO_TICKS(50)); // 等待SPI初始化完成
//    tft.init(TFT_HOR_RES, TFT_VER_RES); // 分辨率
    tft.initR(); // 分辨率
    tft.setRotation(TFT_ROTATION); // 旋转方向


    // // 测试屏幕使用
    // tft.fillScreen(ST77XX_GREEN);   //
    // tft.drawChar(25, 15, 'O', ST77XX_WHITE, ST77XX_WHITE, 1);
    // tft.drawChar(35, 15, 'K', ST77XX_WHITE, ST77XX_WHITE, 1);
    // tft.drawChar(45, 15, '!', ST77XX_BLUE, ST77XX_RED, 1);
    // Serial.println("ST7735 initialized OK!");

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


    custom_init(&guider_ui);
    setup_ui(&guider_ui); // 初始化 GUI Guider 生成的 UI
//    keypad_init();
}


void my_ui_update(void) {
    // 更新LVGL
    lv_task_handler();
}



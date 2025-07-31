// 引脚定义（请根据实际接线修改）
// TFT_CS   -> 5
// TFT_RST  -> 18
// TFT_DC   -> 19
// TFT_MOSI -> 23
// TFT_SCLK -> 18
// TFT_BL   -> 21 (可选，背光控制)

#include <Arduino.h>
#include <Adafruit_ST7789.h>
#include <SPI.h>

// 定义引脚
#define TFT_SCLK  10
#define TFT_MOSI  11
#define TFT_RST   12
#define TFT_DC    13
#define TFT_CS    14
#define TFT_BL    18

Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);

void setup() {
    Serial.begin(115200);
    // 初始化SPI
    SPI.begin(TFT_SCLK, -1, TFT_MOSI, TFT_CS);
    // 初始化屏幕
    tft.init(240, 240); // 分辨率
    tft.setRotation(0); // 旋转方向
    tft.fillScreen(ST77XX_BLACK);
    tft.setTextColor(ST77XX_WHITE);
    tft.setTextSize(2);
    tft.setCursor(10, 10);
    tft.println("Hello ST7789!");

    // 画一个红色圆
    tft.fillCircle(120, 120, 50, ST77XX_RED);

    // 打开背光（如有接线）
    pinMode(TFT_BL, OUTPUT);
    digitalWrite(TFT_BL, HIGH);
}

void loop() {
    Serial.println("Looping...");
    // 画一个红色圆
    tft.fillCircle(120, 120, 50, ST77XX_BLUE);
    delay(500);
    tft.fillCircle(120, 120, 50, ST77XX_GREEN);
    delay(500);
}
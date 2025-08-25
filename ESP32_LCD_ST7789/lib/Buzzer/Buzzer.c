//
// Created by Yuta on 2025/8/25.
//

#include "Buzzer.h"

static bool IsEnable = true;
static int32_t duration = 0;
static uint32_t freq = 0;

static void BuzzerThread(void* argument)
{
    for (;;)
    {
        if (duration > 0)
        {
            ledcWriteTone(CONFIG_BUZZ_CHANNEL, freq);
            delay(duration);
            ledcWriteTone(CONFIG_BUZZ_CHANNEL, 0);

            duration = 0;
        }

        delay(50);
    }
}

void Buzzer_Init()
{
    pinMode(CONFIG_BUZZ_PIN, OUTPUT);   // 设置蜂鸣器引脚为输出模式
    ledcAttachPin(CONFIG_BUZZ_PIN, CONFIG_BUZZ_CHANNEL);    // 将蜂鸣器引脚附加到LED控制通道
    ledcSetup(CONFIG_BUZZ_CHANNEL, 0, 8);   // 配置LED控制通道，初始频率为0，分辨率为8位
    ledcWriteTone(CONFIG_BUZZ_CHANNEL, 0);  // 设置初始频率为0，关闭蜂鸣器

    // Create Buzzer thread
    TaskHandle_t handleBuzzerThread;
    xTaskCreate(
        BuzzerThread,
        "BuzzerThread",
        2048,
         NULL,
        1,
        &handleBuzzerThread);
}

void Buzzer_SetEnable(bool en)
{
    IsEnable = en;
}

void Buzzer_Tone(uint32_t _freq, int32_t _duration)
{
    if (!IsEnable)
        return;

    if (_duration == 0)
    {
        ledcWriteTone(CONFIG_BUZZ_CHANNEL, _freq);
    } else
    {
        freq = _freq;
        duration = _duration;
    }
}

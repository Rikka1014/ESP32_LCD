//
// Created by Yuta on 2025/8/17.
//
#include "DallasTemperature.h"
#include "temperature_sensor.h"

#define DS18B20_PIN 21
OneWire one_wire(DS18B20_PIN);
DallasTemperature DS18B20(&one_wire);

void temperature_sensor_init(void) {
    DS18B20.begin();
    // DS18B20.setWaitForConversion(false);    // 设置为非阻塞式
}

bool temperature_sensor_read_loop(float *temperature) {
    bool ret = false;

    DS18B20.requestTemperatures();  // 发起新的温度转换

    *temperature = DS18B20.getTempCByIndex(0);  // 读取前一次的温度
    if (*temperature != DEVICE_DISCONNECTED_C) {
        ret = true;
    }
    Serial.print("*temperature: ");
    Serial.print(*temperature);
    Serial.println(" C");
    delay(500);

    return ret;
}
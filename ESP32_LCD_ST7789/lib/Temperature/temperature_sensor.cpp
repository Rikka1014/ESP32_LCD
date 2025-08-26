//
// Created by Yuta on 2025/8/17.
//
#include "temperature_sensor.h"
#include <DallasTemperature.h>
#include <Wire.h>
#include <Adafruit_SHT4x.h>

OneWire one_wire(DS18B20_PIN);
DallasTemperature DS18B20(&one_wire);
Adafruit_SHT4x SHT40 = Adafruit_SHT4x();

void temperature_sensor_init(void) {
    if (USE_SENSOR_DS18B20 )
    {
        DS18B20.begin();
        DS18B20.setResolution(12); // 设置分辨率为12位（0.0625度）
        DS18B20.setWaitForConversion(false);    // 设置为非阻塞式
        DS18B20.requestTemperatures(); // ☆关键：发起第一次温度转换
    }
    if (USE_SENSOR_SHT40)
    {
        Wire.begin(SHT40_SDA_PIN, SHT40_SCL_PIN);

        if (!SHT40.begin()) { // 检测传感器
            Serial.println("SHT40 not found!");
        }
        Serial.println("SHT40 detected!");

        // 设置精度（三选一）
        SHT40.setPrecision(SHT4X_HIGH_PRECISION); // 高精度（推荐）[1,7](@ref)
        // SHT40.setPrecision(SHT4X_MED_PRECISION); // 中精度
        // SHT40.setPrecision(SHT4X_LOW_PRECISION); // 低精度
        // 关闭加热器（除非需要除湿）
        SHT40.setHeater(SHT4X_NO_HEATER); // 默认关闭[5,7](@ref)
    }
}

bool temperature_sensor_read_loop(float *t, float *h) {
    bool ret = false;

    if (USE_SENSOR_DS18B20) {
        if (DS18B20.isConversionComplete()) {
            *t = DS18B20.getTempCByIndex(0);  // 读取前一次的温度
            if (*t != DEVICE_DISCONNECTED_C) {
                ret = true;
            }
            DS18B20.requestTemperatures();  // 发起新的温度转换
        }
    }

    if (USE_SENSOR_SHT40) {
        // 读取SHT40传感器的温度
        sensors_event_t humidity, temp; // 存储数据的结构体
        SHT40.getEvent(&humidity, &temp);
        // 打印温湿度
        Serial.print("Temp: ");
        Serial.print(temp.temperature);
        Serial.println(" °C");

        Serial.print("Humidity: ");
        Serial.print(humidity.relative_humidity);
        Serial.println("%");

        *t = temp.temperature; // 获取温度值
        *h = humidity.relative_humidity; // 获取湿度值

        ret = true;
    }

    return ret;
}
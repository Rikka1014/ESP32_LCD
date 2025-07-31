#include <Arduino.h>
#include "ui/ui.h"

void setup() {
    Serial.begin(115200);
    ui_init();
}

void loop() {
    ui_update();
}

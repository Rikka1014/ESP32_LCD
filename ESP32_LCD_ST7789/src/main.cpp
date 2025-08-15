#include <Arduino.h>

#include "my_ui/my_ui.h"
#include "key.h"


void setup() {
    Serial.begin(115200);
    my_ui_init();
}

void loop() {
    my_ui_update();

}

#include "led.h"

void setup()
{
    led_init();
}

void loop()
{
    LED(0);   // 亮
    delay(200);
    LED(1);   // 灭
    delay(200);
}
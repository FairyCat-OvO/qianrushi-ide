#include "relay.h"

unsigned long last_time = 0;
const long interval = 2000; // 2秒
uint8_t relay_sta = RELAY_OFF;

void setup()
{
    relay_init();
}

void loop()
{
    unsigned long now = millis();

    if (now - last_time >= interval)
    {
        last_time = now;
        relay_sta = !relay_sta;
        relay_ctrl(relay_sta);
    }
}
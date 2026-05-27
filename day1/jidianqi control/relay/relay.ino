#include "relay.h"

void setup()
{
    relay_init();
}

void loop()
{
    relay_ctrl(RELAY_ON);
    delay(1000);
    relay_ctrl(RELAY_OFF);
    delay(1000);
}
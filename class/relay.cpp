#include "relay.h"

void relay_init(void)
{
    pinMode(RELAY_PIN, OUTPUT);
    digitalWrite(RELAY_PIN, RELAY_OFF);
}

void relay_ctrl(uint8_t sta)
{
    digitalWrite(RELAY_PIN, sta);
}
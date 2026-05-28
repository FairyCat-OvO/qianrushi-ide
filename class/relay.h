#ifndef __RELAY_H
#define __RELAY_H

#include "Arduino.h"

#define RELAY_PIN  2   // 继电器IN引脚
#define RELAY_ON   HIGH
#define RELAY_OFF  LOW

void relay_init(void);
void relay_ctrl(uint8_t sta);

#endif
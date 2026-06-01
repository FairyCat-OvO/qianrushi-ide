#ifndef RELAY_H
#define RELAY_H

#include <Arduino.h>

#define RELAY1_PIN 6   // GPIO6，照明灯控制
#define RELAY2_PIN 7   // GPIO7，风扇控制

#define RELAY_ON    HIGH
#define RELAY_OFF   LOW

void relay_init(void);
void relay_task(void);
void relay_auto_run(void);
void relay_manual_run(void);
void relay_all_off(void);

#endif
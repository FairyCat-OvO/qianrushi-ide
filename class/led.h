#ifndef __LED_H
#define __LED_H

#include "Arduino.h"

#define LED_PIN  1              // LED连接的GPIO引脚号
#define LED(x)   digitalWrite(LED_PIN, x)  // 宏定义：快捷设置LED状态
#define LED_TOGGLE() digitalWrite(LED_PIN, !digitalRead(LED_PIN)) // 宏定义：翻转LED状态

void led_init(void);  // LED初始化函数声明

#endif
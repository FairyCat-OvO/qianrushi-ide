#ifndef __KEY_H
#define __KEY_H

#include "Arduino.h"

#define KEY_PIN   21   // 按键连接的GPIO引脚号
#define KEY       digitalRead(KEY_PIN)  // 宏定义：快捷读取按键状态

void key_init(void);  // 按键初始化函数声明

#endif
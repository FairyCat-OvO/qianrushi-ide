#ifndef __RELAY_H
#define __RELAY_H

#include "Arduino.h"

#define RELAY_PIN  2   // 继电器控制引脚（IN引脚）
#define RELAY_ON   HIGH  // 继电器吸合状态（高电平）
#define RELAY_OFF  LOW   // 继电器断开状态（低电平）

void relay_init(void);   // 继电器初始化函数声明
void relay_ctrl(uint8_t sta);  // 继电器控制函数声明

#endif
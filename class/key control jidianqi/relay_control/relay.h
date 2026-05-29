/**
 * @file relay.h
 * @brief 继电器控制模块头文件
 * @details 定义继电器控制引脚和状态宏
 *          RELAY_PIN: GPIO5
 */

#ifndef __RELAY_H
#define __RELAY_H

#include "Arduino.h"

#define RELAY_PIN   6    // 继电器控制引脚（IN引脚），GPIO6     
#define RELAY_ON    LOW  // 继电器吸合状态（低电平吸合）
#define RELAY_OFF   HIGH // 继电器断开状态（高电平断开）

void relay_init(void);       // 继电器初始化函数
void relay_ctrl(uint8_t sta); // 继电器控制函数

#endif
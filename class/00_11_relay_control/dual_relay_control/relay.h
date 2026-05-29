/**
 * @file relay.h
 * @brief 双继电器控制模块头文件
 * @details 定义两个继电器引脚和四种状态
 */

#ifndef __RELAY_H
#define __RELAY_H

#include "Arduino.h"

#define RELAY1_PIN   6    // 继电器1控制引脚（IN引脚），GPIO6
#define RELAY2_PIN   7    // 继电器2控制引脚（IN引脚），GPIO7

#define RELAY_ON    HIGH // 继电器吸合状态（高电平吸合）
#define RELAY_OFF   LOW  // 继电器断开状态（低电平断开）

// 继电器四种状态
#define RELAY_STATE_00  0x00  // 00: 两个继电器都断开
#define RELAY_STATE_01  0x01  // 01: 继电器1断开，继电器2吸合
#define RELAY_STATE_10  0x02  // 10: 继电器1吸合，继电器2断开
#define RELAY_STATE_11  0x03  // 11: 两个继电器都吸合

void relay_init(void);                    // 继电器初始化函数
void relay_ctrl(uint8_t relay1_sta, uint8_t relay2_sta);  // 分别控制两个继电器
void relay_set_state(uint8_t state);      // 设置继电器状态（四种状态）

#endif
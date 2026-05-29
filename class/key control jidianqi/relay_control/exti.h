/**
 * @file exti.h
 * @brief 外部中断模块头文件
 * @details 封装外部中断相关的初始化和中断服务函数
 *          - KEY1（GPIO21）：上升沿触发，控制系统开关
 *          - KEY2（GPIO20）：下降沿触发，控制继电器
 */

#ifndef __EXTI_H
#define __EXTI_H

#include "Arduino.h"

extern uint8_t system_enable;  // 系统使能标志
extern uint8_t relay_toggle;   // 继电器切换标志

void exti_init(void);      // 外部中断初始化函数声明

#endif
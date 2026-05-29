/**
 * @file exti.h
 * @brief 外部中断模块头文件
 */

#ifndef __EXTI_H
#define __EXTI_H

#include "Arduino.h"

extern uint8_t system_enable;     // 系统使能标志：0=关闭，1=开启
extern uint8_t relay_toggle;      // 继电器切换标志：1=需要切换

void exti_init(void);

#endif
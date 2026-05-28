/**
 * @file exti.h
 * @brief 外部中断模块头文件
 * @details 封装外部中断相关的初始化和中断服务函数
 *          配置GPIO21为外部中断引脚，上升沿触发
 */

#ifndef __EXTI_H
#define __EXTI_H

#include "Arduino.h"

extern uint8_t led_state;  // 外部声明LED状态变量，供中断服务函数使用

void exti_init(void);      // 外部中断初始化函数声明

#endif
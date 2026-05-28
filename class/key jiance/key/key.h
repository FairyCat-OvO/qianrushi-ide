/**
 * @file key.h
 * @brief 按键检测模块头文件
 * @details 定义按键引脚和相关宏，声明初始化函数
 *          使用GPIO21作为按键输入引脚，内部上拉模式
 */

#ifndef __KEY_H
#define __KEY_H

#include "Arduino.h"

#define KEY_PIN   21   // 按键连接的GPIO引脚号（GPIO21）
#define KEY       digitalRead(KEY_PIN)  // 宏定义：快捷读取按键状态

void key_init(void);  // 按键初始化函数声明

#endif
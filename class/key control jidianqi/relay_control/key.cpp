/**
 * @file key.cpp
 * @brief 双按键控制模块实现文件
 * @details 实现双按键初始化功能
 *          KEY1使用内部上拉（自锁按键按下为低电平）
 *          KEY2使用内部上拉（普通按键按下为低电平）
 */

#include "key.h"

/**
 * @brief 按键初始化函数
 * @details 将两个按键引脚设置为输入模式，启用内部上拉电阻
 */
void key_init(void)
{
    pinMode(KEY1_PIN, INPUT_PULLUP);  // KEY1设置为上拉输入
    pinMode(KEY2_PIN, INPUT_PULLUP);  // KEY2设置为上拉输入
}
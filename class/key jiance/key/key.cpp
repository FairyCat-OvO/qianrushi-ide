/**
 * @file key.cpp
 * @brief 按键检测模块实现文件
 * @details 实现按键初始化功能，配置GPIO21为上拉输入模式
 */

#include "key.h"

/**
 * @brief 按键初始化函数
 * @details 将按键引脚设置为输入模式，并启用内部上拉电阻
 *          启用内部上拉后：
 *          - 按键未按下：引脚读取为 HIGH（1）
 *          - 按键按下：引脚读取为 LOW（0）
 */
void key_init(void)
{
    pinMode(KEY_PIN, INPUT_PULLUP); // 设置为输入模式，启用内部上拉电阻
}
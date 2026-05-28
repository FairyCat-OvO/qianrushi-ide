#include "key.h"

/**
 * @brief 按键初始化函数
 * @details 将按键引脚设置为输入模式，并启用内部上拉电阻
 *          使用内部上拉后，按键未按下时为高电平(HIGH)，按下时为低电平(LOW)
 */
void key_init(void)
{
    pinMode(KEY_PIN, INPUT_PULLUP); // 设置为输入模式，启用内部上拉电阻
}
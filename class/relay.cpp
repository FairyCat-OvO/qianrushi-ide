#include "relay.h"

/**
 * @brief 继电器初始化函数
 * @details 将继电器控制引脚设置为输出模式，并初始化为断开状态
 */
void relay_init(void)
{
    pinMode(RELAY_PIN, OUTPUT);         // 设置为输出模式
    digitalWrite(RELAY_PIN, RELAY_OFF); // 初始断开继电器
}

/**
 * @brief 继电器控制函数
 * @param sta 继电器状态：RELAY_ON（吸合）或 RELAY_OFF（断开）
 */
void relay_ctrl(uint8_t sta)
{
    digitalWrite(RELAY_PIN, sta); // 设置继电器状态
}
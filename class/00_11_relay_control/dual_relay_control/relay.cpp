/**
 * @file relay.cpp
 * @brief 双继电器控制模块实现文件
 * @details 实现两个继电器的初始化和控制功能，支持四种状态切换
 */

#include "relay.h"

/**
 * @brief 继电器初始化函数
 * @details 将继电器引脚设置为输出模式，初始状态为断开
 */
void relay_init(void)
{
    pinMode(RELAY1_PIN, OUTPUT);         // 设置继电器1为输出模式
    pinMode(RELAY2_PIN, OUTPUT);         // 设置继电器2为输出模式
    digitalWrite(RELAY1_PIN, RELAY_OFF);  // 初始断开
    digitalWrite(RELAY2_PIN, RELAY_OFF);  // 初始断开
}

/**
 * @brief 分别控制两个继电器
 * @param relay1_sta 继电器1状态：RELAY_ON（吸合）或 RELAY_OFF（断开）
 * @param relay2_sta 继电器2状态：RELAY_ON（吸合）或 RELAY_OFF（断开）
 */
void relay_ctrl(uint8_t relay1_sta, uint8_t relay2_sta)
{
    digitalWrite(RELAY1_PIN, relay1_sta);
    digitalWrite(RELAY2_PIN, relay2_sta);
}

/**
 * @brief 设置继电器状态（四种状态）
 * @param state 继电器状态：00(0x00), 01(0x01), 10(0x02), 11(0x03)
 */
void relay_set_state(uint8_t state)
{
    switch(state)
    {
        case RELAY_STATE_00:
            relay_ctrl(RELAY_OFF, RELAY_OFF);
            break;
        case RELAY_STATE_01:
            relay_ctrl(RELAY_OFF, RELAY_ON);
            break;
        case RELAY_STATE_10:
            relay_ctrl(RELAY_ON, RELAY_OFF);
            break;
        case RELAY_STATE_11:
            relay_ctrl(RELAY_ON, RELAY_ON);
            break;
        default:
            relay_ctrl(RELAY_OFF, RELAY_OFF);
            break;
    }
}
#include "relay.h"

/**
 * @brief 初始化函数
 * @details 只执行一次，用于初始化继电器
 */
void setup()
{
    relay_init();  // 调用继电器初始化函数
}

/**
 * @brief 主循环函数
 * @details 无限循环执行，实现继电器吸合和断开的循环控制
 */
void loop()
{
    relay_ctrl(RELAY_ON);   // 吸合继电器
    delay(1000);            // 延时1秒
    relay_ctrl(RELAY_OFF);  // 断开继电器
    delay(1000);            // 延时1秒
}
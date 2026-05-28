/**
 * @file relay.ino
 * @brief 继电器控制主程序（阻塞方式）
 * @details 使用delay()实现继电器定时吸合和断开
 *          每隔1秒切换一次继电器状态
 *          注意：此方式使用delay()，会阻塞其他代码执行
 */

#include "relay.h"

/**
 * @brief 初始化函数
 * @details 只执行一次，初始化继电器模块
 */
void setup()
{
    relay_init();  // 调用继电器初始化函数
}

/**
 * @brief 主循环函数
 * @details 无限循环执行，实现继电器吸合和断开的循环控制
 *          使用delay()进行延时，简单但会阻塞程序
 */
void loop()
{
    relay_ctrl(RELAY_ON);   // 吸合继电器（连接负载）
    delay(1000);            // 延时1秒
    relay_ctrl(RELAY_OFF);  // 断开继电器（切断负载）
    delay(1000);            // 延时1秒
}
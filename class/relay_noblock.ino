#include "relay.h"

unsigned long last_time = 0;     // 记录上次状态切换的时间
const long interval = 2000;      // 状态切换间隔（毫秒），这里是2秒
uint8_t relay_sta = RELAY_OFF;   // 继电器当前状态，初始为断开

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
 * @details 使用非阻塞方式实现继电器定时切换
 *          使用 millis() 函数实现非阻塞延时，不影响其他代码执行
 */
void loop()
{
    unsigned long now = millis(); // 获取当前时间（毫秒）

    // 判断是否达到切换时间间隔
    if (now - last_time >= interval)
    {
        last_time = now;           // 更新上次切换时间
        relay_sta = !relay_sta;    // 翻转继电器状态
        relay_ctrl(relay_sta);     // 应用新状态
    }
    // 这里可以添加其他代码，不会被delay阻塞
}
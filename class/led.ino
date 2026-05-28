#include "led.h"

/**
 * @brief 初始化函数
 * @details 只执行一次，用于初始化LED
 */
void setup()
{
    led_init();  // 调用LED初始化函数
}

/**
 * @brief 主循环函数
 * @details 无限循环执行，实现LED闪烁效果
 */
void loop()
{
    LED(0);   // 点亮LED（低电平点亮）
    delay(200); // 延时200ms
    LED(1);   // 熄灭LED（高电平熄灭）
    delay(200); // 延时200ms
}
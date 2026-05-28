#include "led.h"

/**
 * @brief LED初始化函数
 * @details 将LED引脚设置为输出模式，并初始化为熄灭状态
 *          假设LED为共阳极接法，高电平熄灭，低电平点亮
 */
void led_init(void)
{
    pinMode(LED_PIN, OUTPUT);         // 设置为输出模式
    digitalWrite(LED_PIN, HIGH);      // 初始熄灭（高电平）
}
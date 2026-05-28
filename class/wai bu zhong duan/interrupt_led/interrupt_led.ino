/**
 * @file interrupt_led.ino
 * @brief 外部中断实验主程序
 * @details 通过外部中断实现按键控制LED状态翻转
 *          GPIO21设置为下拉输入，按键按下产生上升沿触发中断
 *          中断服务函数中翻转LED状态
 * 
 * 硬件连接：
 * - KEY2按键：GPIO21 --- 按键 --- VCC
 * - LED2：GPIO1 --- LED --- GND
 * 
 * 工作原理：
 * - 按键未按下时，GPIO21为低电平（下拉）
 * - 按键按下时，GPIO21变为高电平，产生上升沿
 * - 上升沿触发外部中断，执行中断服务函数
 * - 中断服务函数翻转LED状态
 */

#include "key.h"
#include "led.h"

volatile int led_state = HIGH; // LED状态，volatile关键字表示可能被中断修改

/**
 * @brief 外部中断服务函数
 * @details 按键按下（上升沿）时触发，翻转LED状态
 * @note 中断服务函数应尽量简短，避免使用delay()等阻塞函数
 */
void key_isr() {
    led_state = !led_state; // 翻转LED状态（高变低，低变高）
}

/**
 * @brief 初始化函数
 * @details 只执行一次，初始化按键、LED和外部中断
 */
void setup() {
    key_init();         // 初始化按键（下拉输入模式）
    led_init();         // 初始化LED
    
    // 配置外部中断：引脚21，中断服务函数key_isr，上升沿触发
    // RISING：上升沿触发（低电平变高电平时）
    attachInterrupt(digitalPinToInterrupt(KEY_PIN), key_isr, RISING);
}

/**
 * @brief 主循环函数
 * @details 无限循环执行，持续更新LED状态
 */
void loop() {
    digitalWrite(LED_PIN, led_state); // 根据led_state更新LED状态
    // 主循环可以执行其他任务，不会被中断阻塞
}
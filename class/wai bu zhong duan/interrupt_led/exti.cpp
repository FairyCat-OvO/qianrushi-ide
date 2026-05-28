/**
 * @file exti.cpp
 * @brief 外部中断模块实现文件
 * @details 实现外部中断初始化和中断服务函数
 *          按键按下产生上升沿触发中断，翻转LED状态
 */

#include "exti.h"
#include "key.h"

uint8_t led_state = 0;  // LED状态变量，0表示熄灭，1表示点亮

/**
 * @brief 外部中断初始化函数
 * @details 初始化按键模块，并配置外部中断
 *          GPIO21设置为下拉输入，按键按下产生上升沿触发中断
 */
void exti_init(void) {
    key_init();  // 初始化按键模块（设置GPIO21为下拉输入）
    
    // 配置外部中断：按键引脚，中断服务函数key_isr，上升沿触发
    attachInterrupt(digitalPinToInterrupt(KEY_PIN), key_isr, RISING);
}

/**
 * @brief 外部中断服务函数
 * @details 按键按下（上升沿）时触发，带消抖处理
 *          消抖后翻转LED状态（从0变1，从1变0）
 */
void key_isr(void) {
    delay(10);  // 消抖：等待10ms稳定
    
    if (KEY == 0) {  // 再次检测按键状态（低电平表示按下）
        led_state = !led_state;  // 翻转LED状态
    }
}
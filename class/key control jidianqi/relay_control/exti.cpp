/**
 * @file exti.cpp
 * @brief 外部中断模块实现文件
 * @details 实现外部中断初始化和中断服务函数
 *          - KEY1（自锁）控制系统总开关
 *          - KEY2（普通）控制继电器切换
 */

#include "exti.h"
#include "key.h"

uint8_t system_enable = 0;  // 系统使能标志：0=关闭，1=开启
uint8_t relay_toggle = 0;   // 继电器切换标志：1=需要切换

void key1_isr(void);  // 函数声明
void key2_isr(void);  // 函数声明

/**
 * @brief 外部中断初始化函数
 * @details 初始化按键模块，并配置两个外部中断
 *          KEY1：GPIO21，上升沿触发（自锁按键）
 *          KEY2：GPIO20，下降沿触发（普通按键）
 */
void exti_init(void) {
    key_init();  // 初始化按键模块

    // 配置KEY1外部中断：上升沿触发
    attachInterrupt(digitalPinToInterrupt(KEY1_PIN), key1_isr, RISING);

    // 配置KEY2外部中断：下降沿触发
    attachInterrupt(digitalPinToInterrupt(KEY2_PIN), key2_isr, FALLING);
}

/**
 * @brief KEY1中断服务函数（总开关）
 * @details 自锁按键触发翻转系统使能状态
 */
void key1_isr(void) {
    delay(10);  // 消抖

    if (KEY1 == 0) {  // 确认按键按下（低电平）
        system_enable = !system_enable;  // 翻转系统使能状态
        relay_toggle = 1;  // 设置切换标志，让主程序处理
    }
}

/**
 * @brief KEY2中断服务函数（继电器控制）
 * @details 普通按键触发继电器切换请求
 */
void key2_isr(void) {
    delay(10);  // 消抖

    if (KEY2 == 0) {  // 确认按键按下（低电平）
        relay_toggle = 1;  // 设置切换标志，让主程序处理
    }
}
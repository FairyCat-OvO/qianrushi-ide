/**
 * @file relay_control.ino
 * @brief 按键控制继电器开关实验主程序（中断方式）
 * @details 使用外部中断实现自锁按键控制继电器开关功能：
 *          - KEY1（GPIO21）：自锁按键，总开关，上升沿中断
 *          - KEY2（GPIO20）：普通按键，控制继电器，下降沿中断
 *          - RELAY（GPIO2）：继电器控制引脚
 *
 * 工作逻辑：
 * 1. KEY1打开后（上升沿触发），系统使能
 * 2. KEY2按下（下降沿触发），切换继电器状态
 * 3. KEY1关闭后，系统失能，继电器强制断开
 *
 * 硬件连接：
 * - KEY1（自锁）：GPIO21 --- 按键 --- GND
 * - KEY2（普通）：GPIO20 --- 按键 --- GND
 * - RELAY：GPIO2 --- 继电器控制端
 */

#include "key.h"
#include "relay.h"
#include "exti.h"

uint8_t relay_state = RELAY_OFF;  // 继电器状态

/**
 * @brief 初始化函数
 */
void setup() {
    relay_init();       // 初始化继电器
    exti_init();        // 初始化外部中断
    Serial.begin(9600); // 开启串口
    Serial.println("System initialized");
}

/**
 * @brief 主循环函数
 * @details 主程序处理继电器切换逻辑
 *          中断服务函数只设置标志位，主程序处理实际动作
 */
void loop() {
    // 检查是否需要切换继电器
    if (relay_toggle == 1) {
        relay_toggle = 0;  // 清除标志

        if (system_enable == 1) {
            // 系统使能，切换继电器状态
            relay_state = !relay_state;
            relay_ctrl(relay_state);

            if (relay_state == RELAY_ON) {
                Serial.println("Relay ON");
            } else {
                Serial.println("Relay OFF");
            }
        }
    }

    // 检查系统是否失能
    if (system_enable == 0 && relay_state == RELAY_ON) {
        // 系统失能，强制断开继电器
        relay_ctrl(RELAY_OFF);
        relay_state = RELAY_OFF;
        Serial.println("System disabled - Relay OFF");
    }

    delay(50);
}
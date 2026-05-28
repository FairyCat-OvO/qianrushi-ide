/**
 * @file relay_control.ino
 * @brief 按键控制继电器开关实验主程序
 * @details 实现自锁按键控制继电器开关功能：
 *          - KEY1（GPIO21）：自锁按键，总开关
 *          - KEY2（GPIO19）：普通按键，控制继电器开关
 *          - RELAY（GPIO2）：继电器控制引脚
 * 
 * 工作逻辑：
 * 1. KEY1打开后（低电平），系统允许KEY2控制继电器
 * 2. 按一下KEY2，继电器吸合；再按一下，继电器断开，依次循环
 * 3. KEY1关闭后（高电平），继电器强制断开
 * 
 * 硬件连接：
 * - KEY1（自锁）：GPIO21 --- 按键 --- GND
 * - KEY2（普通）：GPIO19 --- 按键 --- GND
 * - RELAY：GPIO2 --- 继电器控制端
 */

#include "key.h"
#include "relay.h"

uint8_t key1_state = HIGH;   // KEY1状态（高电平为关闭）
uint8_t relay_state = RELAY_OFF;  // 继电器状态
uint8_t key2_flag = 0;            // KEY2按下标志

/**
 * @brief 初始化函数
 */
void setup() {
    key_init();         // 初始化按键
    relay_init();       // 初始化继电器
    Serial.begin(9600); // 开启串口
}

/**
 * @brief 主循环函数
 */
void loop() {
    // 读取KEY1状态（自锁按键）
    key1_state = KEY1;
    
    // 如果KEY1打开（低电平）
    if (key1_state == LOW) {
        Serial.println("KEY1 ON - System enabled");
        
        // 检测KEY2按下（带消抖）
        if (KEY2 == LOW && key2_flag == 0) {
            delay(10);  // 消抖
            if (KEY2 == LOW) {
                key2_flag = 1;  // 设置按下标志
                // 翻转继电器状态
                relay_state = !relay_state;
                relay_ctrl(relay_state);
                
                if (relay_state == RELAY_ON) {
                    Serial.println("KEY2 pressed - Relay ON");
                } else {
                    Serial.println("KEY2 pressed - Relay OFF");
                }
            }
        }
        
        // KEY2松开后清除标志
        if (KEY2 == HIGH) {
            key2_flag = 0;
        }
    } else {
        // KEY1关闭，强制断开继电器
        if (relay_state == RELAY_ON) {
            relay_ctrl(RELAY_OFF);
            relay_state = RELAY_OFF;
            Serial.println("KEY1 OFF - Relay forced OFF");
        }
    }
    
    delay(50);  // 循环延时
}
/**
 * @file interrupt_led.ino
 * @brief 外部中断实验主程序
 * @details 通过外部中断实现按键控制LED状态翻转
 *          GPIO21设置为下拉输入，按键按下产生上升沿触发中断
 *          使用exti模块封装中断功能
 * 
 * 硬件连接：
 * - KEY2按键：GPIO21 --- 按键 --- VCC
 * - LED2：GPIO1 --- LED --- GND
 */

#include "key.h"
#include "led.h"
#include "exti.h"

void setup() {
    exti_init();              // 初始化外部中断（包含按键初始化）
    led_init();              // 初始化LED
    Serial.begin(115200);    // 开启串口通信，波特率115200
}

void loop() {
    // 主循环中打印LED状态
    Serial.println(led_state);
    
    // 根据led_state更新LED状态
    if (led_state == 1) {
        LED(LOW);   // 点亮LED
    } else {
        LED(HIGH);  // 熄灭LED
    }
}
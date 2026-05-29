/**
 * @file dual_relay_control.ino
 * @brief 双按键控制双继电器开关实验主程序（中断方式）
 * @details KEY1为自锁按键作为总开关，KEY2控制两个继电器的四种状态轮流切换
 */

#include "key.h"
#include "relay.h"
#include "exti.h"

uint8_t relay_state = RELAY_STATE_00;  // 当前继电器状态

void setup() {
    relay_init();
    exti_init();
    
    relay_state = RELAY_STATE_00;
    relay_set_state(relay_state);
    
    Serial.begin(115200);
    while (!Serial) { delay(10); }
    
    Serial.println("=== 双按键控制双继电器 ===");
    Serial.println("KEY1(GPIO20): 自锁按键，总开关");
    Serial.println("KEY2(GPIO21): 普通按键，控制继电器状态切换");
    Serial.println("继电器1(GPIO6): 受控设备1");
    Serial.println("继电器2(GPIO7): 受控设备2");
    Serial.println("-----------------------------------");
    Serial.println("继电器四种状态（短按KEY2切换）:");
    Serial.println("  00: 继电器1断开，继电器2断开");
    Serial.println("  01: 继电器1断开，继电器2吸合");
    Serial.println("  10: 继电器1吸合，继电器2断开");
    Serial.println("  11: 继电器1吸合，继电器2吸合");
    Serial.println("-----------------------------------");
}

void loop() {
    if (relay_toggle == 1) {
        relay_toggle = 0;

        if (system_enable == 1) {
            // 四种状态轮流切换：00 -> 01 -> 10 -> 11 -> 00...
            relay_state = (relay_state + 1) % 4;
            relay_set_state(relay_state);
        } else {
            relay_state = RELAY_STATE_00;
            relay_set_state(RELAY_STATE_00);
        }
    }

    // KEY1关闭时，强制关闭所有继电器
    if (system_enable == 0 && relay_state != RELAY_STATE_00) {
        relay_state = RELAY_STATE_00;
        relay_set_state(RELAY_STATE_00);
    }
    
    // 实时输出中文状态
    static unsigned long last_print = 0;
    if (millis() - last_print >= 500) {
        last_print = millis();
        
        Serial.print("KEY1: ");
        Serial.print(KEY1 ? "按下" : "松开");
        Serial.print(" | KEY2: ");
        Serial.print(KEY2 ? "按下" : "松开");
        Serial.print(" | 系统: ");
        Serial.print(system_enable ? "使能" : "禁用");
        Serial.print(" | 继电器状态: ");
        
        switch(relay_state) {
            case RELAY_STATE_00:
                Serial.println("00 (断开, 断开)");
                break;
            case RELAY_STATE_01:
                Serial.println("01 (断开, 吸合)");
                break;
            case RELAY_STATE_10:
                Serial.println("10 (吸合, 断开)");
                break;
            case RELAY_STATE_11:
                Serial.println("11 (吸合, 吸合)");
                break;
        }
    }
}
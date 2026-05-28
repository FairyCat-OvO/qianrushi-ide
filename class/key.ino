#include "key.h"

/**
 * @brief 初始化函数
 * @details 只执行一次，用于初始化按键和串口
 */
void setup()
{
    key_init();         // 调用按键初始化函数
    Serial.begin(9600); // 初始化串口，波特率9600
}

/**
 * @brief 主循环函数
 * @details 无限循环执行，检测按键状态
 */
void loop()
{
    if (KEY == 0)           // 检测按键是否按下（低电平表示按下）
    {
        delay(10);          // 消抖延时：等待10ms让信号稳定
        if (KEY == 0)       // 再次确认按键状态，防止误触发
        {
            Serial.println("key press!");  // 串口打印按键按下信息
            while (KEY == 0); // 等待按键松开（阻塞等待）
        }
    }
}
/**
 * @file key.ino
 * @brief 按键检测主程序
 * @details 检测按键按下状态，带软件消抖功能
 *          按键按下时通过串口输出"key press!"
 */

#include "key.h"

/**
 * @brief 初始化函数
 * @details 只执行一次，初始化按键模块和串口通信
 */
void setup()
{
    key_init();         // 调用按键初始化函数
    Serial.begin(9600); // 初始化串口，波特率9600
}

/**
 * @brief 主循环函数
 * @details 无限循环执行，检测按键状态
 *          使用软件消抖：检测到按下后延时10ms再次确认
 */
void loop()
{
    if (KEY == 0)           // 检测按键是否按下（低电平表示按下）
    {
        delay(10);          // 消抖延时：等待10ms让信号稳定
        if (KEY == 0)       // 再次确认按键状态，防止误触发
        {
            Serial.println("key press!");  // 串口打印按键按下信息
            while (KEY == 0); // 等待按键松开（阻塞等待，防止重复触发）
        }
    }
}
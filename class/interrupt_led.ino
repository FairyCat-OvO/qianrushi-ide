/**
 * @file interrupt_led.ino
 * @brief 外部中断实验：按键控制LED状态翻转
 * @details GPIO21设置为下拉输入，按键按下产生上升沿触发中断
 *          中断服务函数中翻转LED状态
 */

const int KEY_PIN = 21;    // 按键引脚 GPIO21
const int LED_PIN = 1;      // LED引脚

volatile int led_state = LOW; // LED状态，volatile关键字表示可能被中断修改

/**
 * @brief 初始化函数
 * @details 设置引脚模式，配置外部中断
 */
void setup() {
  pinMode(LED_PIN, OUTPUT);           // 设置LED引脚为输出模式
  pinMode(KEY_PIN, INPUT_PULLDOWN);   // 设置按键引脚为下拉输入模式
  
  digitalWrite(LED_PIN, led_state);   // 初始化LED状态
  
  // 配置外部中断：引脚21，中断服务函数key_isr，上升沿触发
  attachInterrupt(digitalPinToInterrupt(KEY_PIN), key_isr, RISING);
}

/**
 * @brief 主循环函数
 * @details 持续更新LED状态，LED状态由中断控制
 */
void loop() {
  digitalWrite(LED_PIN, led_state); // 根据led_state更新LED状态
}

/**
 * @brief 外部中断服务函数
 * @details 按键按下（上升沿）时触发，翻转LED状态
 * @note 中断服务函数应尽量简短，避免使用delay()等阻塞函数
 */
void key_isr() {
  led_state = !led_state; // 翻转LED状态（0变1，1变0）
}
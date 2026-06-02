#include "exti.h"
#include "relay.h"
#include "light_sensor.h"
#include "temp_sensor.h"
#include "display.h"
#include "wifi_connect.h"
#include "ws2812_rgb.h"

void setup() {
  Serial.begin(115200);
  while (!Serial) { delay(10); }
  
  exti_init();
  relay_init();
  light_sensor_init();
  temp_sensor_init();
  display_init();
  ws2812_init();
  
  Serial.println("===== 智能环境控制系统 =====");
  Serial.println("KEY1(GPIO20): 自锁按键，系统使能");
  Serial.println("KEY2(GPIO21): 长按2秒切换模式");
  Serial.println("RELAY1(GPIO6): 照明灯");
  Serial.println("RELAY2(GPIO7): 风扇");
  Serial.println("光照传感器(GPIO1)");
  Serial.println("温度传感器(GPIO10)");
  Serial.println("OLED SDA(GPIO4), SCL(GPIO5)");
  Serial.println("WS2812 RGB(GPIO0)");
  Serial.println("WiFi: ESP32内置模块");
  Serial.println("-----------------------------");
  Serial.println("串口命令:");
  Serial.println("  disconnect - 断开WiFi并禁用扫描");
  Serial.println("  connect    - 重新启用WiFi连接");
  Serial.println("-----------------------------");
  Serial.print("模式:");
  Serial.println(auto_mode ? "自动模式" : "手动模式");
  
  ws2812_boot_sequence();
  
  wifi_init();
  
  ws2812_set_wifi_status(wifi_is_connected());
}

void loop() {
  exti_task();
  relay_task();
  wifi_task();
  wifi_check_serial_command();
  
  static unsigned long last_led_update = 0;
  if (millis() - last_led_update >= 100) {
    last_led_update = millis();
    ws2812_set_wifi_status(wifi_is_connected());
  }
}
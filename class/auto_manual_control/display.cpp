#include "display.h"
#include <U8g2lib.h>
#include <Wire.h>

#ifdef U8X8_HAVE_HW_I2C
U8G2_SH1106_128X64_VCOMH0_F_HW_I2C u8g2(U8G2_R0);
#else
#error "I2C support required"
#endif

void display_init(void) {
  Wire.begin(I2C_SDA, I2C_SCL);
  u8g2.begin();
  u8g2.setContrast(0x60);
  u8g2.setPowerSave(0);
  u8g2.setFont(u8g2_font_ncenB08_tr);
  
  u8g2.clearBuffer();
  u8g2.drawFrame(0, 0, 128, 64);
  u8g2.drawStr(10, 15, "PCT_100_CTL");
  u8g2.drawStr(10, 35, "INIT...");
  u8g2.sendBuffer();
}

void display_update_info(bool mode_auto, bool main_on, uint16_t light_val, uint16_t light_max, 
                         float temp_val, float temp_max, bool led_on, bool fan_on) {
  u8g2.clearBuffer();
  
  u8g2.drawFrame(0, 0, 128, 64);
  
  char buf[32];
  
  sprintf(buf, "MODE:%s MAIN:%s", mode_auto ? "auto" : "manu", main_on ? "ON" : "OFF");
  u8g2.drawStr(2, 12, buf);
  
  sprintf(buf, "LIGHT:%4d/%4d", light_val, light_max);
  u8g2.drawStr(2, 28, buf);
  
  sprintf(buf, "TEMP:%5.1f/%4.1f", temp_val, temp_max);
  u8g2.drawStr(2, 44, buf);
  
  sprintf(buf, "LED:%s FAN:%s", led_on ? "ON" : "OFF", fan_on ? "ON" : "OFF");
  u8g2.drawStr(2, 60, buf);
  
  u8g2.sendBuffer();
}
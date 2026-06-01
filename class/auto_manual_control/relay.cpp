#include "relay.h"
#include "exti.h"
#include "light_sensor.h"
#include "temp_sensor.h"

int state = 0;

void relay_init(void) {
  pinMode(RELAY1_PIN, OUTPUT);
  pinMode(RELAY2_PIN, OUTPUT);
  
  digitalWrite(RELAY1_PIN, LOW);
  digitalWrite(RELAY2_PIN, LOW);
}

void relay_task(void) {
  if (!system_enable) {
    digitalWrite(RELAY1_PIN, LOW);
    digitalWrite(RELAY2_PIN, LOW);
    state = 0;
    return;
  }

  if (key2_long_2s) {
    auto_mode = !auto_mode;
    key2_long_2s = false;

    if (auto_mode) {
      state = 0;
      digitalWrite(RELAY1_PIN, LOW);
      digitalWrite(RELAY2_PIN, LOW);
      Serial.println("→ 自动模式：温度联动风扇，光照联动照明");
    } else {
      Serial.println("→ 手动模式：可以按键控制");
    }
  }

  if (auto_mode) {
    relay_auto_run();
    return;
  }

  relay_manual_run();
}

void relay_auto_run(void) {
  LightLevel light_level = light_sensor_get_level();
  float temp_c = temp_sensor_read_celsius();
  TempLevel temp_level = temp_sensor_get_level(temp_c);
  
  if (light_level == LIGHT_DARK || light_level == LIGHT_DIM) {
    digitalWrite(RELAY1_PIN, HIGH);
  } else {
    digitalWrite(RELAY1_PIN, LOW);
  }
  
  if (temp_level == TEMP_HIGH || temp_level == TEMP_VERY_HIGH) {
    digitalWrite(RELAY2_PIN, HIGH);
  } else {
    digitalWrite(RELAY2_PIN, LOW);
  }
  
  static unsigned long last_print = 0;
  if (millis() - last_print >= 1000) {
    last_print = millis();
    Serial.print("自动 | 光照:");
    Serial.print(light_sensor_get_level_string(light_level));
    Serial.print(" | 照明:");
    Serial.print(digitalRead(RELAY1_PIN) == HIGH ? "开" : "关");
    Serial.print(" | 温度:");
    Serial.print(temp_c, 1);
    Serial.print("°C | 风扇:");
    Serial.println(digitalRead(RELAY2_PIN) == HIGH ? "开" : "关");
  }
}

void relay_manual_run(void) {
  if (key2_short) {
    state = (state + 1) % 4;
    key2_short = false;
    Serial.print("手动 → 状态:");
    Serial.println(state);
  }

  switch(state) {
    case 0:
      digitalWrite(RELAY1_PIN, LOW);
      digitalWrite(RELAY2_PIN, LOW);
      break;
    case 1:
      digitalWrite(RELAY1_PIN, LOW);
      digitalWrite(RELAY2_PIN, HIGH);
      break;
    case 2:
      digitalWrite(RELAY1_PIN, HIGH);
      digitalWrite(RELAY2_PIN, LOW);
      break;
    case 3:
      digitalWrite(RELAY1_PIN, HIGH);
      digitalWrite(RELAY2_PIN, HIGH);
      break;
  }
}

void relay_all_off(void) {
  digitalWrite(RELAY1_PIN, LOW);
  digitalWrite(RELAY2_PIN, LOW);
}
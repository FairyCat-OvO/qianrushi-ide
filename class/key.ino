#include "key.h"

void setup()
{
    key_init();
    Serial.begin(9600);
}

void loop()
{
    if (KEY == 0)
    {
        delay(10); // 消抖
        if (KEY == 0)
        {
            Serial.println("key press!");
            while (KEY == 0); // 等待松开
        }
    }
}
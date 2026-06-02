#include "ws2812_rgb.h"
#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel pixel(1, WS2812_PIN, NEO_GRB + NEO_KHZ800);

static uint32_t hsv_to_rgb(uint16_t hue, uint8_t sat, uint8_t val) {
    uint8_t r, g, b;
    uint16_t h = hue % 60;
    uint8_t f = h * 255 / 60;
    uint8_t p = (255 - sat) * val / 255;
    uint8_t q = (255 - (sat * f / 255)) * val / 255;
    uint8_t t = (255 - (sat * (255 - f) / 255)) * val / 255;
    
    switch (hue / 60) {
        case 0: r = val; g = t; b = p; break;
        case 1: r = q; g = val; b = p; break;
        case 2: r = p; g = val; b = t; break;
        case 3: r = p; g = q; b = val; break;
        case 4: r = t; g = p; b = val; break;
        default: r = val; g = p; b = q; break;
    }
    return pixel.Color(r, g, b);
}

void ws2812_init(void) {
    pixel.begin();
    pixel.setBrightness(80);
    pixel.clear();
    pixel.show();
}

void ws2812_set_color(uint8_t r, uint8_t g, uint8_t b) {
    pixel.setPixelColor(0, pixel.Color(r, g, b));
    pixel.show();
}

void ws2812_set_color_struct(RGBColor color) {
    pixel.setPixelColor(0, pixel.Color(color.r, color.g, color.b));
    pixel.show();
}

void ws2812_clear(void) {
    pixel.clear();
    pixel.show();
}

void ws2812_show(void) {
    pixel.show();
}

void ws2812_boot_sequence(void) {
    for (uint16_t hue = 0; hue < 360; hue += 5) {
        pixel.setPixelColor(0, hsv_to_rgb(hue, 255, 150));
        pixel.show();
        delay(15);
    }
    pixel.clear();
    pixel.show();
}

void ws2812_set_wifi_status(bool connected) {
    if (connected) {
        pixel.setPixelColor(0, pixel.Color(0, 0, 200));
    } else {
        pixel.setPixelColor(0, pixel.Color(200, 0, 0));
    }
    pixel.show();
}
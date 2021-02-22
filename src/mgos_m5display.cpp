#include "mgos_m5display.h"

#include <common/str_util.h>
#include <fonts/FreeSerif9pt7b.h>
#include <mgos.h>
#include <mgos_gpio.h>

MGOS_M5Display::MGOS_M5Display() : fgColor(ILI9341_WHITE), bgColor(ILI9341_BLACK) {}

void MGOS_M5Display::begin() {
    // GPIO.set_mode(LCD_BACKLIGHT, GPIO.MODE_OUTPUT);
    mgos_gpio_set_mode(M5_LCD_BACKLIGHT, MGOS_GPIO_MODE_OUTPUT);
    // GPIO.write(LCD_BACKLIGHT, 1);
    mgos_gpio_write(M5_LCD_BACKLIGHT, 1);

    // ILI9341.setOrientation(M5STACK_LANDSCAPE, 320, 240);
    mgos_ili9341_set_orientation(M5STACK_LANDSCAPE, 320, 240);
    mgos_ili9341_set_inverted(true);

    // ILI9341.fillScreen();
    fillScreen(bgColor);

    // ILI9341.setFont(fonts[1]);
    set_font(&FreeSerif9pt7b);  // Set font

    set_bgcolor565(bgColor);
    set_fgcolor565(fgColor);
}
void MGOS_M5Display::printf(uint16_t x0, uint16_t y0, const char *fmt, ...) {
    char buf[50], *s = buf;
    va_list ap;
    va_start(ap, fmt);
    if (mg_avprintf(&s, sizeof(buf), fmt, ap) > 0) {
        mgos_ili9341_print(x0, y0, s);
    }
    va_end(ap);
    if (s != buf) free(s);
}
void MGOS_M5Display::printf_col(uint16_t x0, uint16_t y0, uint16_t temp_fg_color, const char *fmt, ...) {
    char buf[50], *s = buf;
    va_list ap;
    va_start(ap, fmt);
    if (mg_avprintf(&s, sizeof(buf), fmt, ap) > 0) {
        mgos_ili9341_set_fgcolor565(temp_fg_color);
        mgos_ili9341_print(x0, y0, s);
        mgos_ili9341_set_fgcolor565(fgColor);
    }
    va_end(ap);
    if (s != buf) free(s);
}
void MGOS_M5Display::fillScreen(uint32_t color) {
    //塗りつぶし用に一旦カラー指定
    mgos_ili9341_set_fgcolor565(color);
    mgos_ili9341_fillScreen();
    mgos_ili9341_set_fgcolor565(fgColor);
}

void MGOS_M5Display::set_fgcolor565(uint16_t rgb) {
    mgos_ili9341_set_fgcolor565(rgb);
    fgColor = rgb;
}
void MGOS_M5Display::set_bgcolor565(uint16_t rgb) {
    mgos_ili9341_set_bgcolor565(rgb);
    bgColor = rgb;
}
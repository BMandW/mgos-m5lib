#ifndef _MGOS_M5DISPLAY_H_
#define _MGOS_M5DISPLAY_H_

#include <mgos_ili9341.h>

#define M5_LCD_BACKLIGHT 32

#define M5STACK_PORTRAIT (ILI9341_MADCTL_MV | ILI9341_MADCTL_MY)
#define M5STACK_LANDSCAPE (0x00)
#define M5STACK_PORTRAIT_FLIP (ILI9341_MADCTL_MV | ILI9341_MADCTL_MX)
#define M5STACK_LANDSCAPE_FLIP (ILI9341_MADCTL_MY | ILI9341_MADCTL_ML | ILI9341_MADCTL_MX)

void fillScreen(uint32_t);
class MGOS_M5Display {
   public:
    MGOS_M5Display();
    void begin();
    void clearDisplay() { fillScreen(bgColor); }
    bool set_font(GFXfont *f) { return mgos_ili9341_set_font(f); }
    void printf(uint16_t x0, uint16_t y0, const char *fmt, ...);
    void printf_col(uint16_t x0, uint16_t y0, uint16_t temp_fg_color, const char *fmt, ...);

    void set_fgcolor(uint8_t r, uint8_t g, uint8_t b) { set_fgcolor565(color565(r, g, b)); };
    void set_bgcolor(uint8_t r, uint8_t g, uint8_t b) { set_bgcolor565(color565(r, g, b)); };
    uint16_t color565(uint8_t r, uint8_t g, uint8_t b) { return mgos_ili9341_color565(r, g, b); };
    void set_fgcolor565(uint16_t rgb);
    void set_bgcolor565(uint16_t rgb);
    uint16_t get_fgcolor565() { return fgColor; };
    uint16_t get_bgcolor565() { return bgColor; };
    uint16_t get_screen_width() { return mgos_ili9341_get_screenWidth(); };
    uint16_t get_screen_height() { return mgos_ili9341_get_screenHeight(); };
    void fillScreen(uint32_t color);

    uint16_t get_string_width(const char *string) { return mgos_ili9341_getStringWidth(string); };
    uint16_t get_string_height(const char *string) { return mgos_ili9341_getStringHeight(string); };
    int get_max_font_width(void) { return mgos_ili9341_get_max_font_width(); };
    int get_max_font_height(void) { return mgos_ili9341_get_max_font_height(); };

    void draw_pixel(uint16_t x0, uint16_t y0) { mgos_ili9341_drawPixel(x0, y0); };
    void draw_line(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1) { mgos_ili9341_drawLine(x0, y0, x1, y1); }

    void draw_rect(uint16_t x0, uint16_t y0, uint16_t w, uint16_t h) { mgos_ili9341_drawRect(x0, y0, w, h); };
    void fill_rect(uint16_t x0, uint16_t y0, uint16_t w, uint16_t h) { mgos_ili9341_fillRect(x0, y0, w, h); };

    void draw_round_rect(uint16_t x0, uint16_t y0, uint16_t w, uint16_t h, uint16_t r) {
        mgos_ili9341_drawRoundRect(x0, y0, w, h, r);
    };
    void fill_round_rect(uint16_t x0, uint16_t y0, uint16_t w, uint16_t h, uint16_t r) {
        mgos_ili9341_fillRoundRect(x0, y0, w, h, r);
    };

    void draw_circle(uint16_t x0, uint16_t y0, uint16_t r) { mgos_ili9341_drawCircle(x0, y0, r); }
    void fill_circle(uint16_t x0, uint16_t y0, uint16_t r) { mgos_ili9341_fillCircle(x0, y0, r); }

    void draw_triangle(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2) {
        mgos_ili9341_drawTriangle(x0, y0, x1, y1, x2, y2);
    };
    void fill_triangle(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2) {
        mgos_ili9341_fillTriangle(x0, y0, x1, y1, x2, y2);
    };
    void drawDIF(uint16_t x0, uint16_t y0, char *fn) { mgos_ili9341_drawDIF(x0, y0, fn); };
    /**
     *  Returns Y position for line N for the currently selected font.
     * If n is negative, returns N-th line from the bottom.
     */
    uint16_t ypos_line(int n) { return mgos_ili9341_line(n); };

   private:
    uint16_t fgColor;
    uint16_t bgColor;
};
#endif
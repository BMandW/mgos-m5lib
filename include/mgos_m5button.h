
#ifndef _MGOS_M5BUTTON_H_
#define _MGOS_M5BUTTON_H_

#define M5_BTN_A_PIN 39
#define M5_BTN_B_PIN 38
#define M5_BTN_C_PIN 37

#define BUTTON_A 0
#define BUTTON_B 1
#define BUTTON_C 2

#define DEBOUNCE_MS 10
#include <mgos.h>
#include <mgos_gpio.h>

class MGOS_M5Button {
   public:
    MGOS_M5Button(uint8_t pin);

    bool set_button_handler(mgos_gpio_int_handler_f cb, void *arg);

   private:
    uint8_t _pin;
};
#endif
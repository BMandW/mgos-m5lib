#include "mgos_m5button.h"

#include <mgos.h>
#include <mgos_gpio.h>
#include <common/str_util.h>

MGOS_M5Button::MGOS_M5Button(uint8_t pin) : _pin(pin) {}
bool MGOS_M5Button::set_button_handler(mgos_gpio_int_handler_f cb, void *arg) {
    return mgos_gpio_set_button_handler(_pin, MGOS_GPIO_PULL_UP, MGOS_GPIO_INT_EDGE_NEG, DEBOUNCE_MS, cb, arg);
}

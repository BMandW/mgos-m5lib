#include "mgos_m5stack.h"

#include <mgos.h>

MGOS_M5Stack::MGOS_M5Stack() : isInited(false) {}

void MGOS_M5Stack::begin(bool LCDEnable) {
    LOG(LL_INFO, ("0"));
    if (isInited == true) {
        return;
    } else {
        isInited = true;
    }

    // LCD INIT
    if (LCDEnable == true) {
        Lcd.begin();
    }
}
MGOS_M5Stack MGOS_M5;
extern "C" bool mgos_mgos_m5lib_init() { return true; }
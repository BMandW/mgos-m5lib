#ifndef _MGOS_M5STACK_H_
#define _MGOS_M5STACK_H_

#include <mgos_ili9341.h>

#include "mgos_m5display.h"
#include "mgos_m5button.h"

class MGOS_M5Stack {
   public:
    MGOS_M5Stack();
    void begin(bool LCDEnable = true);
    void update();

    MGOS_M5Display Lcd = MGOS_M5Display();

    MGOS_M5Button BtnA = MGOS_M5Button(M5_BTN_A_PIN);
    MGOS_M5Button BtnB = MGOS_M5Button(M5_BTN_B_PIN);
    MGOS_M5Button BtnC = MGOS_M5Button(M5_BTN_C_PIN);

   private:
    bool isInited;
};
extern MGOS_M5Stack MGOS_M5;
#define mgos_m5 MGOS_M5;
#define lcd Lcd;
#endif
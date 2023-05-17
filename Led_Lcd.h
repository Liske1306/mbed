#ifndef LED_LCD
#define LED_LCD

#include "LCD_DISCO_F429ZI.h"

class LedLcd{
    public:
        LedLcd();
        void On(uint8_t);
    private:
        LCD_DISCO_F429ZI lcd;
};

#endif

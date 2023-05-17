#ifndef LED_LCD
#define LED_LCD

#include "LCD_DISCO_F429ZI.h"

class LedLcd{
    public:
        LedLcd(uint8_t = 0);
        void On(uint8_t);
    private:
        LCD_DISCO_F429ZI lcd;
        uint8_t ucRow;
};

#endif

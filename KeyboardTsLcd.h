#ifndef KEYBOARD_TS_LCD
#define KEYBOARD_TS_LCD

#include "Keyboard_Ts.h"
#include "Led_Lcd.h"

class KeyboardTsLcd{
    public:
        KeyboardTsLcd(uint8_t = 0);
        KeyboardButtons eRead();
    private:
        LedLcd* pLed;
        KeyboardTs* pKeyboard;
};

#endif

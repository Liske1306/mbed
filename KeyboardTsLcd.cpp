#include "KeyboardTsLcd.h"
#include "Keyboard_Ts.h"

KeyboardTsLcd::KeyboardTsLcd(unsigned char _ucColumn)
{
 pKeyboard = new KeyboardTs(_ucColumn);
 pLed = new LedLcd(_ucColumn);
}; 

KeyboardButtons KeyboardTsLcd::eRead(){
    KeyboardButtons ButtonClicked = pKeyboard->eRead();
    switch(ButtonClicked) {
        case BUTTON_0:
            pLed->On(0);
        break;
        case BUTTON_1:
            pLed->On(1);
        break;
        case BUTTON_2:
            pLed->On(2);
        break;
        case BUTTON_3:
            pLed->On(3);
        break;
        default :
            pLed->On(4);
        break;
        }
        return ButtonClicked;
}

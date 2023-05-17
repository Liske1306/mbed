#include "KeyboardTsLcd.h"

KeyboardTsLcd::KeyboardTsLcd(unsigned char _ucColumn)
{
 pKeyboard = new KeyboardTs(_ucColumn);
 pLed = new LedLcd(_ucColumn);
 pLedReverse = new LedLcd(2);
}; 

void KeyboardTsLcd::eRead(){
switch(pKeyboard->eRead()) {
    case BUTTON_0:
        pLed->On(0);
        pLedReverse->On(3);
    break;
    case BUTTON_1:
        pLed->On(1);
        pLedReverse->On(2);
    break;
    case BUTTON_2:
        pLed->On(2);
        pLedReverse->On(1);
    break;
    case BUTTON_3:
        pLed->On(3);
        pLedReverse->On(0);
    break;
    default :
        pLed->On(4);
        pLedReverse->On(4);
    break;
    }
}

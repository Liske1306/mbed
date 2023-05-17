#include "Keyboard_Ts.h"

KeyboardTs::KeyboardTs(uint8_t ucCurrentRow){
    ts.Init(240, 320);
    ucRow = ucCurrentRow;
}

KeyboardButtons KeyboardTs::eRead(){
    ts.GetState(&TS_State);      
    if (TS_State.TouchDetected && TS_State.X <= ((ucRow+1)*80) && TS_State.X >= (ucRow*80))
    {
        switch(TS_State.Y/80){
            case 0:
                return BUTTON_0;
            case 1:
                return BUTTON_1;
            case 2:
                return BUTTON_2;
            case 3:
                return BUTTON_3;
            default:
                return RELEASED;
        }
    }
    return RELEASED;
}

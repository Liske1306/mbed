#include "Keyboard_Ts.h"

#define ButtonWidth 80
#define ButtonHeight 80
#define ScreenSizeX 240
#define ScreenSizeY 320

KeyboardTs::KeyboardTs(uint8_t ucCurrentRow){
    ts.Init(ScreenSizeX, ScreenSizeY);
    ucRow = ucCurrentRow;
}

KeyboardButtons KeyboardTs::eRead(){
    ts.GetState(&TS_State);
    KeyboardButtons arrButtons[4] = {BUTTON_0, BUTTON_1, BUTTON_2, BUTTON_3};

    if (TS_State.TouchDetected && TS_State.X <= ((ucRow+1)*ButtonWidth) && TS_State.X >= (ucRow*ButtonWidth))
    {
        return arrButtons[TS_State.Y/ButtonHeight];
    }
    return RELEASED;
}

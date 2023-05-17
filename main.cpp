#include "Keyboard_Ts.h"
#include "Led_Lcd.h"
#include "mbed.h"
#include "KeyboardTsLcd.h"

int main()
{
 KeyboardTsLcd Keyboard(0);
 while(1) {
    Keyboard.eRead();
    wait(0.1);
 }
} 

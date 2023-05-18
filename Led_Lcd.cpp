#include "Led_Lcd.h"

#define ButtonWidth 80
#define ButtonHeight 80

LedLcd::LedLcd(uint8_t ucCurrentRow){
    lcd.Clear(LCD_COLOR_BLACK);
    ucRow = ucCurrentRow;
    lcd.SetFont(&Font24);
}

void LedLcd::DrawKeyboardTile(uint8_t ucButtonNumber, uint64_t ucColor){
       lcd.SetTextColor(ucColor);
       lcd.FillRect(ucRow*ButtonWidth, ucButtonNumber*ButtonHeight, ButtonWidth, ButtonHeight);
       lcd.SetTextColor(LCD_COLOR_GREEN);
       lcd.DrawRect(ucRow*ButtonWidth, ucButtonNumber*ButtonHeight, ButtonWidth, ButtonHeight);
       lcd.SetTextColor(LCD_COLOR_WHITE);
       lcd.SetBackColor(LCD_COLOR_RED);
       lcd.DisplayChar(ucRow*ButtonWidth, ucButtonNumber*ButtonHeight, 48+ucButtonNumber);
}

void LedLcd::On(uint8_t ucButtonActive){
    for(uint8_t ucButtonNumber=0;ucButtonNumber<=3;ucButtonNumber++){
       DrawKeyboardTile(ucButtonNumber, LCD_COLOR_BLUE);
    }
    DrawKeyboardTile(ucButtonActive, LCD_COLOR_GREEN);
}

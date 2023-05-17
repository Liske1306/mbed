#include "Led_Lcd.h"

LedLcd::LedLcd(uint8_t ucCurrentRow){
    lcd.Clear(LCD_COLOR_BLACK);
    ucRow = ucCurrentRow;
}

void LedLcd::On(uint8_t ucButtonNumber){
    lcd.SetFont(&Font24);
    for(uint8_t ucButtonInit=0;ucButtonInit<=3;ucButtonInit++){
       lcd.SetTextColor(LCD_COLOR_BLUE);
       lcd.FillRect(ucRow*80, ucButtonInit*80, 80, 80);
       lcd.SetTextColor(LCD_COLOR_GREEN);
       lcd.DrawRect(ucRow*80, ucButtonInit*80, 80, 80);
       lcd.SetTextColor(LCD_COLOR_WHITE);
       lcd.SetBackColor(LCD_COLOR_RED);
       lcd.DisplayChar(ucRow*80, ucButtonInit*80, 48+ucButtonInit);
    }
    lcd.SetTextColor(LCD_COLOR_GREEN);
    lcd.FillRect(ucRow*80, ucButtonNumber*80, 80, 80);
    lcd.SetTextColor(LCD_COLOR_WHITE);
    lcd.SetBackColor(LCD_COLOR_RED);
    lcd.DisplayChar(ucRow*80, ucButtonNumber*80, 48+ucButtonNumber);
}

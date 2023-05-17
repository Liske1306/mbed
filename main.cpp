#include "mbed.h"
#include "TS_DISCO_F429ZI.h"
#include "LCD_DISCO_F429ZI.h"

LCD_DISCO_F429ZI lcd;
TS_DISCO_F429ZI ts;

int main()
{
    TS_StateTypeDef TS_State;
    uint16_t x;
    uint16_t y;
  
    BSP_LCD_SetFont(&Font24);
  
    ts.Init(lcd.GetXSize(), lcd.GetYSize());
    
    while(1)
    {
    lcd.Clear(LCD_COLOR_BLACK);
      for(uint8_t ucButtonNumber=0;ucButtonNumber<=3;ucButtonNumber++){
        lcd.SetTextColor(LCD_COLOR_BLUE);
        lcd.FillRect(0, ucButtonNumber*80, 80, 80);
        lcd.SetTextColor(LCD_COLOR_GREEN);
        lcd.DrawRect(0, ucButtonNumber*80, 80, 80);
        lcd.SetTextColor(LCD_COLOR_WHITE);
        lcd.SetBackColor(LCD_COLOR_RED);
        lcd.DisplayChar(0, ucButtonNumber*80, 48+ucButtonNumber);
      }     
      ts.GetState(&TS_State);      
      if (TS_State.TouchDetected)
      {
        x = TS_State.X;
        y = TS_State.Y/80;
        if(x<=80){
            lcd.SetTextColor(LCD_COLOR_GREEN);
            lcd.FillRect(0, y*80, 80, 80);
            lcd.SetTextColor(LCD_COLOR_WHITE);
            lcd.SetBackColor(LCD_COLOR_RED);
            lcd.DisplayChar(0, y*80, 48+y);
        }
      }
      wait(0.1);
    }
}

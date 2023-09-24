
#include "ev3api.h"
#include "app.h"

#include "libcpp-test.h"
#include "bignumber.h"


#define DEBUG

#ifdef DEBUG
#define _debug(x) (x)
#else
#define _debug(x)
#endif

void print(int line, const char* msg)
{
    // Draw information
    lcdfont_t font = EV3_FONT_MEDIUM;
    ev3_lcd_set_font(font);
    int32_t fontw, fonth;
    ev3_font_get_size(font, &fontw, &fonth);
    const char* lcdclean = "                    ";
    
    ev3_lcd_draw_string(lcdclean, 0, fonth * line);
    ev3_lcd_draw_string(msg, 0, fonth * line);
}

void clearScreen()
{
    ev3_lcd_fill_rect(0, 0, EV3_LCD_WIDTH, EV3_LCD_HEIGHT, EV3_LCD_WHITE);
}

void main_task(intptr_t unused) {
    BigNumber bignumber;
    while(true)
    {
        for(int n = 99; n >= 0; n--)
        {
            clearScreen();
            bignumber.draw(n);
            
            tslp_tsk(250);
        }
    }
}

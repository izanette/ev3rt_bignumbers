
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

BigNumber bignumber;

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

static int counter = 91;

void update_counter(intptr_t exinf)
{
    clearScreen();
    if (counter >= 0)
        bignumber.draw(--counter);
}

void main_task(intptr_t unused) {
    while(true)
    {
        clearScreen();
        print(1, "starting cycle");
        print(2, "in 1 second");
        tslp_tsk(1000);

        ev3_sta_cyc(EV3_UPDATE_COUNTER);
        tslp_tsk(10000);
        ev3_stp_cyc(EV3_UPDATE_COUNTER);

        clearScreen();
        print(1, "stopping cycle");
        print(2, "after 10 seconds");
        tslp_tsk(1000);
        
        // runs until it reaches 0
        ev3_sta_cyc(EV3_UPDATE_COUNTER);
        while(counter > 0)
        {
            tslp_tsk(10);
        }
        ev3_stp_cyc(EV3_UPDATE_COUNTER);
        
        counter = 91;
    }
}

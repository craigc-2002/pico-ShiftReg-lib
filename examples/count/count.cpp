#include "ShiftReg.hpp"
#include <stdio.h>
#include "pico/stdlib.h"

ShiftReg shift_reg(0, 1, 2);

int main(void)
{
    stdio_init_all();
    while (true)
    {
        /*for (int i=0; i<7; i++)
        {
            shift_reg.send_bit(1);
            sleep_ms(100);
        }
        
        for (int i=0; i<7; i++)
        {
            shift_reg.send_bit(0);
            sleep_ms(100);
        }*/

        for (int i=0; i<256; i++)
        {
            shift_reg.send_byte(i);
            shift_reg.latch();
            sleep_ms(500);
        }
    }
}

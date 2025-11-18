#include "stdint.h"
#include "bsp_gpio.h"


void delay(void)
{
    for(int i = 0; i < 1000; i++)
    {
        for(int j = 0; j < 1000; j++);
    }
}


int main()
{
    gpio_initiate();
    while(1)
    {
        gpio_toggle();
        delay();
    }
}












// end of file


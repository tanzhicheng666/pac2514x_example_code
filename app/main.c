#include "stdint.h"
#include "bsp_gpio.h"
#include "bsp_uart.h"
#include "bsp_sysclk.h"

void delay(void)
{
    for(int i = 0; i < 1000; i++)
    {
        for(int j = 0; j < 1000; j++);
    }
}


int main()
{
    
    sys_clock_initiate();
    
    gpio_initiate();
    
    uart_initiate();
    while(1)
    {
        gpio_toggle();
        //delay();
        
        if(uart_read(0) == 0xAA)
        {
            uart_write(0xbb, 0);
        }
    }
}












// end of file


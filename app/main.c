#include "stdint.h"
#include "bsp_gpio.h"
#include "bsp_uart.h"
#include "bsp_sysclk.h"
#include "bsp_systick.h"

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
    
    systick_init();
    
    gpio_initiate();
    
    uart_initiate();
    
    while(1)
    {
        if(systick_obj.g_systick_1s_flag == 1)
        {
            systick_obj.g_systick_1s_flag = 0;
            gpio_toggle();
        }

        //delay();
        
//        if(uart_read(0) == 0xAA)
//        {
//            uart_write(0xff, 0);
//        }
    }
}












// end of file


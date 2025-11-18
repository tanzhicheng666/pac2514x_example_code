#include "bsp_gpio.h"
#include "pac_driver_gpio.h"

/**
***********************************************************
* @brief gpio_initiate
* @param
* @return 
***********************************************************
*/
void gpio_initiate(void)
{
    // GPIOG0/1/2 are LED driver IO, High = ON, Low = OFF
    PAC_GPIOG->MODE.P0 = IO_PUSH_PULL_OUTPUT;
    PAC_GPIOG->OUT.P0 = 0;
    
}


/**
***********************************************************
* @brief gpio_toggle
* @param
* @return 
***********************************************************
*/
void gpio_toggle(void)
{
    PAC_GPIOG->OUT.P0 ^= 1;
}

/**
***********************************************************
* @brief gpio_on
* @param
* @return 
***********************************************************
*/
void gpio_on(void)
{
    PAC_GPIOG->OUT.P0 = 1;
}

/**
***********************************************************
* @brief gpio_off
* @param
* @return 
***********************************************************
*/
void gpio_off(void)
{
    PAC_GPIOG->OUT.P0 = 0;
}






























// end of file 


#include "bsp_systick.h"
#include "bsp_sysclk.h"
#include "pac.h"

stc_systick_class_t systick_obj = {0};

void systick_init(void)
{
    SysTick->LOAD = stc_sysclk_obj.sysclk_hclk / 1000;
    SysTick->VAL = 0;
    SysTick->CTRL |= SysTick_CTRL_CLKSOURCE_Msk;
    SysTick->CTRL |= SysTick_CTRL_TICKINT_Msk;
    SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
    
    NVIC_SetPriority(SysTick_IRQn, 0);
}

void SysTick_Handler(void)
{
    systick_obj.g_systick++;
    systick_obj.g_systick_1s++;
    if(systick_obj.g_systick_1s >= 1000)
    {
        systick_obj.g_systick_1s = 0;
        systick_obj.g_systick_1s_flag = 1;
    }
}

uint32_t systick_get_tick(void)
{
    return systick_obj.g_systick;
}




























// end of file


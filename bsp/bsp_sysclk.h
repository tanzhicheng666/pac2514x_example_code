#ifndef __BSP_SYSCLK_H
#define __BSP_SYSCLK_H
#include "stdint.h"

typedef struct 
{
    uint32_t sysclk_pllclk;
    uint32_t sysclk_frclk;
    uint32_t sysclk_sclk;
    uint32_t sysclk_hclk;
    uint32_t sysclk_pclk;
    uint32_t sysclk_aclk;
}stc_sysclk_t;

extern stc_sysclk_t stc_sysclk_obj;


void sys_clock_initiate(void);







#endif

// end of file


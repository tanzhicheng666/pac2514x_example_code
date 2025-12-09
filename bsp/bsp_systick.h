#ifndef __BSP_SYSTICK_H
#define __BSP_SYSTICK_H
#include "stdint.h"


typedef struct
{
    uint32_t g_systick;
    uint16_t g_systick_1s;
    uint8_t  g_systick_1s_flag;
}stc_systick_class_t;



void systick_init(void);



extern stc_systick_class_t systick_obj;








#endif 

// end of file 


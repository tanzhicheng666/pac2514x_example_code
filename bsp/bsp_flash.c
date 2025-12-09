#include "bsp_flash.h"
#include "stdint.h"
#include "pac.h"


void bsp_flash_write(uint8_t *p_dest, uint8_t *p_src, uint32_t size_bytes)
{
    uint8_t i;
    uint32_t src_index;
    uint8_t buff_index;
    uint32_t *p_flash_write;
    
    PAC_MEMCTL->FLASHLOCK = FLASH_LOCK_ALLOW_WRITE_MEMCTL;
    PAC_MEMCTL->MEMCTL.WRITEWORDCNT = 0;
    
    PAC_MEMCTL->FLASHLOCK = FLASH_LOCK_ALLOW_WRITE_ERASE_FLASH;
}



























// end of file 


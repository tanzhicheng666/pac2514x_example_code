#include "bsp_sysclk.h"
#include "stdint.h"
#include "pac_driver_system.h"





void sys_clock_initiate(void)
{
    // Set Flash Lock to allow write access to MEMCTL register for configuring clocks
    PAC_MEMCTL->FLASHLOCK = FLASH_LOCK_ALLOW_WRITE_MEMCTL;

    // Turn on Flache Cache
    PAC_MEMCTL->MEMCTL.CACHEDIS = 0;                        // enable Flash CACHE

    // Select 4 MHz CLKREF for Free Running Clock FRCLK
    PAC_SCC->CCSCTL.FRCLKMUXSEL = CCSCTL_CLKIN_CLKREF;

    pac_sys_pll_config_enable(4, 300, 0);                   // PLLCLK = 300 MHz = (4/4 * 300) /1

    // Configure SCLK=PLLCLK=300 MHz, HCLK=150 MHz, PCLK=150 MHz, ACLK=50 MHz and WaitStates;  Use default PCLKDIV=1
    PAC_SCC->CCSCTL.HCLKDIV = CCSCTL_HCLKDIV_DIV2;          // HCLK = 150 MHz = SCLK/2; when SCLK = PLLCLK
    PAC_SCC->CCSCTL.SCLKMUXSEL = CCSCTL_SCLK_PLLCLK;        // SCLK = PLLCLK

    PAC_MEMCTL->MEMCTL.WSTATE = 5 + 1;                      // Flash = 150/25 = 6 clocks = 5 WS; So, need 5 + 1 Extra WS
    PAC_MEMCTL->MEMCTL.MCLKDIV = MEMCTL_MCLK_DIV5;
    PAC_MEMCTL->MEMCTL.MCLKSEL = MEMCTL_MCLK_HCLKDIV;
    PAC_MEMCTL->FLASHLOCK = 0;                              // Disallow write access to MEMCTL
}








































// end of file


#include "bsp_sysclk.h"
#include "pac_driver_system.h"

stc_sysclk_t stc_sysclk_obj;


void sys_clock_initiate(void)
{
 	// Turn ON ROSC
	PAC_SCC->CCSCTL.ROSCEN = 1;

	// Set Flash Lock to allow write access to MEMCTL register for configuring clocks
    PAC_MEMCTL->FLASHLOCK = FLASH_LOCK_ALLOW_WRITE_MEMCTL;

    // Set safe clock defaults
    PAC_SCC->CCSCTL.FRCLKMUXSEL = CCSCTL_CLKIN_ROSC;
    PAC_SCC->CCSCTL.SCLKMUXSEL = CCSCTL_SCLK_FRCLK;
    PAC_MEMCTL->MEMCTL.MCLKSEL = MEMCTL_MCLK_ROSCCLK;

    // Turn on Flache Cache
    PAC_MEMCTL->MEMCTL.CACHEDIS = 0; // enable Flash CACHE

    // Select 4 MHz CLKREF for Free Running Clock FRCLK
    PAC_SCC->CCSCTL.FRCLKMUXSEL = CCSCTL_CLKIN_CLKREF;


    pac_sys_pll_config_enable(4, 300, 0); // PLLCLK = 300 MHz = (4/4 * 300) /1

    // Configure SCLK=PLLCLK=300 MHz, HCLK=150 MHz, PCLK=150 MHz, ACLK=50 MHz and WaitStates;  Use default PCLKDIV=1
    PAC_SCC->CCSCTL.HCLKDIV = CCSCTL_HCLKDIV_DIV2;   // HCLK = 150 MHz = SCLK/2; when SCLK = PLLCLK
    PAC_SCC->CCSCTL.ACLKDIV = CCSCTL_ACLKDIV_DIV6;   // ACLK =  50 MHz = SCLK/6; when SCLK = PLLCLK
    PAC_MEMCTL->MEMCTL.WSTATE = 5 + 1;               // Flash = 150/25 = 6 clocks = 5 WS; So, need 5 + 1 Extra WS
    PAC_SCC->CCSCTL.SCLKMUXSEL = CCSCTL_SCLK_PLLCLK; // SCLK = PLLCLK

    // Set MCLK for Flash write & erase in addition to read
    PAC_MEMCTL->MEMCTL.MCLKDIV = MEMCTL_MCLK_DIV5;    // MCLK will = HCLK/5 when MCLKSEL = MEMCTL_MCLK_HCLKDIV
    PAC_MEMCTL->MEMCTL.MCLKSEL = MEMCTL_MCLK_HCLKDIV; // MCLK = HCLK/5 = 30 MHz; allows reading and writing of Flash


    // Enable GPIO Input clock synchronization; should always be enabled, especially when using GPIO edge based interrupts
    PAC_GPIOA->CLKSYNC.w = 0xFF;
    PAC_GPIOB->CLKSYNC.w = 0xFF;
    PAC_GPIOC->CLKSYNC.w = 0xFF;
    PAC_GPIOD->CLKSYNC.w = 0xFF;
    PAC_GPIOE->CLKSYNC.w = 0xFF;
    PAC_GPIOF->CLKSYNC.w = 0xFF;
    PAC_GPIOG->CLKSYNC.w = 0xFF;

    // Turn OFF ROSC
    PAC_SCC->CCSCTL.ROSCEN = 0;
    PAC_SCC->CCSCTL.XTALEN = 0; // Disallow write access to MEMCTL
    
    stc_sysclk_obj.sysclk_frclk = 4000000;
    stc_sysclk_obj.sysclk_pllclk = 300000000;
    stc_sysclk_obj.sysclk_sclk = 300000000;
    stc_sysclk_obj.sysclk_hclk = 150000000;
    stc_sysclk_obj.sysclk_pclk = 150000000;
    stc_sysclk_obj.sysclk_aclk = 50000000;
}








































// end of file


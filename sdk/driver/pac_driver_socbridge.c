/**************************************************************************//**
 * @file     pac_driver_socbridge_config.c
 * @brief    Firmware driver for the PAC SOC Bridge
 *
 * @note
 * Copyright (C) 2015-2019, Qorvo, Inc.
 *
 * THIS SOFTWARE IS SUBJECT TO A SOURCE CODE LICENSE AGREEMENT WHICH PROVIDES,
 * AMONG OTHER THINGS:  (i) THAT IT CAN BE USED ONLY TO ADAPT THE LICENSEE'S
 * APPLICATION TO PAC PROCESSORS SUPPLIED BY QORVO, INC.;
 * (ii) THAT  IT IS PROVIDED "AS IS" WITHOUT WARRANTY;  (iii) THAT
 * QORVO, INC. IS NOT LIABLE FOR ANY INDIRECT DAMAGES OR FOR DIRECT
 * DAMAGES EXCEEDING US$1,500;  AND (iv) THAT IT CAN BE DISCLOSED TO AND USED
 * ONLY BY CERTAIN AUTHORIZED PERSONS.
 *
 ******************************************************************************/

#include "pac_driver_socbridge.h"

RAMFUNC_SOCBRIDGE void pac_socbridge_config(int enable, int int_enable)
{
    PAC_SCC->CCSCTL.USAMODE = 0;            // SET SSPA to SPI mode
    PAC_SSPA->CLK.M = 2;                 // PCLK/((SSPxCLK.M + 1)*SSPxCLK.N)
    PAC_SSPA->CLK.N = 2;                 // N nust be event value from 2 to 254 	
    PAC_SSPA->CON.FRF = 0;               // Frame Format, SPI frame format
    PAC_SSPA->CON.MS = 0;                // Master/Slave mode, master mode
    PAC_SSPA->CON.LSBFIRST = 0;          // Endian Order, MSB transmit 1st
    PAC_SSPA->CON.LBM = 0;               // Loobback Mode, no loopback mode
    PAC_SSPA->CON.CPH = 0;               // Clock Out Phase, SPI captuers data sat 1st edge transition of the frame
    PAC_SSPA->CON.CPO = 0;               // Clock Out Polarity, SPI clock active high
    PAC_SSPA->CON.DSS = 0xF;             // Data Size Select, 16 bit data
    PAC_SSPA->CON.SOD = 1;               // Slave Output Disable
    PAC_SSPA->SSCR.SELSS = 0;            // Slave Select Signal Control
    PAC_SSPA->SSCR.SWSEL = 0;            // Slave Select controlled by SPI
    PAC_SSPA->SSCR.SWSS = 0;             // Slave Select State, Low active
    PAC_SSPA->SSCR.SPHDONTCARE = 1;      // Slave Select Pull High
    if (int_enable)
    {
        NVIC_ClearPendingIRQ(USARTA_IRQn);
        NVIC_EnableIRQ(USARTA_IRQn);
    }
    PAC_SSPA->CON.SSPEN = enable;        // SSP Enable	
}

RAMFUNC_SOCBRIDGE void pac_socbridge_config_io(void)
{

    // ICBSS:    PAMUXSEL.P6 = 001b (PA6 - output)
    // ICBMISO:  PAMUXSEL.P5 = 001b (PA5 - input)
    // ICBMOSI:  PAMUXSEL.P4 = 001b (PA4 - output)
    // ICBCLK:   PAMUXSEL.P3 = 001b (PA3 - output)

    PAC_SCC->PAMUXSEL.w &= 0xF0000FFF;      // Clear PMUX for SSP bits
    PAC_SCC->PAMUXSEL.w |= 0x01111000;      // PA6 = ICBSS, PA5 = ICBMISO, PA4 = ICBMOSI, PA3 = ICBCLK

    // Select SSP peripherals
    PAC_GPIOA->MODE.P3 = 1;                 // SCLK
    PAC_GPIOA->MODE.P6 = 1;                 // SS
    PAC_GPIOA->MODE.P4 = 1;                 // MOSI
    PAC_GPIOA->MODE.P5 = 3;                 // MISO
}

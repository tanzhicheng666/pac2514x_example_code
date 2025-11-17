/**************************************************************************/ /**
 * @file     pac_driver_tile_socbridge.c
 * @brief    Firmware driver for the PAC tile read/write registers via SOC Bridge
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

#include "pac_driver_tile.h"
#include "pac_driver_socbridge.h"

RAMFUNC_TILE void pac_tile_socbridge_config(int enable, int int_enable)
{
    // Configure SOC Bridge
    pac_socbridge_config(enable, int_enable); // Enabled

    pac_socbridge_config_io(); // Enable SPI IOs
}

RAMFUNC_TILE void pac_tile_register_write_bit(uint32_t addr, uint32_t bit_pos, uint32_t bit_value)
{
    uint32_t data;
    data = pac_tile_register_read(addr);
    data = data & ~(1 << bit_pos);
    data = data | (bit_value << bit_pos);
    pac_tile_register_write(addr, (uint8_t)data);
}

RAMFUNC_TILE void pac_tile_register_write_bits(uint32_t addr, uint32_t bit_pos, uint32_t bits_mask, uint32_t value)
{
    uint32_t data;
    data = pac_tile_register_read((uint8_t)addr);
    data = data & ~bits_mask;
    data = data | (value << bit_pos);
    pac_tile_register_write((uint8_t)addr, (uint8_t)data);
}

// To optimize only the tile write, force function in RAM by replacing RAMFUNC_TILE with PAC_RAMFUNC
RAMFUNC_TILE void pac_tile_register_write(uint8_t address, uint8_t data)
{
    volatile unsigned int data_read;
    __disable_irq();
    // Ensure no transmission is pending
    while (!PAC_SSPA->STAT.TNF)
        ;

    // Write 16-bits containing Addr, R/W=1, Data
    // Format: Addr(15:9) | R/W(8) | Data(7:0)
    PAC_SSPA->DAT.DATA = (address << 9) | (1 << 8) | data;

    // Wait for transmission to be complete
    while (!PAC_SSPA->STAT.TNF)
        ;

    // Must empty receive buffer
    while (!PAC_SSPA->STAT.RNE)
        ;                           // Wait for receive data ready
    data_read = PAC_SSPA->DAT.DATA; // Read receive buffer data
    __enable_irq();
    (void)data_read; // Added to prevent compiler warnings about the variable being set but not unused
}

// To optimize only the tile read, force function in RAM by replacing RAMFUNC_TILE with PAC_RAMFUNC
RAMFUNC_TILE uint8_t pac_tile_register_read(uint8_t address)
{
    uint8_t data;
    __disable_irq();
    // Send SPI address with address 7 bit; first 9 bits are 1 bit read-write and 8 bit data
    PAC_SSPA->DAT.DATA = (address << 9);

    // Wait for transmission to be complete
    while (!PAC_SSPA->STAT.TNF)
        ;

    // Wait for receive data ready
    while (!PAC_SSPA->STAT.RNE)
        ;

    data = PAC_SSPA->DAT.DATA;
    __enable_irq();
    // Return read data
    return data;
}

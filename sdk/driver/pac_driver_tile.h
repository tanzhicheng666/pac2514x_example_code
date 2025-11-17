/**************************************************************************//**
 * @file     pac_driver_tile.h
 * @brief    Firmware driver for communications with analog tiles
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

#ifndef PAC_DRIVER_TILE_H
#define PAC_DRIVER_TILE_H

/** @addtogroup PAC_Driver_Tile
  @{
*/

#include "pac.h"
#include "pac_driver_config.h"

#ifdef PAC_DRIVER_TILE_RAM
#define RAMFUNC_TILE	PAC_RAMFUNC
#else 
#define RAMFUNC_TILE
#endif

/**
 * @brief  This function writes to tile register with position
 *
 * @param  address Register address to write
 * @param  bit_pos Bit position
 * @param  bit_value Data to write
 * @return 0: success, non-zero: failure
 *
 * @note The user must configure interrupts for the SOC Bridge interface after calling this function
 *       and is responsible for registering the Cortex interrupts and providing the interrupt handlers.
 */
RAMFUNC_TILE void pac_tile_register_write_bit(uint32_t addr, uint32_t bit_pos, uint32_t bit_value);

/**
 * @brief  This function writes to tile register with position and mask
 *
 * @param  address Register address to write
 * @param  bit_pos Bit position
 * @param  bits_mask  Bit Mask
 * @param  value Data to write
 * @return 0: success, non-zero: failure
 *
 * @note The user must configure interrupts for the SOC Bridge interface after calling this function
 *       and is responsible for registering the Cortex interrupts and providing the interrupt handlers.
 */
RAMFUNC_TILE void pac_tile_register_write_bits(uint32_t addr, uint32_t bit_pos, uint32_t bits_mask, uint32_t value);

/**
 * @brief	This function reads a tile register via polling
 *
 * @param	address Register address to read from
 * @return	Data read from register
 */
RAMFUNC_TILE uint8_t pac_tile_register_read(uint8_t address);

/**
 * @brief  This function writes a tile register
 *
 * @param  address Register address to write
 * @param  data Data to write
 * @return 0: success, non-zero: failure
 *
 * @note The user must configure interrupts for the SOC Bridge interface after calling this function
 *       and is responsible for registering the Cortex interrupts and providing the interrupt handlers.
 */
RAMFUNC_TILE void pac_tile_register_write(uint8_t address, uint8_t data);

/**
 * @brief  This function configures the device for configuration with the Analog tiles via SOC Bridge
 *
 * @param  enable Set to 1 to enable SOC Bridge
 * @param  int_enable Set to 1 to enable interrupts for SOC bridge
 * @return none
 *
 */
RAMFUNC_TILE void pac_tile_socbridge_config(int enable, int int_enable);

/*@}*/ /* end of group PAC_Driver_Tile */

#endif // PAC_DRIVER_TILE_H


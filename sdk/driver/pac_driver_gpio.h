/**************************************************************************//**
 * @file     pac_driver_gpio.h
 * @brief    Firmware driver for the PAC GPIO
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
 
#ifndef PAC_DRIVER_GPIO_H
#define PAC_DRIVER_GPIO_H

/** @addtogroup PAC_Driver_GPIO 
  @{
*/

#include "pac.h"
#include "pac_driver_config.h"

#ifdef PAC_DRIVER_GPIO_RAM
#define RAMFUNC_GPIO PAC_RAMFUNC
#else
#define RAMFUNC_GPIO
#endif

// Type enumerations

/**
 * @brief  This function configures interrupts for the given pins on the given port and enables them.
 *
 * @param  pin_mask Mask of pins to configure and enable interrupts for
 * @param  active_high_mask Mask of pins to set to active high interrupts
 *
 * @return None
 */
RAMFUNC_GPIO void pac_gpio_configure_interrupt_a(uint8_t port_mask, uint8_t active_high_mask);
RAMFUNC_GPIO void pac_gpio_configure_interrupt_b(uint8_t port_mask, uint8_t active_high_mask);
RAMFUNC_GPIO void pac_gpio_configure_interrupt_c(uint8_t port_mask, uint8_t active_high_mask);
RAMFUNC_GPIO void pac_gpio_configure_interrupt_d(uint8_t port_mask, uint8_t active_high_mask);
RAMFUNC_GPIO void pac_gpio_configure_interrupt_e(uint8_t port_mask, uint8_t active_high_mask);
RAMFUNC_GPIO void pac_gpio_configure_interrupt_f(uint8_t port_mask, uint8_t active_high_mask);
RAMFUNC_GPIO void pac_gpio_configure_interrupt_g(uint8_t port_mask, uint8_t active_high_mask);

/*@}*/ /* end of group PAC_Driver_GPIO */

#endif // PAC_DRIVER_GPIO_H


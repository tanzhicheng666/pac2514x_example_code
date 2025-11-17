/**************************************************************************//**
 * @file     pac_driver_can.h
 * @brief    Driver functions for the PAC CAN Peripheral
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
 
#ifndef PAC_DRIVER_CAN_H
#define PAC_DRIVER_CAN_H

/*------------- Controller Area Network (CAN) ----------------------*/
/** @addtogroup PAC_Driver_CAN PAC CAN
  @{
*/

#include "pac.h"
#include "pac_driver_config.h"

#ifdef PAC_DRIVER_CAN_RAM
#define RAMFUNC_CAN	PAC_RAMFUNC
#else 
#define RAMFUNC_CAN
#endif

// Type enumerations

typedef enum {
	CAN_FILTER_DUAL = 0,
	CAN_FILTER_SINGLE = 1,
} CAN_Filter_Type; 

typedef enum {
	CAN_SAMPLE_1 = 0,
	CAN_SAMPLE_3 = 1,
} CAN_BusSample_Type; 

typedef enum {
	CAN_FRAME_STANDARD = 0,
	CAN_FRAME_EXTENDED = 1,
} CAN_FrameFormat_Type; 

/**
 * @brief  This function sets reset mode active/inactive
 *
 * @param  active Set to 1 to activate reset mode, set to 0 to inactivate
 *
 * @return none
 */
RAMFUNC_CAN static inline void pac_can_reset_mode_set(int active) { PAC_CAN->MR.RM = active; };

/**
 * @brief  This function sets transmit request 
 *
 * @param  none
 *
 * @return none
 */
RAMFUNC_CAN static inline void pac_can_transmit_request(void) { PAC_CAN->ISR_SR_CMR_MR = (PAC_CAN->ISR_SR_CMR_MR & 0x00FFFFFF) | CMR_TR; };

/**
 * @brief  This function sets transmission abort
 *
 * @param  none
 *
 * @return none
 */
RAMFUNC_CAN static inline void pac_can_transmission_abort(void) { PAC_CAN->ISR_SR_CMR_MR = (PAC_CAN->ISR_SR_CMR_MR & 0x00FFFFFF) | CMR_AT; };


//RAMFUNC_CAN int pac_can_status_BS(void) { return PAC_CAN->SR.BS; };

//RAMFUNC_CAN int pac_can_status_ES(void) { return PAC_CAN->SR.ES; };

//RAMFUNC_CAN int pac_can_status_TS(void) { return PAC_CAN->SR.TS; };

//RAMFUNC_CAN int pac_can_status_RS(void) { return PAC_CAN->SR.RS; };

//RAMFUNC_CAN int pac_can_status_TBS(void) { return PAC_CAN->SR.TBS; };

//RAMFUNC_CAN int pac_can_status_DSO(void) { return PAC_CAN->SR.DSO; };

//RAMFUNC_CAN int pac_can_status_RBS(void) { return PAC_CAN->SR.RBS; };

/**
 * @brief  This function masks all interrupts
 *
 * @param  none
 * @return none
 *
 */
RAMFUNC_CAN static inline void pac_can_int_mask_all(void) { PAC_CAN->IMR.b = 0x00; };


/**
 * @brief  This function clears the data overflow interrupt flag
 *
 * @param  none
 * @return none
 *
 */
RAMFUNC_CAN static inline void pac_can_int_clear_DOI(void) { PAC_CAN->ISR_SR_CMR_MR = (PAC_CAN->ISR_SR_CMR_MR & 0x00FFFFFF) | ISR_DOI; };

/**
 * @brief  This function clears the bus error interrupt flag
 *
 * @param  none
 * @return none
 *
 */
RAMFUNC_CAN static inline void pac_can_int_clear_BEI(void) { PAC_CAN->ISR_SR_CMR_MR = (PAC_CAN->ISR_SR_CMR_MR & 0x00FFFFFF) | ISR_BEI; };

/**
 * @brief  This function clears the transmit interrupt flag
 *
 * @param  none
 * @return none
 *
 */
RAMFUNC_CAN static inline void pac_can_int_clear_TI(void) { PAC_CAN->ISR_SR_CMR_MR = (PAC_CAN->ISR_SR_CMR_MR & 0x00FFFFFF) | ISR_TI; };

/**
 * @brief  This function clears the receive interrupt flag
 *
 * @param  none
 * @return none
 *
 */
RAMFUNC_CAN static inline void pac_can_int_clear_RI(void) { PAC_CAN->ISR_SR_CMR_MR = (PAC_CAN->ISR_SR_CMR_MR & 0x00FFFFFF) | ISR_RI; };

/**
 * @brief  This function clears the error passive interrupt flag
 *
 * @param  none
 * @return none
 *
 */
RAMFUNC_CAN static inline void pac_can_int_clear_EPI(void) { PAC_CAN->ISR_SR_CMR_MR = (PAC_CAN->ISR_SR_CMR_MR & 0x00FFFFFF) | ISR_EPI; };

/**
 * @brief  This function clears the error warning interrupt flag
 *
 * @param  none
 * @return none
 *
 */
RAMFUNC_CAN static inline void pac_can_int_clear_EWI(void) { PAC_CAN->ISR_SR_CMR_MR = (PAC_CAN->ISR_SR_CMR_MR & 0x00FFFFFF) | ISR_EWI; };

/**
 * @brief  This function clears the arbitration lost interrupt flag
 *
 * @param  none
 * @return none
 *
 */
RAMFUNC_CAN static inline void pac_can_int_clear_ALI(void) { PAC_CAN->ISR_SR_CMR_MR = (PAC_CAN->ISR_SR_CMR_MR & 0x00FFFFFF) | ISR_ALI; };

/**
 * @brief
 *
 * @param  brp
 * @param  sjw
 * @param  tseg1
 * @param  tseg2
 * @param  sample
 * @return none
 *
 */
RAMFUNC_CAN void pac_can_bus_timing_configure(uint8_t brp, uint8_t sjw, uint8_t tseg1, uint8_t tseg2, CAN_BusSample_Type sample);

/**
 * @brief  This function configures IO for use with the CAN peripheral
 *
 * @return none
 */ 
RAMFUNC_CAN void pac_can_io_config(void);

#endif

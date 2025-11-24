#ifndef __BSP_UART_H
#define __BSP_UART_H

#include "stdint.h"

void uart_initiate(void);

uint8_t uart_read(uint32_t time_out);

uint8_t uart_write(uint8_t data, uint32_t time_out);









#endif

// end of file


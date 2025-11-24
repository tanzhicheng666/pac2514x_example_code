#include "bsp_uart.h"
#include "pac_driver_uart.h"

/**
***********************************************************
* @brief uart_initiate
* @param
* @return 
***********************************************************
*/
void uart_initiate(void)
{
    PAC_SCC->CCSCTL.USCMODE = USART_MODE_UART; 
    
    pac_uart_config_LCR2(PAC_UARTC,
                          UARTLCR_WL_BPC_8,
                          UART_STOP_BITS_1,
                          UART_PEN_DISABLE,
                          UART_PARITY_FORCE_STICK_1,
                          UART_BRKCTL_DISABLE);
    pac_uart_config_divisor_latch2(PAC_UARTC, 81);
    
    pac_uart_io_config2();
}

/**
***********************************************************
* @brief uart_reset
* @param
* @return 
***********************************************************
*/
void uart_reset(void)
{

}

/**
***********************************************************
* @brief uart_read
* @param
* @return 
***********************************************************
*/
uint8_t uart_read(uint32_t time_out)
{
    char val;
    
    while(!PAC_UARTC->LSR.RDR)
    {
        
    }
    
    val = (uint8_t)PAC_UARTC->RBR.RBR;
    return val;
}

/**
***********************************************************
* @brief uart_write
* @param
* @return 
***********************************************************
*/
uint8_t uart_write(uint8_t data, uint32_t time_out)
{
    while(!PAC_UARTC->LSR.TEMT)
    {
    
    }
    PAC_UARTC->THR.THR = data;
    return 0;
}



























// end of file 


#ifndef __USART_H__
#define __USART_H__

#include <stdint.h>

//GPS interface
#define UART1_BAUD  9600
//#define UART1_BAUD  38400
//#define UART1_BAUD  115200
#define UART1_US1_TX_LOCATION    11 //PC6 - EXP header #4
#define UART1_US1_RX_LOCATION    11 //PC7 - EXP header #6

void UART1_init();

#endif

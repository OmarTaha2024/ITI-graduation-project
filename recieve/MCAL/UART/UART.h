
#ifndef __UART_H__
#define __UART_H__

/*************** INCLUDES **************************/
#include "../STD.h"
#include "../MCAL_MACROUS.h"
#include "../MCAL_REGS.h"

/************************UART Functions Defination************************/

/*
 * Prototype   : void UART_void_Init(u32 baud);
 * Description : initialize UART with pre configured parameter
 * Arguments   : u32
 * return      : void
 */
 void UART_void_Init_Slave(u16 UBRR_Value);

/*
 * Prototype   : void UART_void_SendData(u8 data);
 * Description : send 1 byte over UART
 * Arguments   : u8
 * return      : void
 */
// void UART_void_SendData(u8 data);

/*
 * Prototype   :  u8 UART_u8_ReceiveData(void);
 * Description : receive 1 byte over UART
 * Arguments   : void
 * return      : u8 received byte
 */
 u8 UART_u8_ReceiveData(void);


#endif /* __UART_H__ */

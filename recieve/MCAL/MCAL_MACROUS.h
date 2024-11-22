#ifndef  _MCAL_MACROUS_h_
#define _MCAL_MACROUS_h_
/*
************** INCLUDES *************************
*/
#include "STD.h"
/*
************* MACROUS DEFINATION ******************
*/
#define BIT_MASK (u8) 1
/* 
***********************MACRO Function Defination***********************
 */
#define HWREG(_x)  *((volatile u8*)_x)
/* Set a certain bit in any register */
#define SET_BIT(REG,BIT) (REG |= (1<<BIT))
/* Clear a certain bit in any register */
#define CLEAR_BIT(REG,BIT)  (REG&=(~(1<<BIT)))
/* toggle a certain bit in any register */
#define toggle_BIT(REG,BIT)  (REG^=(1<<BIT))
/* read a certain bit in any register */
#define read_BIT(REG,BIT) ((REG>>BIT) & BIT_MASK)
/* Set a value  in any port */
#define SET_PORT(REG,val) (REG=val)
/* SET PORT DIRECTION  */
#define SET_PORT_DIR(REG,DIRECTION) (REG =DIRECTION)


#endif // ! _MCAL_MACROUS_h_
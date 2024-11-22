/*
 * ADC_DRIVER.h
 *
 * Created: 9/11/2023 11:56:00 PM
 *  Author: Ahmed Omar
 */ 
#ifndef HAL_HLM35_HLM35_H_
#define HAL_HLM35_HLM35_H_
#include  <stdint.h>
#include "../../MCAL/STD.h"
#include "../../MCAL/MCAL_REGS.h"
#include "../../MCAL/MCAL_MACROUS.h"
#include "../../MCAL/ADC/ADC_DRIVER.h"
#include <avr/io.h>

#define LM35_PORT      GPIO_PORTAID
#define LM35_CHANNEL   GPIO_PIN7 //lm35 pin

void HLM35_voidInit(void);
uint16_t   HLM35_u8ReadTemp(void);

#endif /* HAL_HLM35_HLM35_H_ */
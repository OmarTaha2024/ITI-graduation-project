#ifndef _APP_H_
#define _APP_H_
#include "../HAL/LCD/lcd.h"
#include "../MCAL/UART/UART.h"
#include "../MCAL/GPIO/MCAL_GPIO.h"
#include "../HAL/LCD/lcd.h"
#include "../HAL/LM35/LM35.h"
#include <stdint.h>
#include <avr/io.h>
#include <util/delay.h>

#define F_CPU 1000000UL
#define UBRR_Val 12

void INIT_Prog(void);
u8 app_void_recieve();

void app_void_display(u8 data);
#endif // ! _APP_H_
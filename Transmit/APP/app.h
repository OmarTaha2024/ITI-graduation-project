#ifndef  _APP_H_ 
#define _APP_H_
#define UBRR_Val 12
#include "../HAL/KEYPAD/keypad.h"
#include "../HAL/LCD/lcd.h"
#include "../MCAL/UART/UART.h"
#include <stdint.h>
#include <util/delay.h>
#include <string.h>
typedef struct{
    char position[128];
    char name[128];
    uint8_t password[4];

}user_t;

typedef enum{
    owner=1,
    employee,
    wrongpass,
}userType_t;

void app_init(void);
uint8_t Cheack_Password(uint8_t n);


void run_program(void);

/*
 * Prototype   : void transmit_who_entered(void)
 * Description : check who entered and send it to receiving MC via communication protocol
 * Arguments   : void
 * return      : void
 */
void transmit_who_entered(void);

#endif // ! _APP_H_ 

#ifndef _KEYPAD_H_
#define _KEYPAD_H_
#include <stdint.h>
#include "../../MCAL/GPIO/MCAL_GPIO.h"
/*
----------DEFINATION---------
*/
#define keypad_ROWS 4
#define keypad_COL 4
/*
------------MACROUS------------------
*/
typedef struct {
pin_config_t keypad_rows_pin[keypad_ROWS];
pin_config_t keypad_col_pin[keypad_COL];
}keypad_t;
/*
******************* keypad 1 ******************
*/

/*
*configration api's
*/
void keypad_inti(const keypad_t * keypad_obj);
/*
*control api's
*/
uint8_t keypad_scan( const keypad_t * keypad_obj);
//static uint8_t KeyPad_4x4_adjustKeyNumber(uint8_t button_number);
#endif // !_KEYPAD_H_

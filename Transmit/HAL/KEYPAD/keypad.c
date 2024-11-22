#include "keypad.h"
#include <stdio.h>
#include <util/delay.h>
static const uint8_t values[keypad_ROWS][keypad_COL]={
                                                        {7,8,9,'/'},
                                                        {4,5,6,'*'},
                                                        {1,2,3,'+'},
                                                        {'#','0','=','-'}
                                                                                    };


  keypad_t keypad_1 = {
    .keypad_rows_pin[0].port=GPIO_PORTCID,
    .keypad_rows_pin[0].pin=GPIO_PIN0,
    .keypad_rows_pin[0].logic=GPIO_LOW,
    .keypad_rows_pin[0].direction= GPIO_OUTPUT_DIRECTION,

    .keypad_rows_pin[1].port=GPIO_PORTCID,
    .keypad_rows_pin[1].pin=GPIO_PIN1,
    .keypad_rows_pin[1].logic=GPIO_LOW,
    .keypad_rows_pin[1].direction= GPIO_OUTPUT_DIRECTION,

    .keypad_rows_pin[2].port=GPIO_PORTCID,
    .keypad_rows_pin[2].pin=GPIO_PIN2,
    .keypad_rows_pin[2].logic=GPIO_LOW,
    .keypad_rows_pin[2].direction= GPIO_OUTPUT_DIRECTION,

    .keypad_rows_pin[3].port=GPIO_PORTCID,
    .keypad_rows_pin[3].pin=GPIO_PIN3,
    .keypad_rows_pin[3].logic=GPIO_LOW,
    .keypad_rows_pin[3].direction= GPIO_OUTPUT_DIRECTION,
    

    .keypad_col_pin[0].port=GPIO_PORTCID,
    .keypad_col_pin[0].pin=GPIO_PIN4,
    .keypad_col_pin[0].logic=GPIO_LOW,
    .keypad_col_pin[0].direction=GPIO_INPUT_DIRECTION,

    .keypad_col_pin[1].port=GPIO_PORTCID,
    .keypad_col_pin[1].pin=GPIO_PIN5,
    .keypad_col_pin[1].logic=GPIO_LOW,
    .keypad_col_pin[1].direction=GPIO_INPUT_DIRECTION,

    .keypad_col_pin[2].port=GPIO_PORTCID,
    .keypad_col_pin[2].pin=GPIO_PIN6,
    .keypad_col_pin[2].logic=GPIO_LOW,
    .keypad_col_pin[2].direction=GPIO_INPUT_DIRECTION,

    
    .keypad_col_pin[3].port=GPIO_PORTCID,
    .keypad_col_pin[3].pin=GPIO_PIN7,
    .keypad_col_pin[3].logic=GPIO_LOW,
    .keypad_col_pin[3].direction=GPIO_INPUT_DIRECTION,
    
  };

void keypad_inti(const keypad_t * keypad_obj){
    uint8_t rows_counter ;
    uint8_t col_counter  ;
   if(keypad_obj==NULL){
    return ;
   }
   else {
        for(rows_counter=0;rows_counter<keypad_ROWS;rows_counter++){
          gpio_pin_intialization(&(keypad_obj->keypad_rows_pin[rows_counter]));
        }
        for(col_counter=0;col_counter<keypad_COL;col_counter++){
             gpio_pin_direction_intialization(&(keypad_obj->keypad_col_pin[col_counter]));
        }
   }
}
uint8_t keypad_scan( const keypad_t * keypad_obj){
     uint8_t rows_counter = 0 ;
    uint8_t col_counter = 0 ;
    uint8_t col_val ;
    uint8_t btn ='\0';
   
    if(keypad_obj==NULL){
    return 0 ;
   }
  else {
    for(rows_counter = 0; rows_counter<keypad_ROWS;rows_counter++)
    {
        for(uint8_t r_counter = 0;r_counter<keypad_ROWS;r_counter++){   
            gpio_pin_write_logic(&(keypad_obj->keypad_rows_pin[r_counter]),GPIO_LOW);
        }
            gpio_pin_write_logic(&(keypad_obj->keypad_rows_pin[rows_counter]), GPIO_HIGH);
            _delay_ms(10);
               for(col_counter=0;col_counter<keypad_COL;col_counter++){
                col_val=   gpio_pin_read_logic(&(keypad_obj->keypad_col_pin[col_counter]),&col_val);
                   
                   if(col_val==GPIO_HIGH){
                   btn=values[rows_counter][col_counter];
                   return btn ;
                   }
                }
     }
  }
   return btn ;
}
    
/*
**************test*************************
*/
/*static uint8_t KeyPad_4x4_adjustKeyNumber(uint8_t button_number)
{
	switch(button_number)
	{
		case 1: return 7; 
				break;
		case 2: return 8; 
				break;
		case 3: return 9; 
				break;
		case 4: return '%'; // ASCII Code of %
				break;
		case 5: return 4; 
				break;
		case 6: return 5;
				break;
		case 7: return 6; 
				break;
		case 8: return '*'; 
				break;		
		case 9: return 1; 
				break;
		case 10: return 2; 
				break;
		case 11: return 3; 
				break;
		case 12: return '-';
				break;
		case 13: return 13;  
				break;			
		case 14: return 0; 
				break;
		case 15: return '='; 
				break;
		case 16: return '+'; 
				break;
		default: return button_number;								 						
	}
} */
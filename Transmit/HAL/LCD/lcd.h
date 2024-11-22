#ifndef _LCD_H_
#define _LCD_H_


#include "../../MCAL/GPIO/MCAL_GPIO.h"

#define H_LCD_RS 		2
#define H_LCD_RW		1
#define H_LCD_EN   	    0
#define PORT_CNL        PORTB_Ptr 
#define PORT_DATA       ptr_PORTA
#define PORT_CNL_direction  _PTRDDRB  
#define PORT_DATA_direction  _PTRDDRA 




#define _LCD_CLEAR                      0X01
#define _LCD_RETURN_HOME                0x02
#define _LCD_ENTRY_MODE_DEC_SHIFT_OFF   0x04
#define _LCD_ENTRY_MODE_DEC_SHIFT_ON    0x05
#define _LCD_ENTRY_MODE_INC_SHIFT_OFF   0x06
#define _LCD_ENTRY_MODE_INC_SHIFT_ON    0x07
#define _LCD_CURSOR_MOVE_SHIFT_LEFT     0x10
#define _LCD_CURSOR_MOVE_SHIFT_RIGHT    0x14
#define _LCD_DISPLAY_SHIFT_LEFT         0x18
#define _LCD_DISPLAY_SHIFT_RIGHT        0x1C
#define _LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_OFF 0x0C
#define _LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_ON  0x0D
#define _LCD_DISPLAY_ON_UNDERLINE_ON_CURSOR_OFF  0x0E
#define _LCD_DISPLAY_ON_UNDERLINE_ON_CURSOR_ON   0x0F
#define _LCD_DISPLAY_OFF_CURSOR_OFF              0x08
#define _LCD_8BIT_MODE_2_LINE           0x38
#define _LCD_4BIT_MODE_2_LINE           0x28

#define _LCD_CGRAM_START                0x40
#define _LCD_DDRAM_START                0x80

#define ROW1 0
#define ROW2 1
/*********************/
void HLCD_send_command(uint8_t cope_h_command );
void HLCD_INIT(void);
void HLCD_send_DATA(uint8_t cope_h_data);
void HLCD_voidCLRScreen(void);
void HLCD_voidGoToXy (uint8_t  Copy_u8XPosition, uint8_t  Copy_u8YPosition); 
void HLCD_voidSendString (const uint8_t * copy_ps8str); //send string
void HLCD_voidSendNumber(uint32_t Copy_s32Number);
void LCD_send_string_pos(uint8_t * copy_ps8str,uint8_t  Copy_u8XPosition, uint8_t  Copy_u8YPosition);
void LCD_Send_Number(uint8_t num);
void LCD_Send_Number_Pos(uint8_t num,uint8_t row,uint8_t column);
#endif /* HAL_LCD_HLCD_CNF_H_ */
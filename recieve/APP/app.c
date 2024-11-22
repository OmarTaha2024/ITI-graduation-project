#include "app.h"

#define WARNING 'W'
#define OWNER 'O'
#define GUEST 'E'

u8 data;
u16 temp;

void INIT_Prog(void)
{
	UART_void_Init_Slave(UBRR_Val);
	HLCD_INIT();
	HLM35_voidInit();
	HLCD_voidCLRScreen();
	DDRC = 0xFF;
}

u8 app_void_recieve()
{
	u8 data = UART_u8_ReceiveData(); // UART_u8_ReceiveData();
	return data;
}

void app_void_display(u8 data)
{
	temp = HLM35_u8ReadTemp();
	if (data == WARNING)
	{
		PORTC = 4;
	}
	else if (data == OWNER)
	{
		PORTC = 0b000000001;
		while (1)
		{
			temp = HLM35_u8ReadTemp();
			if (temp < 16)
			{
				PORTC &= 0b00000111;
				SET_BIT(PORTC, PIN3);
			}
			else if ((temp >= 16)&&(temp<=35))
			{
				PORTC &= 0b00000111;
				SET_BIT(PORTC, PIN4);
			}
			else if ((temp > 35) && (temp<=55))
			{
				PORTC &= 0b00000111;
				SET_BIT(PORTC, PIN5);
			}
			else if (temp > 55)
			{
				PORTC &= 0b00000111;
				SET_BIT(PORTC, PIN6);
			}
		}
	}
	else if (data == GUEST)
	{
		PORTC = 2;
	}
}

#include "LM35.h"

void HLM35_voidInit(void)
{
    ADC_void_init(V_AVCC, PRESCALER_8);
    SET_BIT(DDRA, PIN7);
}

uint16_t HLM35_u8ReadTemp(void)
{
    ADC_void_startConversion(channel_7);
    uint16_t Local_u16ADCRead; //(digital)
    uint16_t Local_u16Readmv;  //(analog)

    Local_u16ADCRead = ADC_u16_read();

    Local_u16Readmv = ((Local_u16ADCRead * 0.0048828125) * 100);
    return Local_u16Readmv;
}

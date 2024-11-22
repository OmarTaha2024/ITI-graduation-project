#ifndef  _MCAL_REGS_h_
#define _MCAL_REGS_h_

/*
*************** ALL PORTS ADRESSES ***************
*/
#define     PORTA_BASE      0x3B
#define     DDRA_BASE       0x3A
#define     PINA_BASE       0x39
// GROUP B


#define     PORTB_BASE      0x38
#define     DDRB_BASE       0x37
#define     PINB_BASE       0x36
//GROUP C
#define     PORTC_BASE      0x35
#define     DDRC_BASE       0x34
#define     PINC_BASE       0x33

// GROUP  D
#define     PORTD_BASE      0x32
#define     DDRD_BASE       0x31
#define     PIND_BASE       0x30


//POINTERS  FOR GROUPS
/*
*************** PORT_NAMES **************
*/
#define ptr_PORTA * ((volatile u8*)PORTA_BASE)
#define PORTB_Ptr  *((volatile u8*)PORTB_BASE)
#define PORTC_Ptr  *((volatile u8*)PORTC_BASE)
#define PORTD_Ptr * ((volatile u8*)PORTD_BASE)
/*
*************** PORT_DIRECTION ***************
*/
#define _PTRDDRA        *((volatile u8*)DDRA_BASE)
#define _PTRDDRB       *((volatile u8*)DDRB_BASE)
#define _PTRDDRC        *((volatile u8*)DDRC_BASE)
#define _PTRDDRD        *((volatile u8*)DDRD_BASE)
/*
************** PORT_PINS ***************
*/
#define PINA_PTR        *((volatile u8*)PINA_BASE)
#define PINB_PTR        *((volatile u8*)PINB_BASE)
#define PINC_PTR        *((volatile u8*)PINC_BASE)
#define PIND_PTR        *((volatile u8*)PIND_BASE)
/*
************** ADC_REG ***************
*/
#define  ADMUX_REG       (*((volatile u8*)0x27))
#define ADCSRA_REG       (*((volatile u8*)0x26))
#define  SFIOR_REG       (*((volatile u8*)0x50))
#define   ADCH_REG       (*((volatile u16*)0x25))
#define   ADCL_REG       (*((volatile u16*)0x24))
/********** ADMUX *************/
#define REFS1_BIT   7
#define REFS0_BIT   6
#define ADLAR_BIT   5
/********** ADCSRA *************/
#define  ADEN_BIT   7
#define  ADSC_BIT   6
#define ADATE_BIT   5
#define  ADIF_BIT   4
#define  ADIE_BIT   3
#define ADPS2_BIT   2
#define ADPS1_BIT   1
#define ADPS0_BIT   0
/*********** SFIOR **************/
#define ADTS2_BIT  7
#define ADTS1_BIT  6
#define ADTS0_BIT  5
/*********** Voltage ************/
#define AREF	   0
#define AVCC       1
#define RESERVED   2
#define INTERNAL   3

/*********** MUX_BITS***********/
#define MUX0_BIT 0
#define MUX1_BIT 1
#define MUX2_BIT 2
#define MUX3_BIT 3
#define MUX4_BIT 4

/*
************** UART_REG ***************
*/
#define UCSRA            (*((volatile u8*)0x2B))
#define UCSRB            (*((volatile u8*)0x2A))
#define UCSRC            (*((volatile u8*)0x40))
#define   UDR            (*((volatile u8*)0x2C))
#define  UBRR
#define UBRRL            (*((volatile u8*)0x29))
#define UBRRH            (*((volatile u8*)0x40))

/*UCSRA*/
#define MPCM             0
#define  U2X             1
#define   PE             2
#define  DOR             3
#define   FE             4
#define UDRE             5
#define  TXC             6
#define  RXC             7

/*UCSRB*/
#define  TXB8            0
#define  RXB8            1
#define UCSZ2            2
#define  TXEN           3
#define  RXEN            4
#define UDRIE            5
#define TXCIE            6
#define RXCIE            7

/*UCSRC*/
#define UCPOL            0
#define UCSZ0            1
#define UCSZ1            2
#define  USBS            3
#define  UPM0            4
#define  UPM1            5
#define UMSEL            6
#define URSEL            7

#endif

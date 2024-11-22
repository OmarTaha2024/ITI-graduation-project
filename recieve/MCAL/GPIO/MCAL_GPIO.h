#ifndef  _MCAL_GPIO_h_
#define _MCAL_GPIO_h_
#include "../MCAL_MACROUS.h"
#include "../MCAL_REGS.h"
/*
************* DATA TYPE DEFINATION ******************
*/

typedef enum{
    GPIO_INPUT_DIRECTION ,
    GPIO_OUTPUT_DIRECTION
}dierction_t;
typedef enum{
    GPIO_LOW ,
    GPIO_HIGH
}logic_t;
typedef enum {
    GPIO_PIN0,
    GPIO_PIN1,
    GPIO_PIN2,
    GPIO_PIN3,
    GPIO_PIN4,
    GPIO_PIN5,
    GPIO_PIN6,
    GPIO_PIN7
}pin_index_t;
typedef enum {
    GPIO_PORTAID ,
    GPIO_PORTBID,
    GPIO_PORTCID,
    GPIO_PORTDID
}port_index_t;
typedef struct {
    u8 port : 3 ;/* @ref port_index_t */
    u8 pin : 3 ; /* @ref pin_index_t */
    u8 direction : 1 ;/* @ref dierction_t */
    u8 logic: 1 ;/* @ref logic_t */
}pin_config_t;
#define port_mask 0xFF

/*
***********************API'S DEFINATION *******************************
*/
void gpio_pin_write_logic(const pin_config_t * _pin_config ,u8 logic);
logic_t gpio_pin_read_logic(const pin_config_t * _pin_config ,u8 * logic);
void gpio_pin_direction_status(const pin_config_t * _pin_config ,dierction_t * copy_u8direction);
void gpio_pin_intialization(const pin_config_t * _pin_config );
void gpio_pin_direction_intialization(const pin_config_t * _pin_config );
void gpio_pin_toggle(const pin_config_t * _pin_config );


/*
*************PORT CONFIGRATION *****************
*/

void gpio_PORT_read_value(port_index_t copy_portin ,u8 * copy_logic );
void gpio_PORT_write_value(port_index_t copy_portin ,u8 copy_logic );
void gpio_PORT_direction_intialization(port_index_t copy_portin ,u8 copy_direction );
void gpio_PORT_toggle(port_index_t copy_portin );
#endif // ! _MCAL_GPIO_h_
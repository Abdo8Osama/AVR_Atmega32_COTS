/*******************************************************/
/* AUTHOR 	: ABDULRAHMAN OSAMA MOHAMED                */
/* DEC		: LED DRIVER                               */
/* DATE		: 28/1/2020                                */
/*******************************************************/

#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"led_int.h"
#include"DIO_interface.h"
#include"DIO_register.h"


/****************PIN FUNCTIONS ****************************************/
/**********************************************************************/

/*TURN LED ON */
void  LED_TURN_ON (u8 port , u8 pin )
{
/* set pin direction to be output */
	DIO_voidSetpinDirection(port , pin , OUT);
/* set pin value to be High */
    DIO_voidSetpinValue(port , pin , HIGH);

}
/**********************************************************************/
/**********************************************************************/

/*TURN LED OFF */
void  LED_TURN_OFF(u8 port , u8 pin )
{
/* set pin direction to be output */
	DIO_voidSetpinDirection(port , pin , OUT);
/* set pin value to be High */
    DIO_voidSetpinValue(port , pin , LOW);

}

/***********************************************************************/
/***********************************************************************/

/*TOGGLE LED STATE */
void  LED_TOGGLE(u8 port , u8 pin )
{
/* set pin direction to be output */
	DIO_voidSetpinDirection(port , pin , OUT);
/* set pin value to be High */
	switch(port)
	{
		case PORTA : TOG(PORTA_REG , pin);break;
		case PORTB : TOG(PORTB_REG , pin);break;
		case PORTC : TOG(PORTC_REG , pin);break;
		case PORTD : TOG(PORTD_REG , pin);break;
		default    : break;
	}

}



/*******************************************************/
/* AUTHOR 	: ABDULRAHMAN OSAMA MOHAMED                */
/* DEC		: KEYPAD DRIVER                            */
/* DATE		: 2/2/2020                                 */
/*******************************************************/

#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"DIO_interface.h"
#include"DIO_register.h"
#include"KEYPAD_int.h"


/****************PIN FUNCTIONS ****************************************/
/**********************************************************************/
/* GET THE PRESSED KEY FUNCTION */
u8  Keypad_u8_getPressedKey (void )
{
	u8 result = ' ';
	/* SET PINS 0123 OUTPUT*/
	DIO_voidSetpinDirection(KEYS_PORT , PIN0 ,OUT);
	DIO_voidSetpinDirection(KEYS_PORT , PIN1 ,OUT);
	DIO_voidSetpinDirection(KEYS_PORT , PIN2 ,OUT);
	DIO_voidSetpinDirection(KEYS_PORT , PIN3 ,OUT);

	/* SET PINS 4567 INPUT*/
	DIO_voidSetpinDirection(KEYS_PORT , PIN4 , IN);
	DIO_voidSetpinDirection(KEYS_PORT , PIN5 , IN);
	DIO_voidSetpinDirection(KEYS_PORT , PIN6 , IN);
	DIO_voidSetpinDirection(KEYS_PORT , PIN7 , IN);

	/* ENABLE THE PULL UP RESISTORS */
	DIO_voidSetpinValue(KEYS_PORT , PIN4 , HIGH);
	DIO_voidSetpinValue(KEYS_PORT , PIN5 , HIGH);
	DIO_voidSetpinValue(KEYS_PORT , PIN6 , HIGH);
	DIO_voidSetpinValue(KEYS_PORT , PIN7 , HIGH);

	/* SEND PATTERN 1110 TO THE KEYPAD */
	DIO_voidSetportValue(KEYS_PORT , 0xFE);

	/* CHECK THE FIRST COLUMN */
	if(((PINC_REG >> PIN4) & 1) == 0)
	{
		result = '*' ;
		while(((PINC_REG >> PIN4) & 1) == 0);
		//_delay_ms(10);
	}
	else if(((PINC_REG >> PIN5) & 1) == 0)
	{
		result = '/' ;
		while(((PINC_REG >> PIN5) & 1) == 0);
	}
	else if(((PINC_REG >> PIN6) & 1) == 0)
	{
		result = '+' ;
		while(((PINC_REG >> PIN6) & 1) == 0);
	}
	else if(((PINC_REG >> PIN7) & 1) == 0)
	{
		result = '-' ;
		while(((PINC_REG >> PIN7) & 1) == 0);
	}

	/* SEND PATTERN 1101 TO THE KEYPAD */
	DIO_voidSetportValue(KEYS_PORT , 0xFD);

	/* CHECK THE SECOND COLUMN */
	if(((PINC_REG >> PIN4) & 1) == 0)
	{
		result = 3 ;
		while(((PINC_REG >> PIN4) & 1) == 0);
	}
	else if(((PINC_REG >> PIN5) & 1) == 0)
	{
		result = 6 ;
		while(((PINC_REG >> PIN5) & 1) == 0);
	}
	else if(((PINC_REG >> PIN6) & 1) == 0)
	{
		result = 9 ;
		while(((PINC_REG >> PIN6) & 1) == 0);
	}
	else if(((PINC_REG >> PIN7) & 1) == 0)
	{
		result = '=' ;
		while(((PINC_REG >> PIN7) & 1) == 0);
	}

	/* SEND PATTERN 1011 TO THE KEYPAD */
	DIO_voidSetportValue(KEYS_PORT , 0xFB);

	/* CHECK THE THIRD COLUMN */
	if(((PINC_REG >> PIN4) & 1) == 0)
	{
		result = 2 ;
		while(((PINC_REG >> PIN4) & 1) == 0);
	}
	else if(((PINC_REG >> PIN5) & 1) == 0)
	{
		result = 5 ;
		while(((PINC_REG >> PIN5) & 1) == 0);
	}
	else if(((PINC_REG >> PIN6) & 1) == 0)
	{
		result = 8 ;
		while(((PINC_REG >> PIN6) & 1) == 0);
	}
	else if(((PINC_REG >> PIN7) & 1) == 0)
	{
		result = 0 ;
		while(((PINC_REG >> PIN7) & 1) == 0);
	}

	/* SEND PATTERN 0111 TO THE KEYPAD */
	DIO_voidSetportValue(KEYS_PORT , 0xF7);

	/* CHECK THE FOURTH COLUMN */
	if(((PINC_REG >> PIN4) & 1) == 0)
	{
		result = 1 ;
		while(((PINC_REG >> PIN4) & 1) == 0);
	}
	else if(((PINC_REG >> PIN5) & 1) == 0)
	{
		result = 4 ;
		while(((PINC_REG >> PIN5) & 1) == 0);
	}
	else if(((PINC_REG >> PIN6) & 1) == 0)
	{
		result = 7 ;
		while(((PINC_REG >> PIN6) & 1) == 0);
	}
	else if(((PINC_REG >> PIN7) & 1) == 0)
	{
		result = '.' ;
		while(((PINC_REG >> PIN7) & 1) == 0);
	}



	return result ;
}

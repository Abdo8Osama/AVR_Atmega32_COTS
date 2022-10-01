
/*******************************************************/
/* AUTHOR 	: ABDULRAHMAN OSAMA MOHAMED                */
/* DEC		: STEPPER DRIVER                           */
/* DATE		: 4/2/2020                                 */
/*******************************************************/

#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"DIO_interface.h"
#include"STEPPER_int.h"
#include<util/delay.h>

/****************PIN FUNCTIONS ****************************************/
/**********************************************************************/
void STEPPER_Full_STEP(u8 direction , u16 angel , u16 Tdelay)
{
	if(direction == CW)
	{

		u16 i = 0 , steps = 0;
		steps = (angel * 512) / 360;

		DIO_voidSetpinDirection(STEPPER_PORT , BLUE ,OUT);
		DIO_voidSetpinDirection(STEPPER_PORT , PINK ,OUT);
		DIO_voidSetpinDirection(STEPPER_PORT , YELLOW ,OUT);
		DIO_voidSetpinDirection(STEPPER_PORT , ORANGE ,OUT);

		for(i = 0;i<steps;i++)
		{
			DIO_voidSetpinValue(STEPPER_PORT , PIN1 , HIGH);
			DIO_voidSetpinValue(STEPPER_PORT , PIN2 , LOW);
			DIO_voidSetpinValue(STEPPER_PORT , PIN3 , LOW);
			DIO_voidSetpinValue(STEPPER_PORT , PIN4 , LOW);
			_delay_ms(Tdelay);


			DIO_voidSetpinValue(STEPPER_PORT , PIN1 , LOW);
			DIO_voidSetpinValue(STEPPER_PORT , PIN2 , HIGH);
			DIO_voidSetpinValue(STEPPER_PORT , PIN3 , LOW);
			DIO_voidSetpinValue(STEPPER_PORT , PIN4 , LOW);
			_delay_ms(Tdelay);



			DIO_voidSetpinValue(STEPPER_PORT , PIN1 , LOW);
			DIO_voidSetpinValue(STEPPER_PORT , PIN2 , LOW);
			DIO_voidSetpinValue(STEPPER_PORT , PIN3 , HIGH);
			DIO_voidSetpinValue(STEPPER_PORT , PIN4 , LOW);
			_delay_ms(Tdelay);



			DIO_voidSetpinValue(STEPPER_PORT , PIN1 , LOW);
			DIO_voidSetpinValue(STEPPER_PORT , PIN2 , LOW);
			DIO_voidSetpinValue(STEPPER_PORT , PIN3 , LOW);
			DIO_voidSetpinValue(STEPPER_PORT , PIN4 , HIGH);
			_delay_ms(Tdelay);

		}
	}


	else if(direction == CCW)
	{

		u16 i = 0 , steps = 0;
		steps = (angel * 512)/ 360;

		DIO_voidSetpinDirection(STEPPER_PORT , BLUE ,OUT);
		DIO_voidSetpinDirection(STEPPER_PORT , PINK ,OUT);
		DIO_voidSetpinDirection(STEPPER_PORT , YELLOW ,OUT);
		DIO_voidSetpinDirection(STEPPER_PORT , ORANGE ,OUT);

		for(i = 0;i<steps;i++)
		{
			DIO_voidSetpinValue(STEPPER_PORT , PIN1 , LOW);
			DIO_voidSetpinValue(STEPPER_PORT , PIN2 , LOW);
			DIO_voidSetpinValue(STEPPER_PORT , PIN3 , LOW);
			DIO_voidSetpinValue(STEPPER_PORT , PIN4 , HIGH);
			_delay_ms(Tdelay);


			DIO_voidSetpinValue(STEPPER_PORT , PIN1 , LOW);
			DIO_voidSetpinValue(STEPPER_PORT , PIN2 , LOW);
			DIO_voidSetpinValue(STEPPER_PORT , PIN3 , HIGH);
			DIO_voidSetpinValue(STEPPER_PORT , PIN4 , LOW);
			_delay_ms(Tdelay);



			DIO_voidSetpinValue(STEPPER_PORT , PIN1 , LOW);
			DIO_voidSetpinValue(STEPPER_PORT , PIN2 , HIGH);
			DIO_voidSetpinValue(STEPPER_PORT , PIN3 , LOW);
			DIO_voidSetpinValue(STEPPER_PORT , PIN4 , LOW);
			_delay_ms(Tdelay);



			DIO_voidSetpinValue(STEPPER_PORT , PIN1 , HIGH);
			DIO_voidSetpinValue(STEPPER_PORT , PIN2 , LOW);
			DIO_voidSetpinValue(STEPPER_PORT , PIN3 , LOW);
			DIO_voidSetpinValue(STEPPER_PORT , PIN4 , LOW);
			_delay_ms(Tdelay);

		}
	}
}



/**********************************************************************/
/**********************************************************************/

void STEPPER_HALF_STEP(u8 direction , u16 angel , u16 Tdelay)
{
	if(direction == CW)
	{

		u16 i = 0 , steps = 0;
		steps = (angel * 512) / 360;

		DIO_voidSetpinDirection(STEPPER_PORT , BLUE ,OUT);
		DIO_voidSetpinDirection(STEPPER_PORT , PINK ,OUT);
		DIO_voidSetpinDirection(STEPPER_PORT , YELLOW ,OUT);
		DIO_voidSetpinDirection(STEPPER_PORT , ORANGE ,OUT);

		for(i = 0;i<steps;i++)
		{
			DIO_voidSetpinValue(STEPPER_PORT , PIN1 , HIGH);
			DIO_voidSetpinValue(STEPPER_PORT , PIN2 , LOW);
			DIO_voidSetpinValue(STEPPER_PORT , PIN3 , LOW);
			DIO_voidSetpinValue(STEPPER_PORT , PIN4 , LOW);
			_delay_ms(Tdelay);


			DIO_voidSetpinValue(STEPPER_PORT , PIN1 , HIGH);
			DIO_voidSetpinValue(STEPPER_PORT , PIN2 , HIGH);
			DIO_voidSetpinValue(STEPPER_PORT , PIN3 , LOW);
			DIO_voidSetpinValue(STEPPER_PORT , PIN4 , LOW);
			_delay_ms(Tdelay);

			DIO_voidSetpinValue(STEPPER_PORT , PIN1 , LOW);
			DIO_voidSetpinValue(STEPPER_PORT , PIN2 , HIGH);
			DIO_voidSetpinValue(STEPPER_PORT , PIN3 , LOW);
			DIO_voidSetpinValue(STEPPER_PORT , PIN4 , LOW);
			_delay_ms(Tdelay);


			DIO_voidSetpinValue(STEPPER_PORT , PIN1 , LOW);
			DIO_voidSetpinValue(STEPPER_PORT , PIN2 , HIGH);
			DIO_voidSetpinValue(STEPPER_PORT , PIN3 , HIGH);
			DIO_voidSetpinValue(STEPPER_PORT , PIN4 , LOW);
			_delay_ms(Tdelay);


			DIO_voidSetpinValue(STEPPER_PORT , PIN1 , LOW);
			DIO_voidSetpinValue(STEPPER_PORT , PIN2 , LOW);
			DIO_voidSetpinValue(STEPPER_PORT , PIN3 , HIGH);
			DIO_voidSetpinValue(STEPPER_PORT , PIN4 , LOW);
			_delay_ms(Tdelay);

			DIO_voidSetpinValue(STEPPER_PORT , PIN1 , LOW);
			DIO_voidSetpinValue(STEPPER_PORT , PIN2 , LOW);
			DIO_voidSetpinValue(STEPPER_PORT , PIN3 , HIGH);
			DIO_voidSetpinValue(STEPPER_PORT , PIN4 , HIGH);
			_delay_ms(Tdelay);

			DIO_voidSetpinValue(STEPPER_PORT , PIN1 , LOW);
			DIO_voidSetpinValue(STEPPER_PORT , PIN2 , LOW);
			DIO_voidSetpinValue(STEPPER_PORT , PIN3 , LOW);
			DIO_voidSetpinValue(STEPPER_PORT , PIN4 , HIGH);
			_delay_ms(Tdelay);

			DIO_voidSetpinValue(STEPPER_PORT , PIN1 , HIGH);
			DIO_voidSetpinValue(STEPPER_PORT , PIN2 , LOW);
			DIO_voidSetpinValue(STEPPER_PORT , PIN3 , LOW);
			DIO_voidSetpinValue(STEPPER_PORT , PIN4 , HIGH);
			_delay_ms(Tdelay);

		}
	}


	else if(direction == CCW)
	{

		u16 i = 0 , steps = 0;
		steps = (angel * 512)/ 360;

		DIO_voidSetpinDirection(STEPPER_PORT , BLUE ,OUT);
		DIO_voidSetpinDirection(STEPPER_PORT , PINK ,OUT);
		DIO_voidSetpinDirection(STEPPER_PORT , YELLOW ,OUT);
		DIO_voidSetpinDirection(STEPPER_PORT , ORANGE ,OUT);

		for(i = 0;i<steps;i++)
		{
			DIO_voidSetpinValue(STEPPER_PORT , PIN1 , LOW);
			DIO_voidSetpinValue(STEPPER_PORT , PIN2 , LOW);
			DIO_voidSetpinValue(STEPPER_PORT , PIN3 , LOW);
			DIO_voidSetpinValue(STEPPER_PORT , PIN4 , HIGH);
			_delay_ms(Tdelay);


			DIO_voidSetpinValue(STEPPER_PORT , PIN1 , LOW);
			DIO_voidSetpinValue(STEPPER_PORT , PIN2 , LOW);
			DIO_voidSetpinValue(STEPPER_PORT , PIN3 , HIGH);
			DIO_voidSetpinValue(STEPPER_PORT , PIN4 , HIGH);
			_delay_ms(Tdelay);



			DIO_voidSetpinValue(STEPPER_PORT , PIN1 , LOW);
			DIO_voidSetpinValue(STEPPER_PORT , PIN2 , LOW);
			DIO_voidSetpinValue(STEPPER_PORT , PIN3 , HIGH);
			DIO_voidSetpinValue(STEPPER_PORT , PIN4 , LOW);
			_delay_ms(Tdelay);



			DIO_voidSetpinValue(STEPPER_PORT , PIN1 , LOW);
			DIO_voidSetpinValue(STEPPER_PORT , PIN2 , HIGH);
			DIO_voidSetpinValue(STEPPER_PORT , PIN3 , HIGH);
			DIO_voidSetpinValue(STEPPER_PORT , PIN4 , LOW);
			_delay_ms(Tdelay);


			DIO_voidSetpinValue(STEPPER_PORT , PIN1 , LOW);
			DIO_voidSetpinValue(STEPPER_PORT , PIN2 , HIGH);
			DIO_voidSetpinValue(STEPPER_PORT , PIN3 , LOW);
			DIO_voidSetpinValue(STEPPER_PORT , PIN4 , LOW);
			_delay_ms(Tdelay);


			DIO_voidSetpinValue(STEPPER_PORT , PIN1 , HIGH);
			DIO_voidSetpinValue(STEPPER_PORT , PIN2 , HIGH);
			DIO_voidSetpinValue(STEPPER_PORT , PIN3 , LOW);
			DIO_voidSetpinValue(STEPPER_PORT , PIN4 , LOW);
			_delay_ms(Tdelay);



			DIO_voidSetpinValue(STEPPER_PORT , PIN1 , HIGH);
			DIO_voidSetpinValue(STEPPER_PORT , PIN2 , LOW);
			DIO_voidSetpinValue(STEPPER_PORT , PIN3 , LOW);
			DIO_voidSetpinValue(STEPPER_PORT , PIN4 , LOW);
			_delay_ms(Tdelay);



			DIO_voidSetpinValue(STEPPER_PORT , PIN1 , HIGH);
			DIO_voidSetpinValue(STEPPER_PORT , PIN2 , LOW);
			DIO_voidSetpinValue(STEPPER_PORT , PIN3 , LOW);
			DIO_voidSetpinValue(STEPPER_PORT , PIN4 , HIGH);
			_delay_ms(Tdelay);


		}
	}
}


/**********************************************************************/
/**********************************************************************/

void STEPPER_STOP()
{
	DIO_voidSetpinValue(STEPPER_PORT , PIN1 , LOW);
	DIO_voidSetpinValue(STEPPER_PORT , PIN2 , LOW);
	DIO_voidSetpinValue(STEPPER_PORT , PIN3 , LOW);
	DIO_voidSetpinValue(STEPPER_PORT , PIN4 , LOW);
}










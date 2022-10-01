
/*******************************************************/
/* AUTHOR 	: ABDULRAHMAN OSAMA MOHAMED                */
/* DEC		: DC MOTOR DRIVER                           */
/* DATE		: 4/2/2020                                 */
/*******************************************************/

#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"DIO_interface.h"
#include"DC_MOTOR_int.h"

/****************PIN FUNCTIONS ****************************************/
/**********************************************************************/

void DCMOTOR_TurnRight()
{
	/* MOTOR DIRECTION RIGHT*/
	DIO_voidSetpinValue(DC_PORT , PIN_RIGHT ,HIGH);
	DIO_voidSetpinValue(DC_PORT , PIN_LEFT ,LOW);
}

/**********************************************************************/
/**********************************************************************/

void DCMOTOR_Turnleft()
{
	/* MOTOR DIRECTION RIGHT*/
	DIO_voidSetpinValue(DC_PORT , PIN_LEFT ,HIGH);
	DIO_voidSetpinValue(DC_PORT , PIN_RIGHT ,LOW);
}

/**********************************************************************/
/**********************************************************************/

void DCMOTOR_Stop()
{
	/* MOTOR DIRECTION RIGHT*/
	DIO_voidSetpinValue(DC_PORT , PIN_LEFT ,LOW);
	DIO_voidSetpinValue(DC_PORT , PIN_RIGHT ,LOW);
}

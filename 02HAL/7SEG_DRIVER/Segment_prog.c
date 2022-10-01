/*******************************************************/
/* AUTHOR 	: ABDULRAHMAN OSAMA MOHAMED                */
/* DEC		: 7SEG DRIVER                               */
/* DATE		: 28/1/2020                                */
/*******************************************************/

#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"DIO_interface.h"
#include"Segment_int.h"

/****************PIN FUNCTIONS ****************************************/
/**********************************************************************/

void  SEG7_DISPLAY(u8 seg_type ,u8 port , u8 digit)
{
	if(seg_type == CK )
	{
		DIO_voidSetportDirection(port , PORT_OUT);
		switch(digit)
		{
			case 0 : DIO_voidSetportValue(port , ZERO) ;break;
			case 1 : DIO_voidSetportValue(port , ONE)  ;break;
			case 2 : DIO_voidSetportValue(port , TWO)  ;break;
			case 3 : DIO_voidSetportValue(port , THREE);break;
			case 4 : DIO_voidSetportValue(port , FOUR) ;break;
			case 5 : DIO_voidSetportValue(port , FIVE) ;break;
			case 6 : DIO_voidSetportValue(port , SIX)  ;break;
			case 7 : DIO_voidSetportValue(port , SEVEN);break;
			case 8 : DIO_voidSetportValue(port , EIGHT);break;
			case 9 : DIO_voidSetportValue(port , NINE) ;break;
			default: break ;
		}
	}
	else if (seg_type == CA)
	{
		DIO_voidSetportDirection(port , PORT_OUT);
		switch(digit)
		{
			case 0 : DIO_voidSetportValue(port , ~(ZERO)) ;break;
			case 1 : DIO_voidSetportValue(port , ~(ONE))  ;break;
			case 2 : DIO_voidSetportValue(port , ~(TWO))  ;break;
			case 3 : DIO_voidSetportValue(port , ~(THREE));break;
			case 4 : DIO_voidSetportValue(port , ~(FOUR)) ;break;
			case 5 : DIO_voidSetportValue(port , ~(FIVE)) ;break;
			case 6 : DIO_voidSetportValue(port , ~(SIX))  ;break;
			case 7 : DIO_voidSetportValue(port , ~(SEVEN));break;
			case 8 : DIO_voidSetportValue(port , ~(EIGHT));break;
			case 9 : DIO_voidSetportValue(port , ~(NINE)) ;break;
			default: DIO_voidSetportValue(port , 0x00 )   ;break ;
		}

	}
	else
	{
		/*...................*/
	}
}

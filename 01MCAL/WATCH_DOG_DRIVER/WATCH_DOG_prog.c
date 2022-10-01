
/*******************************************************/
/* AUTHOR 	: ABDULRAHMAN OSAMA MOHAMED                */
/* DEC		: WATCH DOG TIMER DRIVER                          	   */
/* DATE		: 18/2/2020                                */
/*******************************************************/

#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"DIO_interface.h"
#include "WATCH_DOG_int.h"


/*************************TIMER FUNCTIONS********************************/
/**********************************************************************/

void WDT_ENABLE()
{
	SET(WDTCR_REG,WDE);
}

/**********************************************************************/

void WDT_DISABLE()
{
	WDTCR_REG = 0xff;
	WDTCR_REG = 0X00;
	
}

/**********************************************************************/

void WDT_REFRESH()
{
	asm("WDR");
}

/**********************************************************************/
void WDT_SET_PRESCALAR(s8 VOLTAGE ,s16 TIME_OUT_ms)
{
	if(VOLTAGE == V5)
	{
		if(TIME_OUT_ms <= 16.3)
		{
			CLR(WDTCR_REG,WDP0);
			CLR(WDTCR_REG,WDP1);
			CLR(WDTCR_REG,WDP2);
		}
		else if(TIME_OUT_ms <= 32.5)
		{
			SET(WDTCR_REG,WDP0);
			CLR(WDTCR_REG,WDP1);
			CLR(WDTCR_REG,WDP2);
		}
		else if(TIME_OUT_ms <= 65)
		{
			CLR(WDTCR_REG,WDP0);
			SET(WDTCR_REG,WDP1);
			CLR(WDTCR_REG,WDP2);
		}
		else if(TIME_OUT_ms <= 130)
		{
			SET(WDTCR_REG,WDP0);
			SET(WDTCR_REG,WDP1);
			CLR(WDTCR_REG,WDP2);
		}
		else if(TIME_OUT_ms <= 260)
		{
			CLR(WDTCR_REG,WDP0);
			CLR(WDTCR_REG,WDP1);
			SET(WDTCR_REG,WDP2);
		}
		else if(TIME_OUT_ms <= 520)
		{
			SET(WDTCR_REG,WDP0);
			CLR(WDTCR_REG,WDP1);
			SET(WDTCR_REG,WDP2);
		}
		else if(TIME_OUT_ms <= 1000)
		{
			CLR(WDTCR_REG,WDP0);
			SET(WDTCR_REG,WDP1);
			SET(WDTCR_REG,WDP2);
		}
		else if(TIME_OUT_ms <= 2100)
		{
			SET(WDTCR_REG,WDP0);
			SET(WDTCR_REG,WDP1);
			SET(WDTCR_REG,WDP2);
		}
		else
		{
			SET(WDTCR_REG,WDP0);
			SET(WDTCR_REG,WDP1);
			SET(WDTCR_REG,WDP2);
		}
	}


	else if(VOLTAGE == V3)
	{
		if(TIME_OUT_ms <= 17.1)
		{
			CLR(WDTCR_REG,WDP0);
			CLR(WDTCR_REG,WDP1);
			CLR(WDTCR_REG,WDP2);
		}
		else if(TIME_OUT_ms <= 34.3)
		{
			SET(WDTCR_REG,WDP0);
			CLR(WDTCR_REG,WDP1);
			CLR(WDTCR_REG,WDP2);
		}
		else if(TIME_OUT_ms <= 68.5)
		{
			CLR(WDTCR_REG,WDP0);
			SET(WDTCR_REG,WDP1);
			CLR(WDTCR_REG,WDP2);
		}
		else if(TIME_OUT_ms <= 140)
		{
			SET(WDTCR_REG,WDP0);
			SET(WDTCR_REG,WDP1);
			CLR(WDTCR_REG,WDP2);
		}
		else if(TIME_OUT_ms <= 270)
		{
			CLR(WDTCR_REG,WDP0);
			CLR(WDTCR_REG,WDP1);
			SET(WDTCR_REG,WDP2);
		}
		else if(TIME_OUT_ms <= 550)
		{
			SET(WDTCR_REG,WDP0);
			CLR(WDTCR_REG,WDP1);
			SET(WDTCR_REG,WDP2);
		}
		else if(TIME_OUT_ms <= 1100)
		{
			CLR(WDTCR_REG,WDP0);
			SET(WDTCR_REG,WDP1);
			SET(WDTCR_REG,WDP2);
		}
		else if(TIME_OUT_ms <= 2200)
		{
			SET(WDTCR_REG,WDP0);
			SET(WDTCR_REG,WDP1);
			SET(WDTCR_REG,WDP2);
		}
		else
		{
			SET(WDTCR_REG,WDP0);
			SET(WDTCR_REG,WDP1);
			SET(WDTCR_REG,WDP2);
		}
		
	}
}

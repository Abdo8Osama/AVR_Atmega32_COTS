
/*******************************************************/
/* AUTHOR 	: ABDULRAHMAN OSAMA MOHAMED                */
/* DEC		: TIMER2 DRIVER                          	   */
/* DATE		: 18/2/2020                                */
/*******************************************************/

#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"DIO_interface.h"
#include "TIMER2_int.h"
#include "TIMER2_register.h"


/*************************TIMER FUNCTIONS********************************/
/**********************************************************************/

void (* PF_TIMER2V) (void);
void (* PF_TIMER2C) (void);

void __vector_5 (void) __attribute__ ((signal , used));

void __vector_5 (void)
{
	PF_TIMER2V();
}

void __vector_4 (void) __attribute__ ((signal , used));

void __vector_4 (void)
{
	PF_TIMER2C();
}

/**********************************************************************/

void CALLback_TIMER2V (void (* ptr) (void))
{
	PF_TIMER2V = (void (*) (void))ptr ;
}


void CALLback_TIMER2C (void (* ptr) (void))
{
	PF_TIMER2C = (void (*) (void))ptr ;
}

/**********************************************************************/

void TIMER2V_INT_Disable (void )
{
	CLR(TIMSK_REG , TOIE2);
}

/**********************************************************************/

void TIMER2C_INT_Disable (void )
{
	CLR(TIMSK_REG , OCIE2);
}

/**********************************************************************/

void TOV2_Flag_Clear(void)
{
	SET(TIFR_REG , TOV2);
}

/**********************************************************************/

void OCF2_Flag_Clear(void)
{
	SET(TIFR_REG , OCF2);
}

/**********************************************************************/

u8 TOV2_Flag_Read(void)
{
	u8 read ;
	read = GET(TIFR_REG , TOV2);
	return read;
}

/**********************************************************************/

u8 OCF2_Flag_Read(void)
{
	u8 read ;
	read = GET(TIFR_REG , OCF2);
	return read;
}

/**********************************************************************/
void TIMER2_INIT(u8 TIMER_MODE , u8 CLOCK_SOURCE , u8 INTERRUPT_POLLING ,u8 TCNT_PRELOAD ,u8 OCR_PRELOAD , u8 OCO_INVERTING_NONINVERTING)
{
	CLR(TCCR2_REG , FOC2);

	if(OCO_INVERTING_NONINVERTING == OCO2_DISABLE)
	{
		CLR(TCCR2_REG , COM20);
		CLR(TCCR2_REG , COM21);
	}
	else if(OCO_INVERTING_NONINVERTING == NONINVERTING)
	{
		CLR(TCCR2_REG , COM20);
		SET(TCCR2_REG , COM21);

	}else if(OCO_INVERTING_NONINVERTING == INVERTING)
	{
		SET(TCCR2_REG , COM20);
		SET(TCCR2_REG , COM21);
	}


	if(TIMER_MODE == NORMAL)
	{
		CLR(TCCR2_REG , WGM21);
		CLR(TCCR2_REG , WGM20);
		if(OCO_INVERTING_NONINVERTING == OCO2_TOGGLE)
		{
			SET(TCCR2_REG , COM20);
			CLR(TCCR2_REG , COM21);
		}
	}
	else if(TIMER_MODE == PWM_C_PH)
	{
		CLR(TCCR2_REG , WGM21);
		SET(TCCR2_REG , WGM20);
		//DIO_voidSetpinDirection(PORTB,PIN0,OUT);
	}
	else if(TIMER_MODE == CTC)
	{
		SET(TCCR2_REG , WGM21);
		CLR(TCCR2_REG , WGM20);
		if(OCO_INVERTING_NONINVERTING == OCO2_TOGGLE)
		{
			SET(TCCR2_REG , COM20);
			CLR(TCCR2_REG , COM21);
		}
	}
	else if(TIMER_MODE == FAST_PWM)
	{
		SET(TCCR2_REG , WGM21);
		SET(TCCR2_REG , WGM20);
		//DIO_voidSetpinDirection(PORTB,PIN0,OUT);
	}


	if(CLOCK_SOURCE == OFF)
	{
		CLR(TCCR2_REG , CS20);
		CLR(TCCR2_REG , CS21);
		CLR(TCCR2_REG , CS22);
	}
	else if(CLOCK_SOURCE == FCPU)
	{
		SET(TCCR2_REG , CS20);
		CLR(TCCR2_REG , CS21);
		CLR(TCCR2_REG , CS22);
	}
	else if(CLOCK_SOURCE == FCPU8)
	{
		CLR(TCCR2_REG , CS20);
		SET(TCCR2_REG , CS21);
		CLR(TCCR2_REG , CS22);
	}
	else if(CLOCK_SOURCE == FCPU32)
	{
		SET(TCCR2_REG , CS20);
		SET(TCCR2_REG , CS21);
		CLR(TCCR2_REG , CS22);
	}
	else if(CLOCK_SOURCE == FCPU64)
	{
		CLR(TCCR2_REG , CS20);
		CLR(TCCR2_REG , CS21);
		SET(TCCR2_REG , CS22);
	}
	else if(CLOCK_SOURCE == FCPU128)
	{
		SET(TCCR2_REG , CS20);
		CLR(TCCR2_REG , CS21);
		SET(TCCR2_REG , CS22);
	}
	else if(CLOCK_SOURCE == FCPU256)
	{
		CLR(TCCR2_REG , CS20);
		SET(TCCR2_REG , CS21);
		SET(TCCR2_REG , CS22);
	}
	else if(CLOCK_SOURCE == FCPU1024)
	{
		SET(TCCR2_REG , CS20);
		SET(TCCR2_REG , CS21);
		SET(TCCR2_REG , CS22);
	}


	if(INTERRUPT_POLLING == INTERRUPT)
	{
		SET(TIMSK_REG , TOIE2);
		SET(TIMSK_REG , OCIE2);
		SET(SREG_REG,GIE_PIN);
	}
	else if(INTERRUPT_POLLING == POLLING)
	{
		CLR(TIMSK_REG , TOIE2);
		CLR(TIMSK_REG , OCIE2);
	}


	TCNT2_REG =  TCNT_PRELOAD;
	OCR2_REG =   OCR_PRELOAD ;
}
/**********************************************************************/
void TCNT2_REG_LOAD(u8 TCNT2_VALUE)
{
	TCNT2_REG =  TCNT2_VALUE;
}
/**********************************************************************/
void OCR2_REG_LOAD(u8 OCR2_VALUE)
{
	OCR2_REG =  OCR2_VALUE;
}

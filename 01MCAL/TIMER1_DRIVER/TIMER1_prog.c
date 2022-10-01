
/*******************************************************/
/* AUTHOR 	: ABDULRAHMAN OSAMA MOHAMED                */
/* DEC		: TIMER1 DRIVER                          	   */
/* DATE		: 18/2/2020                                */
/*******************************************************/

#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"DIO_interface.h"
#include "TIMER1_int.h"
#include "TIMER1_register.h"


/*************************TIMER FUNCTIONS********************************/
/**********************************************************************/

void (* PF_TIMER1V)  (void);
void (* PF_TIMER1CA) (void);
void (* PF_TIMER1CB) (void);
void (* PF_TIMER1IC) (void);

void __vector_6 (void) __attribute__ ((signal , used));

void __vector_6 (void)
{
	PF_TIMER1IC();
}


void __vector_7 (void) __attribute__ ((signal , used));

void __vector_7 (void)
{
	PF_TIMER1CA();
}


void __vector_8 (void) __attribute__ ((signal , used));

void __vector_8 (void)
{
	PF_TIMER1CB();
}


void __vector_9 (void) __attribute__ ((signal , used));

void __vector_9 (void)
{
	PF_TIMER1V();
}

/**********************************************************************/

void CALLback_TIMER1IC (void (* ptr) (void))
{
	PF_TIMER1IC = (void (*) (void))ptr ;
}

void CALLback_TIMER1CA (void (* ptr) (void))
{
	PF_TIMER1CA = (void (*) (void))ptr ;
}

void CALLback_TIMER1CB (void (* ptr) (void))
{
	PF_TIMER1CB = (void (*) (void))ptr ;
}

void CALLback_TIMER1V (void (* ptr) (void))
{
	PF_TIMER1V = (void (*) (void))ptr ;
}

/**********************************************************************/

u8 OCF1A_Flag_Read(void)
{
	u8 read;
	read = GET(TIFR_REG , OCF1A);
	return read;
}
/**********************************************************************/

u8 OCF1B_Flag_Read(void)
{
	u8 read;
	read = GET(TIFR_REG , OCF1B);
	return read;
}
/**********************************************************************/

u8 TOV1_Flag_Read(void)
{
	u8 read;
	read = GET(TIFR_REG , TOV1);
	return read;
}
/**********************************************************************/

u8 ICF1_Flag_Read(void)
{
	u8 read;
	read = GET(TIFR_REG , ICF1);
	return read;
}
/**********************************************************************/

void OCF1A_Flag_Clear(void)
{
	SET(TIFR_REG , OCF1A);
}
/**********************************************************************/

void OCF1B_Flag_Clear(void)
{
	SET(TIFR_REG , OCF1B);
}

/**********************************************************************/

void TOV1_Flag_Clear(void)
{
	SET(TIFR_REG , TOV1);
}

/**********************************************************************/

void ICF1_Flag_Clear(void)
{
	SET(TIFR_REG , ICF1);
}

/**********************************************************************/


void TIMER1OCA_INT_Disable (void )
{
	CLR(TIMSK_REG , OCIE1A);
}
/**********************************************************************/

void TIMER1OCB_INT_Disable (void )
{
	CLR(TIMSK_REG , OCIE1B);
}
/**********************************************************************/

void TIMER1OV_INT_Disable (void )
{
	CLR(TIMSK_REG , TOIE1);
}
/**********************************************************************/

void TIMER1IC_INT_Disable (void )
{
	CLR(TIMSK_REG , TICIE1);
}
/**********************************************************************/


void TCNT1_REG_LOAD(u16 TCNT1_VALUE)
{
	TCNT1L_REG =  TCNT1_VALUE;
}
/**********************************************************************/

void OCR1A_REG_LOAD(u16 OCR1A_VALUE)
{
	OCR1AL_REG = OCR1A_VALUE;
}
/**********************************************************************/

void OCR1B_REG_LOAD(u16 OCR1B_VALUE)
{
	OCR1BL_REG = OCR1B_VALUE;
}
/**********************************************************************/

void ICR1_REG_LOAD(u16 ICR1_VALUE)
{
	ICR1L_REG = ICR1_VALUE;
}
/**********************************************************************/


void TIMER1_INIT(u8 TIMER_MODE ,u8 ICU_SENSING_EDGE , u8 CLOCK_SOURCE , u8 INTERRUPT_POLLING ,u16 TCNT_PRELOAD ,u16 OCRA_PRELOAD , u16 OCRB_PRELOAD , u16 ICR_PRELOAD, u8 OCO_INVERTING_NONINVERTING)
{
	CLR(TCCR1A_REG , FOC1A);
	CLR(TCCR1A_REG , FOC1B);

	if(ICU_SENSING_EDGE == FALLING_EDGE_ICU)
	{
		CLR(TCCR1B_REG , ICES1);
		SET(TCCR1B_REG , ICNC1 );
	}
	else if(ICU_SENSING_EDGE == RISING_EDGE_ICU)
	{
		SET(TCCR1B_REG , ICES1);
		SET(TCCR1B_REG , ICNC1);
	}

	if(OCO_INVERTING_NONINVERTING == OCO1A_OCO1B_DISABLE)
	{
		CLR(TCCR1A_REG , COM1A0);
		CLR(TCCR1A_REG , COM1A1);
		CLR(TCCR1A_REG , COM1B0);
		CLR(TCCR1A_REG , COM1B1);
	}
	else if(OCO_INVERTING_NONINVERTING == NONINVERTING)
	{
		CLR(TCCR1A_REG , COM1A0);
		SET(TCCR1A_REG , COM1A1);
		CLR(TCCR1A_REG , COM1B0);
		SET(TCCR1A_REG , COM1B1);

	}else if(OCO_INVERTING_NONINVERTING == INVERTING)
	{
		SET(TCCR1A_REG , COM1A0);
		SET(TCCR1A_REG , COM1A1);
		SET(TCCR1A_REG , COM1B0);
		SET(TCCR1A_REG , COM1B1);
	}else if(OCO_INVERTING_NONINVERTING == OCO1A_OCO1B_TOGGLE)
	{
		SET(TCCR1A_REG , COM1A0);
		CLR(TCCR1A_REG , COM1A1);
		SET(TCCR1A_REG , COM1B0);
		CLR(TCCR1A_REG , COM1B1);
	}

	if(TIMER_MODE ==NORMAL)
	{
		CLR(TCCR1A_REG , WGM10);
		CLR(TCCR1A_REG , WGM11);
		CLR(TCCR1B_REG , WGM12);
		CLR(TCCR1B_REG , WGM13);

	}
	else if(TIMER_MODE ==PWM_C_PH8)
	{
		SET(TCCR1A_REG , WGM10);
		CLR(TCCR1A_REG , WGM11);
		CLR(TCCR1B_REG , WGM12);
		CLR(TCCR1B_REG , WGM13);

	}
	else if(TIMER_MODE ==PWM_C_PH9)
	{
		CLR(TCCR1A_REG , WGM10);
		SET(TCCR1A_REG , WGM11);
		CLR(TCCR1B_REG , WGM12);
		CLR(TCCR1B_REG , WGM13);
	}
	else if(TIMER_MODE ==PWM_C_PH10)
	{
		SET(TCCR1A_REG , WGM10);
		SET(TCCR1A_REG , WGM11);
		CLR(TCCR1B_REG , WGM12);
		CLR(TCCR1B_REG , WGM13);
	}
	else if(TIMER_MODE ==CTC_OCR1A)
	{
		CLR(TCCR1A_REG , WGM10);
		CLR(TCCR1A_REG , WGM11);
		SET(TCCR1B_REG , WGM12);
		CLR(TCCR1B_REG , WGM13);

	}
	else if(TIMER_MODE ==FAST_PWM8)
	{
		SET(TCCR1A_REG , WGM10);
		CLR(TCCR1A_REG , WGM11);
		SET(TCCR1B_REG , WGM12);
		CLR(TCCR1B_REG , WGM13);

	}
	else if(TIMER_MODE ==FAST_PWM9)
	{
		CLR(TCCR1A_REG , WGM10);
		SET(TCCR1A_REG , WGM11);
		SET(TCCR1B_REG , WGM12);
		CLR(TCCR1B_REG , WGM13);

	}
	else if(TIMER_MODE ==FAST_PWM10)
	{
		SET(TCCR1A_REG , WGM10);
		SET(TCCR1A_REG , WGM11);
		SET(TCCR1B_REG , WGM12);
		CLR(TCCR1B_REG , WGM13);

	}
	else if(TIMER_MODE ==PWM_C_PHF_ICR1)
	{
		CLR(TCCR1A_REG , WGM10);
		CLR(TCCR1A_REG , WGM11);
		CLR(TCCR1B_REG , WGM12);
		SET(TCCR1B_REG , WGM13);
	}
	else if(TIMER_MODE ==PWM_C_PHF_OCR1A)
	{
		SET(TCCR1A_REG , WGM10);
		CLR(TCCR1A_REG , WGM11);
		CLR(TCCR1B_REG , WGM12);
		SET(TCCR1B_REG , WGM13);
	}
	else if(TIMER_MODE ==PWM_C_PH_ICR1)
	{
		CLR(TCCR1A_REG , WGM10);
		SET(TCCR1A_REG , WGM11);
		CLR(TCCR1B_REG , WGM12);
		SET(TCCR1B_REG , WGM13);
	}
	else if(TIMER_MODE ==PWM_C_PH_OCR1A)
	{
		SET(TCCR1A_REG , WGM10);
		SET(TCCR1A_REG , WGM11);
		CLR(TCCR1B_REG , WGM12);
		SET(TCCR1B_REG , WGM13);
	}
	else if(TIMER_MODE ==CTC_ICR1)
	{
		CLR(TCCR1A_REG , WGM10);
		CLR(TCCR1A_REG , WGM11);
		SET(TCCR1B_REG , WGM12);
		SET(TCCR1B_REG , WGM13);

	}
	else if(TIMER_MODE ==FAST_PWM_ICR1)
	{
		CLR(TCCR1A_REG , WGM10);
		SET(TCCR1A_REG , WGM11);
		SET(TCCR1B_REG , WGM12);
		SET(TCCR1B_REG , WGM13);

	}
	else if(TIMER_MODE ==FAST_PWM_OCR1A)
	{
		SET(TCCR1A_REG , WGM10);
		SET(TCCR1A_REG , WGM11);
		SET(TCCR1B_REG , WGM12);
		SET(TCCR1B_REG , WGM13);

	}



	if(CLOCK_SOURCE == OFF)
	{
		CLR(TCCR1B_REG , CS10);
		CLR(TCCR1B_REG , CS11);
		CLR(TCCR1B_REG , CS12);
	}
	else if(CLOCK_SOURCE == FCPU)
	{
		SET(TCCR1B_REG , CS10);
		CLR(TCCR1B_REG , CS11);
		CLR(TCCR1B_REG , CS12);
	}
	else if(CLOCK_SOURCE == FCPU8)
	{
		CLR(TCCR1B_REG , CS10);
		SET(TCCR1B_REG , CS11);
		CLR(TCCR1B_REG , CS12);
	}
	else if(CLOCK_SOURCE == FCPU64)
	{
		SET(TCCR1B_REG , CS10);
		SET(TCCR1B_REG , CS11);
		CLR(TCCR1B_REG , CS12);
	}
	else if(CLOCK_SOURCE == FCPU256)
	{
		CLR(TCCR1B_REG , CS10);
		CLR(TCCR1B_REG , CS11);
		SET(TCCR1B_REG , CS12);
	}
	else if(CLOCK_SOURCE == FCPU1024)
	{
		SET(TCCR1B_REG , CS10);
		CLR(TCCR1B_REG , CS11);
		SET(TCCR1B_REG , CS12);
	}
	else if(CLOCK_SOURCE == FALLING_EDGE_COUNTER)
	{
		CLR(TCCR1B_REG , CS10);
		SET(TCCR1B_REG , CS11);
		SET(TCCR1B_REG , CS12);
		DIO_voidSetpinDirection(PORTB,PIN1,IN);
		DIO_voidSetpinValue(PORTB,PIN1,HIGH);
	}
	else if(CLOCK_SOURCE == RISING_EDGE_COUNTER)
	{
		SET(TCCR1B_REG , CS10);
		SET(TCCR1B_REG , CS11);
		SET(TCCR1B_REG , CS12);
		DIO_voidSetpinDirection(PORTB,PIN1,IN);
		DIO_voidSetpinValue(PORTB,PIN1,LOW);

	}


	if(INTERRUPT_POLLING == INTERRUPT)
	{
		SET(TIMSK_REG , TOIE1);
		SET(TIMSK_REG , OCIE1A);
		SET(TIMSK_REG , OCIE1B);
		SET(TIMSK_REG , TICIE1);
		SET(SREG_REG,GIE_PIN);
	}
	else if(INTERRUPT_POLLING == POLLING)
	{
		CLR(TIMSK_REG , TOIE1);
		CLR(TIMSK_REG , OCIE1A);
		CLR(TIMSK_REG , OCIE1B);
		CLR(TIMSK_REG , TICIE1);
	}

	TCNT1L_REG =  TCNT_PRELOAD;
	OCR1AL_REG = OCRA_PRELOAD;
	OCR1BL_REG = OCRB_PRELOAD;
	//ICR1_REG = ICR_PRELOAD;

}

void ICU_SET_RISING_EDGE()
{
	SET(TCCR1B_REG , ICES1);
	SET(TCCR1B_REG , ICNC1);
}

void ICU_SET_FALLING_EDGE()
{
	CLR(TCCR1B_REG , ICES1);
	SET(TCCR1B_REG , ICNC1);
}

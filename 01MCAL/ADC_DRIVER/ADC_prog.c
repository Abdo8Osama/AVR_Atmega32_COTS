
/*******************************************************/
/* AUTHOR 	: ABDULRAHMAN OSAMA MOHAMED                */
/* DEC		: ADC DRIVER                              */
/* DATE		: 11/2/2020                                */
/*******************************************************/

#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"ADC_int.h"
#include"ADC_register.h"
#include"DIO_interface.h"
/*************************ADC FUNCTIONS********************************/
/**********************************************************************/
void (* PF_ADC) (void);

void __vector_16 (void) __attribute__ ((signal , used));

void __vector_16 (void)
{
	PF_ADC();
}

/**********************************************************************/

void CALLback_ADC (void (* ptr) (void))
{
	PF_ADC = ptr ;
}

/**********************************************************************/

void ADC_INT_Disable (void )
{
	CLR(ADCSRA_REG ,ADIE );
}

/**********************************************************************/

u32 ADC_Get_Value(void)
{
	u32 digital_value ;
	digital_value = (((ADCL_REG|ADCH_REG<<8)));
	return digital_value ;
}

/**********************************************************************/

void ADIF_Flag_Clear(void)
{
	SET(ADCSRA_REG , ADIF);
}

/**********************************************************************/

void ADC_StartConversion(void)
{
	SET(ADCSRA_REG ,ADSC );
}

/**********************************************************************/

u8 ADIF_Flag_Read(void)
{
	u8 read ;
	read = GET(ADCSRA_REG , ADIF);
	return read;
}

/**********************************************************************/

void ADC_SingleEnded_void_initialize(u8 ADC_u8_PIN , u8 AREF_AVCC_INTERNAL ,u8 INTERRUPT_POLLING ,u8 RIGHT_LEFT_ADJUSTMENT , u8 singleConv_AutoT )
{
	/*SET ADC PIN TO INPUT */
	DIO_voidSetpinDirection(PORTA , ADC_u8_PIN , IN);

	if(AREF_AVCC_INTERNAL == AREF)
	{
		CLR(ADMUX_REG ,REFS1 );
		CLR(ADMUX_REG ,REFS0 );
	}
	else if(AREF_AVCC_INTERNAL == AVCC)
	{
		CLR(ADMUX_REG ,REFS1 );
		SET(ADMUX_REG ,REFS0 );
	}
	else if(AREF_AVCC_INTERNAL == INTERNAL)
	{
		SET(ADMUX_REG ,REFS1 );
		SET(ADMUX_REG ,REFS0 );
	}



	if(RIGHT_LEFT_ADJUSTMENT == R_ADJ)
	{
		CLR(ADMUX_REG ,ADLAR );
	}
	else if(RIGHT_LEFT_ADJUSTMENT == L_ADJ)
	{
		SET(ADMUX_REG ,ADLAR );
	}



	if(singleConv_AutoT == SINGLE)
	{
		CLR(ADCSRA_REG ,ADATE );
	}
	else if(singleConv_AutoT == AUTO)
	{
		SET(ADCSRA_REG ,ADATE );
	}


	if(INTERRUPT_POLLING == INTERRUPT)
	{
		SET(ADCSRA_REG ,ADIE );
		SET(SREG_REG,GIE_PIN);

	}
	else if(INTERRUPT_POLLING == POLLING)
	{
		CLR(ADCSRA_REG ,ADIE );
	}



	switch(ADC_u8_PIN)
	{
	case ADC0 :
		CLR(ADMUX_REG ,MUX4 );
		CLR(ADMUX_REG ,MUX3 );
		CLR(ADMUX_REG ,MUX2 );
		CLR(ADMUX_REG ,MUX1 );
		CLR(ADMUX_REG ,MUX0 );
		break ;
	case ADC1 :
		CLR(ADMUX_REG ,MUX4 );
		CLR(ADMUX_REG ,MUX3 );
		CLR(ADMUX_REG ,MUX2 );
		CLR(ADMUX_REG ,MUX1 );
		SET(ADMUX_REG ,MUX0 );
		break ;
	case ADC2 :
		CLR(ADMUX_REG ,MUX4 );
		CLR(ADMUX_REG ,MUX3 );
		CLR(ADMUX_REG ,MUX2 );
		SET(ADMUX_REG ,MUX1 );
		CLR(ADMUX_REG ,MUX0 );
		break ;
	case ADC3 :
		CLR(ADMUX_REG ,MUX4 );
		CLR(ADMUX_REG ,MUX3 );
		CLR(ADMUX_REG ,MUX2 );
		SET(ADMUX_REG ,MUX1 );
		SET(ADMUX_REG ,MUX0 );
		break ;
	case ADC4 :
		CLR(ADMUX_REG ,MUX4 );
		CLR(ADMUX_REG ,MUX3 );
		SET(ADMUX_REG ,MUX2 );
		CLR(ADMUX_REG ,MUX1 );
		CLR(ADMUX_REG ,MUX0 );
		break ;
	case ADC5 :
		CLR(ADMUX_REG ,MUX4 );
		CLR(ADMUX_REG ,MUX3 );
		SET(ADMUX_REG ,MUX2 );
		CLR(ADMUX_REG ,MUX1 );
		SET(ADMUX_REG ,MUX0 );
		break ;
	case ADC6 :
		CLR(ADMUX_REG ,MUX4 );
		CLR(ADMUX_REG ,MUX3 );
		SET(ADMUX_REG ,MUX2 );
		SET(ADMUX_REG ,MUX1 );
		CLR(ADMUX_REG ,MUX0 );
		break ;
	case ADC7 :
		CLR(ADMUX_REG ,MUX4 );
		CLR(ADMUX_REG ,MUX3 );
		SET(ADMUX_REG ,MUX2 );
		SET(ADMUX_REG ,MUX1 );
		SET(ADMUX_REG ,MUX0 );
		break ;
	}
	SET(ADCSRA_REG ,ADEN );
	SET(ADCSRA_REG ,ADIF );
	SET(ADCSRA_REG ,ADPS2 );
	SET(ADCSRA_REG ,ADPS1 );
	SET(ADCSRA_REG ,ADPS0 );
	SET(ADCSRA_REG ,ADSC );


}

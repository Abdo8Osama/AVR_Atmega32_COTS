/*******************************************************/
/* AUTHOR 	: ABDULRAHMAN OSAMA MOHAMED                */
/* DEC		: RTOS LAYER                               */
/* DATE		: 22/3/2020                                */
/*******************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "RTOS_config.h"
#include "RTOS_interface.h"
#include "RTOS_private.h"
#include "RTOS_reg.h"

static void (* PF_TIMER0V) (void);
static void (* PF_TIMER0C) (void);

void __vector_11 (void) __attribute__ ((signal , used));

void __vector_11 (void)
{
	PF_TIMER0V();
}

void __vector_10 (void) __attribute__ ((signal , used));

void __vector_10 (void)
{
	PF_TIMER0C();
}



/**********************************************************************/
/**********************************************************************/

static void CALLback_TIMER0V (void (* ptr) (void))
{
	PF_TIMER0V = (void (*) (void))ptr ;
}


static void CALLback_TIMER0C (void (* ptr) (void))
{
	PF_TIMER0C = (void (*) (void))ptr ;
}


/**********************************************************************/
/**********************************************************************/

static void TIMER_INIT(u8 TIMER_MODE , u8 CLOCK_SOURCE , u8 INTERRUPT_POLLING ,u8 TCNT_PRELOAD ,u8 OCR_PRELOAD , u8 OCO_INVERTING_NONINVERTING)
{
	CLR(TCCR0_REG , FOC0);

	if(OCO_INVERTING_NONINVERTING == OCO_DISABLE)
	{
		CLR(TCCR0_REG , COM00);
		CLR(TCCR0_REG , COM01);
	}
	else if(OCO_INVERTING_NONINVERTING == NONINVERTING)
	{
		CLR(TCCR0_REG , COM00);
		SET(TCCR0_REG , COM01);

	}else if(OCO_INVERTING_NONINVERTING == INVERTING)
	{
		SET(TCCR0_REG , COM00);
		SET(TCCR0_REG , COM01);
	}


	if(TIMER_MODE == NORMAL)
	{
		CLR(TCCR0_REG , WGM01);
		CLR(TCCR0_REG , WGM00);
		if(OCO_INVERTING_NONINVERTING == OCO_TOGGLE)
		{
			SET(TCCR0_REG , COM00);
			CLR(TCCR0_REG , COM01);
		}
	}
	else if(TIMER_MODE == PWM)
	{
		CLR(TCCR0_REG , WGM01);
		SET(TCCR0_REG , WGM00);
	}
	else if(TIMER_MODE == CTC)
	{
		SET(TCCR0_REG , WGM01);
		CLR(TCCR0_REG , WGM00);
		if(OCO_INVERTING_NONINVERTING == OCO_TOGGLE)
		{
			SET(TCCR0_REG , COM00);
			CLR(TCCR0_REG , COM01);
		}
	}
	else if(TIMER_MODE == FAST_PWM)
	{
		SET(TCCR0_REG , WGM01);
		SET(TCCR0_REG , WGM00);
	}


	if(CLOCK_SOURCE == OFF)
	{
		CLR(TCCR0_REG , CS00);
		CLR(TCCR0_REG , CS01);
		CLR(TCCR0_REG , CS02);
	}
	else if(CLOCK_SOURCE == FCPU)
	{
		SET(TCCR0_REG , CS00);
		CLR(TCCR0_REG , CS01);
		CLR(TCCR0_REG , CS02);
	}
	else if(CLOCK_SOURCE == FCPU8)
	{
		CLR(TCCR0_REG , CS00);
		SET(TCCR0_REG , CS01);
		CLR(TCCR0_REG , CS02);
	}
	else if(CLOCK_SOURCE == FCPU64)
	{
		SET(TCCR0_REG , CS00);
		SET(TCCR0_REG , CS01);
		CLR(TCCR0_REG , CS02);
	}
	else if(CLOCK_SOURCE == FCPU256)
	{
		CLR(TCCR0_REG , CS00);
		CLR(TCCR0_REG , CS01);
		SET(TCCR0_REG , CS02);
	}
	else if(CLOCK_SOURCE == FCPU1024)
	{
		SET(TCCR0_REG , CS00);
		CLR(TCCR0_REG , CS01);
		SET(TCCR0_REG , CS02);
	}
	else if(CLOCK_SOURCE == FALLING_EDGE_COUNTER)
	{
		CLR(TCCR0_REG , CS00);
		SET(TCCR0_REG , CS01);
		SET(TCCR0_REG , CS02);
		DIO_voidSetpinDirection(PORTB,PIN0,IN);
		DIO_voidSetpinValue(PORTB,PIN0,HIGH);
	}
	else if(CLOCK_SOURCE == RISING_EDGE_COUNTER)
	{
		SET(TCCR0_REG , CS00);
		SET(TCCR0_REG , CS01);
		SET(TCCR0_REG , CS02);
		DIO_voidSetpinDirection(PORTB,PIN0,IN);
		DIO_voidSetpinValue(PORTB,PIN0,LOW);

	}


	if(INTERRUPT_POLLING == INTERRUPT_OV)
	{
		SET(TIMSK_REG , TOIE0);
		SET(SREG_REG,GIE_PIN);
	}
	else if(INTERRUPT_POLLING == INTERRUPT_OC)
	{
		SET(TIMSK_REG , OCIE0);
		SET(SREG_REG,GIE_PIN);
	}

	else if(INTERRUPT_POLLING == POLLING)
	{
		CLR(TIMSK_REG , TOIE0);
		CLR(TIMSK_REG , OCIE0);
	}


	TCNT0_REG =  TCNT_PRELOAD;
	OCR0_REG =   OCR_PRELOAD ;
}

/**********************************************************************/
/**********************************************************************/

Task_t SysTasks[TASK_NUM];

void RTOS_CREAT_TASK(u32 Task_Periodicity , u8 Task_Priority, void (*ptr)(void))
{
	SysTasks[Task_Priority].Periodicity=Task_Periodicity;
	SysTasks[Task_Priority].TaskHandler_ptr=ptr;
	SysTasks[Task_Priority].status =RESUME;
}
/**********************************************************************/
/**********************************************************************/

/*used for RTOS Initialisation*/
void RTOS_voidStart(void)
{
	CALLback_TIMER(&Scheduler);
	TIMER_INIT(NORMAL , FCPU8 , INTERRUPT , 192 , 0 ,OCO_DISABLE);
}
/**********************************************************************/
/**********************************************************************/

void RTOS_SUSPEND_TASK(u8 TASK_ID)
{
	SysTasks[TASK_ID].status = SUSPENDED ;
}
/**********************************************************************/
/**********************************************************************/

void RTOS_RESUME_TASK(u8 TASK_ID)
{
	SysTasks[TASK_ID].status = RESUME ;
}
/**********************************************************************/
/**********************************************************************/
static void Scheduler(void)
{
	static u32 System_Counter=0;
	u8 Local_Iterator;
	System_Counter++;

	for(Local_Iterator=0;Local_Iterator<TASK_NUM;Local_Iterator++)
	{
		if(SysTasks[Local_Iterator].status == RESUME)
		{
			if((System_Counter % (SysTasks[Local_Iterator].Periodicity)) == 0)
			{
				/*Invoke the Task C Function*/
				SysTasks[Local_Iterator].TaskHandler_ptr();
			}
			else
			{
				/*Do Nothing*/
			}
		}
	}

}

/**********************************************************************/
/**********************************************************************/

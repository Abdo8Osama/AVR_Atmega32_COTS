/****************GUARD MY FILE********************/

#ifndef AVR_TIMERS_REG_H_
#define AVR_TIMERS_REG_H_

#define		TCCR0_REG 		*((volatile u8*)0X53)
#define		TCNT0_REG 		*((volatile u8*)0X52)
#define		OCR0_REG 		*((volatile u8*)0X5C)
#define		TIMSK_REG 		*((volatile u8*)0X59)
#define		TIFR_REG 		*((volatile u8*)0X58)

#define 	SREG_REG		*((volatile u8 *)0x5F)


//TCCR0_REG
#define	FOC0 	7
#define	WGM00 	6
#define	COM01 	5
#define	COM00 	4
#define	WGM01 	3
#define	CS02 	2
#define	CS01 	1
#define	CS00 	0
//TIMSK_REG
#define	TOIE0 	0
#define	OCIE0	1
//TIFR_REG
#define	TOV0 	0
#define	OCF0	1
//SREG_REG
#define GIE_PIN		7		
//TIMER_PIN
#define	TIMER0		0
#define	TIMER1		1
#define	TIMER2		2
//TIMER_MODE
#define	NORMAL		0
#define	PWM			1
#define	CTC			2
#define	FAST_PWM	3
//CLOCK_SOURCE
#define	OFF						0
#define	FCPU					1
#define	FCPU8					2
#define	FCPU64					3
#define	FCPU256					4
#define	FCPU1024				5
#define	FALLING_EDGE_COUNTER	6
#define	RISING_EDGE_COUNTER		7
//INTERRUPT_POLLING
#define	INTERRUPTOV	0
#define	INTERRUPTOC	3
#define	POLLING		1
//OCO_INVERTING_NONINVERTING
#define	OCO_DISABLE			0
#define	OCO_TOGGLE			1
#define	NONINVERTING		2
#define	INVERTING			3


#endif /* AVR_TIMERS_REG_H_ */

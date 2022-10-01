/*
 * 	FileName  : TIMER1_interface.h
 *  Created on: 18/2/2020
 *  Author    : ABDULRAHMAN OSAMA 
 */

/****************GUARD MY FILE********************/
#ifndef TIMER1_INTERFACE_H
#define TIMER1_INTERFACE_H

//TCCR1A_REG
#define	COM1A1  	7
#define	COM1A0  	6
#define	COM1B1  	5
#define	COM1B0  	4
#define	FOC1A  		3
#define	FOC1B  		2
#define	WGM11  		1
#define	WGM10  		0

//TCCR1B_REG
#define	ICNC1  	7
#define	ICES1  	6
#define	WGM13  	4
#define	WGM12  	3
#define	CS12  	2
#define	CS11  	1
#define	CS10  	0
    
//TIMSK_REG
#define	TOIE1 	2
#define	OCIE1B	3
#define	OCIE1A	4
#define	TICIE1	5
    
//TIFR_REG
#define	TOV1 	2
#define	OCF1B	3
#define	OCF1A	4
#define	ICF1	5

//SREG_REG
#define GIE_PIN		7
	
//TIMER_MODE
#define	NORMAL				0
#define	PWM_C_PH8			1
#define	PWM_C_PH9			2
#define	PWM_C_PH10			3
#define	CTC_OCR1A 			4
#define	FAST_PWM8			5
#define	FAST_PWM9			6
#define	FAST_PWM10			7
#define	PWM_C_PHF_ICR1		8
#define	PWM_C_PHF_OCR1A 	9
#define	PWM_C_PH_ICR1		10
#define	PWM_C_PH_OCR1A 		11
#define	CTC_ICR1			12
#define	FAST_PWM_ICR1 		14
#define	FAST_PWM_OCR1A 		15

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
#define	INTERRUPT	0
#define	POLLING		1

//ICU_SENSING_EDGE
#define	FALLING_EDGE_ICU	0
#define	RISING_EDGE_ICU		1

//OCO_INVERTING_NONINVERTING
#define	OCO1A_OCO1B_DISABLE			0
#define	OCO1A_OCO1B_TOGGLE			1
#define	NONINVERTING				2
#define	INVERTING					3

/****************TIMER FUNCTIONS *********************/
void TIMER1_INIT(u8 TIMER_MODE ,u8 ICU_SENSING_EDGE , u8 CLOCK_SOURCE , u8 INTERRUPT_POLLING ,u16 TCNT_PRELOAD ,u16 OCRA_PRELOAD , u16 OCRB_PRELOAD , u16 ICR_PRELOAD, u8 OCO_INVERTING_NONINVERTING);

u8 OCF1A_Flag_Read(void);
u8 OCF1B_Flag_Read(void);
u8 TOV1_Flag_Read(void);
u8 ICF1_Flag_Read(void);

void OCF1A_Flag_Clear(void);
void OCF1B_Flag_Clear(void);
void TOV1_Flag_Clear(void);
void ICF1_Flag_Clear(void);
    
void TIMER1OCA_INT_Disable (void );
void TIMER1OCB_INT_Disable (void );
void TIMER1OV_INT_Disable (void );
void TIMER1IC_INT_Disable (void );

void CALLback_TIMER1V (void (* ptr) (void));
void CALLback_TIMER1CA (void (* ptr) (void));
void CALLback_TIMER1CB (void (* ptr) (void));
void CALLback_TIMER1IC (void (* ptr) (void));

void TCNT1_REG_LOAD(u16 TCNT1_VALUE);
void OCR1A_REG_LOAD(u16 OCR1A_VALUE);
void OCR1B_REG_LOAD(u16 OCR1B_VALUE);
void ICR1_REG_LOAD(u16 ICR1_VALUE);

void ICU_SET_RISING_EDGE();
void ICU_SET_FALLING_EDGE();




#endif



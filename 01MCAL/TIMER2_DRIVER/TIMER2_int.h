/*
 * 	FileName  : TIMER2_interface.h
 *  Created on: 18/2/2020
 *  Author    : ABDULRAHMAN OSAMA 
 */

/****************GUARD MY FILE********************/
#ifndef TIMER2_INTERFACE_H
#define TIMER2_INTERFACE_H

/****************TIMER FUNCTIONS *********************/

//TCCR2_REG        
#define	FOC2 	7
#define	WGM20 	6
#define	COM21 	5
#define	COM20 	4
#define	WGM21 	3
#define	CS22 	2
#define	CS21 	1
#define	CS20 	0
	
//TIMSK_REG
#define	OCIE2 	7
#define	TOIE2 	6

//TIFR_REG  
#define	OCF2 	7
#define	TOV2 	6

//SREG_REG
#define GIE_PIN		7

//TIMER_MODE
#define	NORMAL		0
#define	PWM_C_PH	1
#define	CTC			2
#define	FAST_PWM	3

//CLOCK_SOURCE
#define	OFF						0
#define	FCPU					1
#define	FCPU8					2
#define	FCPU32					3
#define	FCPU64					4
#define	FCPU128					5
#define	FCPU256					6
#define	FCPU1024				7

//INTERRUPT_POLLING
#define	INTERRUPT	0
#define	POLLING		1

//OCO_INVERTING_NONINVERTING
#define	OCO2_DISABLE			0
#define	OCO2_TOGGLE			1
#define	NONINVERTING		2
#define	INVERTING			3

/****************TIMER FUNCTIONS *********************/
void CALLback_TIMER2V (void (* ptr) (void));
void CALLback_TIMER2C (void (* ptr) (void));
void TIMER2V_INT_Disable (void );
void TIMER2C_INT_Disable (void );
void TOV2_Flag_Clear(void);
void OCF2_Flag_Clear(void);
u8 TOV2_Flag_Read(void);
u8 OCF2_Flag_Read(void);
void TIMER2_INIT(u8 TIMER_MODE , u8 CLOCK_SOURCE , u8 INTERRUPT_POLLING ,u8 TCNT_PRELOAD ,u8 OCR_PRELOAD , u8 OCO_INVERTING_NONINVERTING);
void TCNT2_REG_LOAD(u8 TCNT2_VALUE);
void OCR2_REG_LOAD(u8 OCR2_VALUE);

#endif



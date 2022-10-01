/*
 * 	FileName  : TIMER1_register.h
 *  Created on: 18/2/2020
 *  Author    : ABDULRAHMAN OSAMA 
 */

/****************GUARD MY FILE********************/

#ifndef TIMER1_REGISTER_H
#define TIMER1_REGISTER_H

/* REGITER DEFINITIONS */
#define		TCCR1A_REG 		*((volatile u8*)0X4F)
#define		TCCR1B_REG 		*((volatile u8*)0X4E)

#define		TCNT1H_REG 		*((volatile u8*)0X4D)
#define		TCNT1L_REG 		*((volatile u8*)0X4C)

#define		OCR1AH_REG 		*((volatile u8*)0X4B)
#define		OCR1AL_REG 		*((volatile u8*)0X4A)

#define		OCR1BH_REG 		*((volatile u8*)0X49)
#define		OCR1BL_REG 		*((volatile u8*)0X48)

#define		ICR1H_REG 		*((volatile u8*)0X47)
#define		ICR1L_REG 		*((volatile u8*)0X46)

#define		TIMSK_REG 		*((volatile u8*)0X59)
#define		TIFR_REG 		*((volatile u8*)0X58)
#define 	SREG_REG		*((volatile u8 *)0x5F)


#endif	


 
 
  



  
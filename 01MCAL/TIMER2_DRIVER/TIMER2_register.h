/*
 * 	FileName  : TIMER2_register.h
 *  Created on: 18/2/2020
 *  Author    : ABDULRAHMAN OSAMA 
 */

/****************GUARD MY FILE********************/

#ifndef TIMER2_REGISTER_H
#define TIMER2_REGISTER_H

/* REGITER DEFINITIONS */
#define		TCCR2_REG 		*((volatile u8*)0X45)
#define		TCNT2_REG 		*((volatile u8*)0X44)
#define		OCR2_REG 		*((volatile u8*)0X43)

#define		TIMSK_REG 		*((volatile u8*)0X59)
#define		TIFR_REG 		*((volatile u8*)0X58)
#define 	SREG_REG		*((volatile u8 *)0x5F)


#endif	


   

 
  



  
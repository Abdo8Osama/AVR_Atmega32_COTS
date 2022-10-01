/*
 * 	FileName  : ADC_register.h
 *  Created on: 11/2/2020 
 *  Author    : ABDULRAHMAN OSAMA MOHAMED
 */
/****************GUARD MY FILE********************/

#ifndef ADC_REGISTER_H
#define ADC_REGISTER_H


/* REGITER DEFINITIONS */
#define ADMUX_REG 	*((volatile u8 *)0x27)
#define ADCSRA_REG 	*((volatile u8 *)0x26)
#define ADCH_REG 	*((volatile u8 *)0x25)
#define ADCL_REG 	*((volatile u8 *)0x24)

#define SREG_REG	*((volatile u8 *)0x5F)



#endif	/* EXTERNAL_INTERRUPT _REG_H */



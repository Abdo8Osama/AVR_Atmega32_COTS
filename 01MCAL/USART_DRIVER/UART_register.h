/*
 * 	FileName  : UART_register.h
 *  Created on: 25/2/2020
 *  Author    : ABDULRAHMAN OSAMA 
 */

#ifndef UART_REGISTER_H_
#define UART_REGISTER_H_

#define		UBRRH_REG   	*((volatile u8*)0X40)
#define		UCSRC_REG   	*((volatile u8*)0X40)
#define		UDR_REG 		*((volatile u8*)0X2C)
#define		UCSRA_REG 		*((volatile u8*)0X2B)
#define		UCSRB_REG 		*((volatile u8*)0X2A)
#define		UBRRL_REG 		*((volatile u8*)0X29)

#define		SREG_REG 		*((volatile u8*)0X5F)


#endif /* UART_REGISTER_H_ */

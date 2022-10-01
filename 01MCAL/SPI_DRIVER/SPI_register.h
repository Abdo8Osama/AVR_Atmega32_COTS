/*
 * 	FileName  : SPI_register.h
 *  Created on: 26/2/2020
 *  Author    : ABDULRAHMAN OSAMA 
 */

/****************GUARD MY FILE********************/

#ifndef SPI_REGISTER_H_
#define SPI_REGISTER_H_

#define		SPDR_REG 		*((volatile u8*)0X2F)
#define		SPSR_REG 		*((volatile u8*)0X2E)
#define		SPCR_REG 		*((volatile u8*)0X2D)

#define		SREG_REG 		*((volatile u8*)0X5F)

#endif /* SPI_REGISTER_H_ */

/*
 * 	FileName  : SPI_interface.h
 *  Created on: 26/2/2020
 *  Author    : ABDULRAHMAN OSAMA 
 */

/****************GUARD MY FILE********************/

#ifndef SPI_INT_H_
#define SPI_INT_H_

//SPI_PINS
#define	SS		4
#define	MOSI	5
#define	MISO	6
#define	CLK		7

//SPSR_REG
#define	SPI2X	0
#define	WCOL	6
#define	SPIF	7

//SPCR_REG
#define	SPR0	0
#define	SPR1	1
#define	CPHA	2
#define	CPOL	3
#define	MSTR	4
#define	DORD	5
#define	SPE		6
#define	SPIE	7

//SREG_REG
#define	GIE	7

//INTERRUPT_POLLING
#define	INTERRUPT	0
#define	POLLING		1

//DATA_ORDER
#define	MSB		0
#define	LSB		1

//MASTER_SLAVE
#define	SLAVE		0
#define	MASTER		1

//CLOCK_POLARITY
#define	RISING		0
#define	FALLING		1

//CLOCK_PHASE
#define	SAMPLE		0
#define	SETUP		1

//SCK_Frequency
#define	FOSCN4		0
#define	FOSCN16		1
#define	FOSCN64		2
#define	FOSCN128	3
#define	FOSCD2		4
#define	FOSCD8		5
#define	FOSCD32		6
#define	FOSCD64		7


/****************SPI FUNCTIONS *********************/
void SPI_INIT(u8 MASTER_SLAVE ,u8 SCK_Frequency ,u8 CLOCK_POLARITY ,u8 CLOCK_PHASE ,u8 DATA_ORDER ,u8 INTERRUPT_POLLING );
void SPI_MasterInit(void);
void SPI_MasterTransmit(u8 cData);
void SPI_SlaveInit(void);
u8 SPI_SlaveReceive(void);
void CALLback_SPI (void (* ptr) (void));

#endif /* SPI_INT_H_ */

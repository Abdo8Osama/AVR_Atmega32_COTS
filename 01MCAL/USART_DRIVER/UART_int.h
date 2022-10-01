/*
 * 	FileName  : UART_interface.h
 *  Created on: 25/2/2020
 *  Author    : ABDULRAHMAN OSAMA 
 */

#ifndef UART_INTERFCE_H_
#define UART_INTERFCE_H_


//UCSRA_REG
#define	RXC 7
#define	TXC 6
#define	UDRE 5
#define	FE 4
#define	DOR 3
#define	PE 72
#define	U2X 1
#define	MPCM 0

//UCSRB_REG
#define	RXCIE 7
#define	TXCIE 6
#define	UDRIE 5
#define	RXEN  4
#define	TXEN  3
#define	UCSZ2 2
#define	RXB8  1
#define	TXB8  0

//UCSRC_REG
#define	URSEL  7
#define	UMSEL  6
#define	UPM1   5
#define	UPM0   4
#define	USBS   3
#define	UCSZ1  2
#define	UCSZ0  1
#define	UCPOL  0

//SREG
#define	GIE  7

//MODES
#define	ASYNC_NORMAL 		0
#define	ASYNC_DSPEED  		1
#define	SYNCHRONUS    		2
#define	MULTI_PROCESSOR     3

//INTERRUPY_POLLING
#define	INTERRUPT 		0
#define	POLLING  		1

//CHARACTER SIZE
#define	FIVE_BITS 		0
#define	SIX_BITS  		1
#define	SEVEN_BITS 		2
#define	EIGHT_BITS  	3
#define	NINE_BITS 		4

//PARITY CHECK
#define	NO_PARITY 		0
#define	EVEN_PARITY  	1
#define	ODD_PARITY 		2

//STOP BITS
#define	ONE_BIT 		0
#define	TWO_BITS  		1

//BAUD RATE
#define	BN2400 			207
#define	BN4800  		103
#define	BN9600 			51
#define	BN14400  		34
#define	BN19200 		25
#define	BN28800 		16
#define	BN38400  		12
#define	BN57600 		8
#define	BN76800  		6
#define	BN115200 		3
#define	BN230400 		1
#define	BN250000  		1
#define	BN500000 		0

#define	BD2400 			416
#define	BD4800  		207
#define	BD9600 			103
#define	BD14400  		68
#define	BD19200 		51
#define	BD28800 		34
#define	BD38400  		25
#define	BD57600 		16
#define	BD76800  		12
#define	BD115200 		8
#define	BD230400 		3
#define	BD250000  		3
#define	BD500000 		1
#define	BD1M			0

/******************************UART FUNCTION *****************/
void USART_Init(u16 baud ,u8 mode , u8 data_size , u8 parity_check ,u8 stop_bits ,u8 interrupt_polling );
void USART_Init8( u16 baud );

void USART_Transmit_String8( u8 * u8ptr_copy );
void USART_Transmit8( u8 data );
void USART_Transmit9( u16 data );

u8 USART_Receive8( void );
u8 USART_Receive9( void );

void CALLback_URXC (void (* ptr) (void));
void CALLback_UDRE (void (* ptr) (void));
void CALLback_UTXC (void (* ptr) (void));

void URXC_INT_Disable (void );
void UDRE_INT_Disable (void );
void UTXC_INT_Disable (void );

void URXC_Flag_Clear(void);
void UTXC_Flag_Clear(void);
void UDRE_Flag_Clear(void);

u8 URXC_Flag_Read(void);
u8 UTXC_Flag_Read(void);
u8 UDRE_Flag_Read(void);


#endif /* UART_REGISTER_H_ */

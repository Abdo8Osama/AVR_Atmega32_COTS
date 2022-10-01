/****************GUARD MY FILE********************/
#ifndef _SEG_INTERFACE_H
#define _SEG_INTERFACE_H

/****************PORTS DEFINITIONS****************/
#define	PORTA	0
#define	PORTB	1
#define	PORTC	2
#define	PORTD	3	

/***************PINS DEFINITIONS******************/
#define	PIN0	0
#define	PIN1	1
#define	PIN2	2
#define	PIN3	3	
#define	PIN4	4
#define	PIN5	5
#define	PIN6	6
#define	PIN7	7

/****************DIRECTION DEFINITIONS*************/
#define	PORT_OUT	0xff
#define	PORT_IN		0x00 
#define	OUT			1
#define	IN			0 

/****************VALUES DEFINITIONS*************/
#define	ZERO		0x3F
#define	ONE			0x06 
#define	TWO			0x5B
#define	THREE		0x4F	 
#define	FOUR		0x66	 
#define	FIVE		0x6D	 
#define	SIX			0xFD 
#define	SEVEN		0x07	 
#define	EIGHT		0x7F	 
#define	NINE		0x6F	 


/***************************************************/
/* common kathode */
#define CK 1
/* common Anode */
#define CA	0


/****************PIN FUNCTIONS *********************/

void  SEG7_DISPLAY(u8 seg_type ,u8 port , u8 digit);



#endif
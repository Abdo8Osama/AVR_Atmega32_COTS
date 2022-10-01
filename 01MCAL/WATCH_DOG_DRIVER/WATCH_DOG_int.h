/*
 * 	FileName  : WDT_interface.h
 *  Created on: 18/2/2020
 *  Author    : ABDULRAHMAN OSAMA 
 */

/****************GUARD MY FILE********************/
#ifndef WDT_INTERFACE_H
#define WDT_INTERFACE_H


#define	WDTCR_REG  	*((volatile u8*)0X41)
#define	WDP0  	0
#define	WDP1  	1
#define	WDP2  	2
#define	WDE  	3
#define	WDTOE  	4

#define	V5	5
#define	V3	3
/****************INTERRUPT FUNCTIONS *********************/
void WDT_ENABLE();
void WDT_DISABLE();
void WDT_REFRESH();
void WDT_SET_PRESCALAR(s8 VOLTAGE ,s16 TIME_OUT_ms);


#endif



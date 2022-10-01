/*
 * 	FileName  : ADC_int.h
 *  Created on: 11/2/2020 
 *  Author    : ABDULRAHMAN OSAMA 
 */

/****************GUARD MY FILE********************/
#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H


#define REFS1  	7
#define REFS0  	6
#define ADLAR   5
#define MUX4   	4
#define MUX3  	3
#define MUX2  	2
#define MUX1  	1
#define MUX0  	0


#define ADEN  	7
#define ADSC  	6
#define ADATE   5
#define ADIF   	4
#define ADIE  	3
#define ADPS2  	2
#define ADPS1  	1
#define ADPS0  	0

#define ADC7  	7
#define ADC6  	6
#define ADC5    5
#define ADC4   	4
#define ADC3  	3
#define ADC2  	2
#define ADC1  	1
#define ADC0  	0

#define POLLING  	0
#define INTERRUPT  	1

#define AREF		0
#define AVCC  		1
#define INTERNAL  	2

#define R_ADJ  		0
#define L_ADJ  		1

#define SINGLE  	0
#define AUTO		1

#define GIE_PIN		7		//SREG_REG

/****************INTERRUPT FUNCTIONS *********************/

void ADC_SingleEnded_void_initialize(u8 ADC_u8_PIN , u8 AREF_AVCC_INTERNAL ,u8 INTERRUPT_POLLING ,u8 RIGHT_LEFT_ADJUSTMENT , u8 singleConv_AutoT );
u32 ADC_Get_Value(void);
void ADIF_Flag_Clear(void);
void ADC_StartConversion(void);
u8 ADIF_Flag_Read(void);
void CALLback_ADC (void (* ptr) (void));
void ADC_INT_Disable (void );




#endif



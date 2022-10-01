
/*******************************************************/
/* AUTHOR 	: ABDULRAHMAN OSAMA MOHAMED                */
/* DEC		: USART DRIVER                          	   */
/* DATE		: 25/2/2020                                */
/*******************************************************/

#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"UART_register.h"
#include"UART_int.h"

/******************************UART FUNCTION *****************/
/**********************************************************************/
void USART_Init8( u16 baud )
{

	/* Set baud rate */
	UBRRH_REG = (u8 )(baud>>8);
	UBRRL_REG = (u8 )baud;
	/* Enable receiver and transmitter */
	UCSRB_REG = (1<<RXEN)|(1<<TXEN);
	/* Set frame format: 8data, 1stop bit */
	UCSRC_REG = (1<<URSEL)|(3<<UCSZ0);
}


void USART_Init(u16 baud ,u8 mode , u8 data_size , u8 parity_check ,u8 stop_bits ,u8 interrupt_polling )
{
	/* Set baud rate */
	UBRRH_REG = (u8)(baud>>8);
	UBRRL_REG = (u8 )baud;
	CLR(UCSRA_REG , PE);
	CLR(UCSRA_REG , DOR);
	CLR(UCSRA_REG , FE);
	/* Enable receiver and transmitter */
	SET(UCSRB_REG , RXEN);
	SET(UCSRB_REG , TXEN);

	if(interrupt_polling == INTERRUPT)
	{
		SET(UCSRB_REG , UDRIE);
		SET(UCSRB_REG , TXCIE);
		SET(UCSRB_REG , RXCIE);
		SET(SREG_REG , GIE);

	}
	else if(interrupt_polling == POLLING)
	{
		CLR(UCSRB_REG , UDRIE);
		CLR(UCSRB_REG , TXCIE);
		CLR(UCSRB_REG , RXCIE);

	}

	/* Set frame format: 8data, 2stop bit */
	/**************************************************************/
	if((mode == ASYNC_NORMAL )&&(parity_check == NO_PARITY)&&(stop_bits == ONE_BIT)&&(data_size == FIVE_BITS))
	{
		UCSRC_REG = (1<<URSEL);
		CLR(UCSRA_REG , U2X);
	}
	else if((mode == ASYNC_DSPEED )&&(parity_check == NO_PARITY)&&(stop_bits == ONE_BIT)&&(data_size == FIVE_BITS))
	{
		UCSRC_REG = (1<<URSEL);
		SET(UCSRA_REG , U2X);
	}
	else if((mode == SYNCHRONUS )&&(parity_check == NO_PARITY)&&(stop_bits == ONE_BIT)&&(data_size == FIVE_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<UMSEL);
	}
	else if((mode == MULTI_PROCESSOR )&&(parity_check == NO_PARITY)&&(stop_bits == ONE_BIT)&&(data_size == FIVE_BITS))
	{
		UCSRC_REG = (1<<URSEL);
		SET(UCSRA_REG , MPCM);
	}
	/**************************************************************/
	else if((mode == ASYNC_NORMAL )&&(parity_check == EVEN_PARITY)&&(stop_bits == ONE_BIT)&&(data_size == FIVE_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<UPM1);
		CLR(UCSRA_REG , U2X);
	}
	else if((mode == ASYNC_DSPEED )&&(parity_check == EVEN_PARITY)&&(stop_bits == ONE_BIT)&&(data_size == FIVE_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<UPM1);
		SET(UCSRA_REG , U2X);
	}
	else if((mode == SYNCHRONUS )&&(parity_check == EVEN_PARITY)&&(stop_bits == ONE_BIT)&&(data_size == FIVE_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<UMSEL)|(1<<UPM1);
	}
	else if((mode == MULTI_PROCESSOR )&&(parity_check == EVEN_PARITY)&&(stop_bits == ONE_BIT)&&(data_size == FIVE_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<UPM1);
		SET(UCSRA_REG , MPCM);
	}
	/**************************************************************/
	else if((mode == ASYNC_NORMAL )&&(parity_check == ODD_PARITY)&&(stop_bits == ONE_BIT)&&(data_size == FIVE_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<UPM1)|(1<<UPM0);
		CLR(UCSRA_REG , U2X);
	}
	else if((mode == ASYNC_DSPEED )&&(parity_check == EVEN_PARITY)&&(stop_bits == ONE_BIT)&&(data_size == FIVE_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<UPM1)|(1<<UPM0);
		SET(UCSRA_REG , U2X);
	}
	else if((mode == SYNCHRONUS )&&(parity_check == EVEN_PARITY)&&(stop_bits == ONE_BIT)&&(data_size == FIVE_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<UMSEL)|(1<<UPM1)|(1<<UPM0);
	}
	else if((mode == MULTI_PROCESSOR )&&(parity_check == EVEN_PARITY)&&(stop_bits == ONE_BIT)&&(data_size == FIVE_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<UPM1)|(1<<UPM0);
		SET(UCSRA_REG , MPCM);
	}
	/**************************************************************/

	else if((mode == ASYNC_NORMAL )&&(parity_check == NO_PARITY)&&(stop_bits == TWO_BITS)&&(data_size == FIVE_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<USBS);
		CLR(UCSRA_REG , U2X);
	}
	else if((mode == ASYNC_DSPEED )&&(parity_check == NO_PARITY)&&(stop_bits == TWO_BITS)&&(data_size == FIVE_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<USBS);
		SET(UCSRA_REG , U2X);
	}
	else if((mode == SYNCHRONUS )&&(parity_check == NO_PARITY)&&(stop_bits == TWO_BITS)&&(data_size == FIVE_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<UMSEL)|(1<<USBS);
	}
	else if((mode == MULTI_PROCESSOR )&&(parity_check == NO_PARITY)&&(stop_bits == TWO_BITS)&&(data_size == FIVE_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<USBS);
		SET(UCSRA_REG , MPCM);
	}
	/**************************************************************/
	else if((mode == ASYNC_NORMAL )&&(parity_check == EVEN_PARITY)&&(stop_bits == TWO_BITS)&&(data_size == FIVE_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<UPM1)|(1<<USBS);
		CLR(UCSRA_REG , U2X);
	}
	else if((mode == ASYNC_DSPEED )&&(parity_check == EVEN_PARITY)&&(stop_bits == TWO_BITS)&&(data_size == FIVE_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<UPM1)|(1<<USBS);
		SET(UCSRA_REG , U2X);
	}
	else if((mode == SYNCHRONUS )&&(parity_check == EVEN_PARITY)&&(stop_bits == TWO_BITS)&&(data_size == FIVE_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<UMSEL)|(1<<UPM1)|(1<<USBS);
	}
	else if((mode == MULTI_PROCESSOR )&&(parity_check == EVEN_PARITY)&&(stop_bits == TWO_BITS)&&(data_size == FIVE_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<UPM1)|(1<<USBS);
		SET(UCSRA_REG , MPCM);
	}
	/**************************************************************/
	else if((mode == ASYNC_NORMAL )&&(parity_check == ODD_PARITY)&&(stop_bits == TWO_BITS)&&(data_size == FIVE_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<UPM1)|(1<<UPM0)|(1<<USBS);
		CLR(UCSRA_REG , U2X);
	}
	else if((mode == ASYNC_DSPEED )&&(parity_check == EVEN_PARITY)&&(stop_bits == TWO_BITS)&&(data_size == FIVE_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<UPM1)|(1<<UPM0)|(1<<USBS);
		SET(UCSRA_REG , U2X);
	}
	else if((mode == SYNCHRONUS )&&(parity_check == EVEN_PARITY)&&(stop_bits == TWO_BITS)&&(data_size == FIVE_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<UMSEL)|(1<<UPM1)|(1<<UPM0)|(1<<USBS);
	}
	else if((mode == MULTI_PROCESSOR )&&(parity_check == EVEN_PARITY)&&(stop_bits == TWO_BITS)&&(data_size == FIVE_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<UPM1)|(1<<UPM0)|(1<<USBS);
		SET(UCSRA_REG , MPCM);
	}
	/**************************************************************/
	else if((mode == ASYNC_NORMAL )&&(parity_check == NO_PARITY)&&(stop_bits == ONE_BIT)&&(data_size == SIX_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<UCSZ0);
		CLR(UCSRA_REG , U2X);
	}
	else if((mode == ASYNC_DSPEED )&&(parity_check == NO_PARITY)&&(stop_bits == ONE_BIT)&&(data_size == SIX_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<UCSZ0);
		SET(UCSRA_REG , U2X);
	}
	else if((mode == SYNCHRONUS )&&(parity_check == NO_PARITY)&&(stop_bits == ONE_BIT)&&(data_size == SIX_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<UMSEL)|(1<<UCSZ0);
	}
	else if((mode == MULTI_PROCESSOR )&&(parity_check == NO_PARITY)&&(stop_bits == ONE_BIT)&&(data_size == SIX_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<UCSZ0);
		SET(UCSRA_REG , MPCM);
	}
	/**************************************************************/
	else if((mode == ASYNC_NORMAL )&&(parity_check == EVEN_PARITY)&&(stop_bits == ONE_BIT)&&(data_size == SIX_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<UPM1)|(1<<UCSZ0);
		CLR(UCSRA_REG , U2X);
	}
	else if((mode == ASYNC_DSPEED )&&(parity_check == EVEN_PARITY)&&(stop_bits == ONE_BIT)&&(data_size == SIX_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<UPM1)|(1<<UCSZ0);
		SET(UCSRA_REG , U2X);
	}
	else if((mode == SYNCHRONUS )&&(parity_check == EVEN_PARITY)&&(stop_bits == ONE_BIT)&&(data_size == SIX_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<UMSEL)|(1<<UPM1)|(1<<UCSZ0);
	}
	else if((mode == MULTI_PROCESSOR )&&(parity_check == EVEN_PARITY)&&(stop_bits == ONE_BIT)&&(data_size == SIX_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<UPM1)|(1<<UCSZ0);
		SET(UCSRA_REG , MPCM);
	}
	/**************************************************************/
	else if((mode == ASYNC_NORMAL )&&(parity_check == ODD_PARITY)&&(stop_bits == ONE_BIT)&&(data_size == SIX_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<UPM1)|(1<<UPM0)|(1<<UCSZ0);
		CLR(UCSRA_REG , U2X);
	}
	else if((mode == ASYNC_DSPEED )&&(parity_check == EVEN_PARITY)&&(stop_bits == ONE_BIT)&&(data_size == SIX_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<UPM1)|(1<<UPM0)|(1<<UCSZ0);
		SET(UCSRA_REG , U2X);
	}
	else if((mode == SYNCHRONUS )&&(parity_check == EVEN_PARITY)&&(stop_bits == ONE_BIT)&&(data_size == SIX_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<UMSEL)|(1<<UPM1)|(1<<UPM0)|(1<<UCSZ0);
	}
	else if((mode == MULTI_PROCESSOR )&&(parity_check == EVEN_PARITY)&&(stop_bits == ONE_BIT)&&(data_size == SIX_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<UPM1)|(1<<UPM0)|(1<<UCSZ0);
		SET(UCSRA_REG , MPCM);
	}
	/**************************************************************/

	else if((mode == ASYNC_NORMAL )&&(parity_check == NO_PARITY)&&(stop_bits == TWO_BITS)&&(data_size == SIX_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<USBS)|(1<<UCSZ0);
		CLR(UCSRA_REG , U2X);
	}
	else if((mode == ASYNC_DSPEED )&&(parity_check == NO_PARITY)&&(stop_bits == TWO_BITS)&&(data_size == SIX_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<USBS)|(1<<UCSZ0);
		SET(UCSRA_REG , U2X);
	}
	else if((mode == SYNCHRONUS )&&(parity_check == NO_PARITY)&&(stop_bits == TWO_BITS)&&(data_size == SIX_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<UMSEL)|(1<<USBS)|(1<<UCSZ0);
	}
	else if((mode == MULTI_PROCESSOR )&&(parity_check == NO_PARITY)&&(stop_bits == TWO_BITS)&&(data_size == SIX_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<USBS)|(1<<UCSZ0);
		SET(UCSRA_REG , MPCM);
	}
	/**************************************************************/
	else if((mode == ASYNC_NORMAL )&&(parity_check == EVEN_PARITY)&&(stop_bits == TWO_BITS)&&(data_size == SIX_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<UPM1)|(1<<USBS)|(1<<UCSZ0);
		CLR(UCSRA_REG , U2X);
	}
	else if((mode == ASYNC_DSPEED )&&(parity_check == EVEN_PARITY)&&(stop_bits == TWO_BITS)&&(data_size == SIX_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<UPM1)|(1<<USBS)|(1<<UCSZ0);
		SET(UCSRA_REG , U2X);
	}
	else if((mode == SYNCHRONUS )&&(parity_check == EVEN_PARITY)&&(stop_bits == TWO_BITS)&&(data_size == SIX_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<UMSEL)|(1<<UPM1)|(1<<USBS)|(1<<UCSZ0);
	}
	else if((mode == MULTI_PROCESSOR )&&(parity_check == EVEN_PARITY)&&(stop_bits == TWO_BITS)&&(data_size == SIX_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<UPM1)|(1<<USBS)|(1<<UCSZ0);
		SET(UCSRA_REG , MPCM);
	}
	/**************************************************************/
	else if((mode == ASYNC_NORMAL )&&(parity_check == ODD_PARITY)&&(stop_bits == TWO_BITS)&&(data_size == SIX_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<UPM1)|(1<<UPM0)|(1<<USBS)|(1<<UCSZ0);
		CLR(UCSRA_REG , U2X);
	}
	else if((mode == ASYNC_DSPEED )&&(parity_check == EVEN_PARITY)&&(stop_bits == TWO_BITS)&&(data_size == SIX_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<UPM1)|(1<<UPM0)|(1<<USBS)|(1<<UCSZ0);
		SET(UCSRA_REG , U2X);
	}
	else if((mode == SYNCHRONUS )&&(parity_check == EVEN_PARITY)&&(stop_bits == TWO_BITS)&&(data_size == SIX_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<UMSEL)|(1<<UPM1)|(1<<UPM0)|(1<<USBS)|(1<<UCSZ0);
	}
	else if((mode == MULTI_PROCESSOR )&&(parity_check == EVEN_PARITY)&&(stop_bits == TWO_BITS)&&(data_size == SIX_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<UPM1)|(1<<UPM0)|(1<<USBS)|(1<<UCSZ0);
		SET(UCSRA_REG , MPCM);
	}
	/**************************************************************/
	else if((mode == ASYNC_NORMAL )&&(parity_check == NO_PARITY)&&(stop_bits == ONE_BIT)&&(data_size == SEVEN_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<UCSZ1);
		CLR(UCSRA_REG , U2X);
	}
	else if((mode == ASYNC_DSPEED )&&(parity_check == NO_PARITY)&&(stop_bits == ONE_BIT)&&(data_size == SEVEN_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<UCSZ1);
		SET(UCSRA_REG , U2X);
	}
	else if((mode == SYNCHRONUS )&&(parity_check == NO_PARITY)&&(stop_bits == ONE_BIT)&&(data_size == SEVEN_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<UMSEL)|(1<<UCSZ1);
	}
	else if((mode == MULTI_PROCESSOR )&&(parity_check == NO_PARITY)&&(stop_bits == ONE_BIT)&&(data_size == SEVEN_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<UCSZ1);
		SET(UCSRA_REG , MPCM);
	}
	/**************************************************************/
	else if((mode == ASYNC_NORMAL )&&(parity_check == EVEN_PARITY)&&(stop_bits == ONE_BIT)&&(data_size == SEVEN_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<UPM1)|(1<<UCSZ1);
		CLR(UCSRA_REG , U2X);
	}
	else if((mode == ASYNC_DSPEED )&&(parity_check == EVEN_PARITY)&&(stop_bits == ONE_BIT)&&(data_size == SEVEN_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<UPM1)|(1<<UCSZ1);
		SET(UCSRA_REG , U2X);
	}
	else if((mode == SYNCHRONUS )&&(parity_check == EVEN_PARITY)&&(stop_bits == ONE_BIT)&&(data_size == SEVEN_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<UMSEL)|(1<<UPM1)|(1<<UCSZ1);
	}
	else if((mode == MULTI_PROCESSOR )&&(parity_check == EVEN_PARITY)&&(stop_bits == ONE_BIT)&&(data_size == SEVEN_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<UPM1)|(1<<UCSZ1);
		SET(UCSRA_REG , MPCM);
	}
	/**************************************************************/
	else if((mode == ASYNC_NORMAL )&&(parity_check == ODD_PARITY)&&(stop_bits == ONE_BIT)&&(data_size == SEVEN_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<UPM1)|(1<<UPM0)|(1<<UCSZ1);
		CLR(UCSRA_REG , U2X);
	}
	else if((mode == ASYNC_DSPEED )&&(parity_check == EVEN_PARITY)&&(stop_bits == ONE_BIT)&&(data_size == SEVEN_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<UPM1)|(1<<UPM0)|(1<<UCSZ1);
		SET(UCSRA_REG , U2X);
	}
	else if((mode == SYNCHRONUS )&&(parity_check == EVEN_PARITY)&&(stop_bits == ONE_BIT)&&(data_size == SEVEN_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<UMSEL)|(1<<UPM1)|(1<<UPM0)|(1<<UCSZ1);
	}
	else if((mode == MULTI_PROCESSOR )&&(parity_check == EVEN_PARITY)&&(stop_bits == ONE_BIT)&&(data_size == SEVEN_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<UPM1)|(1<<UPM0)|(1<<UCSZ1);
		SET(UCSRA_REG , MPCM);
	}
	/**************************************************************/

	else if((mode == ASYNC_NORMAL )&&(parity_check == NO_PARITY)&&(stop_bits == TWO_BITS)&&(data_size == SEVEN_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<USBS)|(1<<UCSZ1);
		CLR(UCSRA_REG , U2X);
	}
	else if((mode == ASYNC_DSPEED )&&(parity_check == NO_PARITY)&&(stop_bits == TWO_BITS)&&(data_size == SEVEN_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<USBS)|(1<<UCSZ1);
		SET(UCSRA_REG , U2X);
	}
	else if((mode == SYNCHRONUS )&&(parity_check == NO_PARITY)&&(stop_bits == TWO_BITS)&&(data_size == SEVEN_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<UMSEL)|(1<<USBS)|(1<<UCSZ1);
	}
	else if((mode == MULTI_PROCESSOR )&&(parity_check == NO_PARITY)&&(stop_bits == TWO_BITS)&&(data_size == SEVEN_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<USBS)|(1<<UCSZ1);
		SET(UCSRA_REG , MPCM);
	}
	/**************************************************************/
	else if((mode == ASYNC_NORMAL )&&(parity_check == EVEN_PARITY)&&(stop_bits == TWO_BITS)&&(data_size == SEVEN_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<UPM1)|(1<<USBS)|(1<<UCSZ1);
		CLR(UCSRA_REG , U2X);
	}
	else if((mode == ASYNC_DSPEED )&&(parity_check == EVEN_PARITY)&&(stop_bits == TWO_BITS)&&(data_size == SEVEN_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<UPM1)|(1<<USBS)|(1<<UCSZ1);
		SET(UCSRA_REG , U2X);
	}
	else if((mode == SYNCHRONUS )&&(parity_check == EVEN_PARITY)&&(stop_bits == TWO_BITS)&&(data_size == SEVEN_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<UMSEL)|(1<<UPM1)|(1<<USBS)|(1<<UCSZ1);
	}
	else if((mode == MULTI_PROCESSOR )&&(parity_check == EVEN_PARITY)&&(stop_bits == TWO_BITS)&&(data_size == SEVEN_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<UPM1)|(1<<USBS)|(1<<UCSZ1);
		SET(UCSRA_REG , MPCM);
	}
	/**************************************************************/
	else if((mode == ASYNC_NORMAL )&&(parity_check == ODD_PARITY)&&(stop_bits == TWO_BITS)&&(data_size == SEVEN_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<UPM1)|(1<<UPM0)|(1<<USBS)|(1<<UCSZ1);
		CLR(UCSRA_REG , U2X);
	}
	else if((mode == ASYNC_DSPEED )&&(parity_check == EVEN_PARITY)&&(stop_bits == TWO_BITS)&&(data_size == SEVEN_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<UPM1)|(1<<UPM0)|(1<<USBS)|(1<<UCSZ1);
		SET(UCSRA_REG , U2X);
	}
	else if((mode == SYNCHRONUS )&&(parity_check == EVEN_PARITY)&&(stop_bits == TWO_BITS)&&(data_size == SEVEN_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<UMSEL)|(1<<UPM1)|(1<<UPM0)|(1<<USBS)|(1<<UCSZ1);
	}
	else if((mode == MULTI_PROCESSOR )&&(parity_check == EVEN_PARITY)&&(stop_bits == TWO_BITS)&&(data_size == SEVEN_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<UPM1)|(1<<UPM0)|(1<<USBS)|(1<<UCSZ1);
		SET(UCSRA_REG , MPCM);
	}

	/**********************************************************************/
	/**************************************************************/
	else if((mode == ASYNC_NORMAL )&&(parity_check == NO_PARITY)&&(stop_bits == ONE_BIT)&&(data_size == EIGHT_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(3<<UCSZ0);
		CLR(UCSRA_REG , U2X);
	}
	else if((mode == ASYNC_DSPEED )&&(parity_check == NO_PARITY)&&(stop_bits == ONE_BIT)&&(data_size == EIGHT_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(3<<UCSZ0);
		SET(UCSRA_REG , U2X);
	}
	else if((mode == SYNCHRONUS )&&(parity_check == NO_PARITY)&&(stop_bits == ONE_BIT)&&(data_size == EIGHT_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<UMSEL)|(3<<UCSZ0);
	}
	else if((mode == MULTI_PROCESSOR )&&(parity_check == NO_PARITY)&&(stop_bits == ONE_BIT)&&(data_size == EIGHT_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(3<<UCSZ0);
		SET(UCSRA_REG , MPCM);
	}
	/**************************************************************/
	else if((mode == ASYNC_NORMAL )&&(parity_check == EVEN_PARITY)&&(stop_bits == ONE_BIT)&&(data_size == EIGHT_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<UPM1)|(3<<UCSZ0);
		CLR(UCSRA_REG , U2X);
	}
	else if((mode == ASYNC_DSPEED )&&(parity_check == EVEN_PARITY)&&(stop_bits == ONE_BIT)&&(data_size == EIGHT_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<UPM1)|(3<<UCSZ0);
		SET(UCSRA_REG , U2X);
	}
	else if((mode == SYNCHRONUS )&&(parity_check == EVEN_PARITY)&&(stop_bits == ONE_BIT)&&(data_size == EIGHT_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<UMSEL)|(1<<UPM1)|(3<<UCSZ0);
	}
	else if((mode == MULTI_PROCESSOR )&&(parity_check == EVEN_PARITY)&&(stop_bits == ONE_BIT)&&(data_size == EIGHT_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<UPM1)|(3<<UCSZ0);
		SET(UCSRA_REG , MPCM);
	}
	/**************************************************************/
	else if((mode == ASYNC_NORMAL )&&(parity_check == ODD_PARITY)&&(stop_bits == ONE_BIT)&&(data_size == EIGHT_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<UPM1)|(1<<UPM0)|(3<<UCSZ0);
		CLR(UCSRA_REG , U2X);
	}
	else if((mode == ASYNC_DSPEED )&&(parity_check == EVEN_PARITY)&&(stop_bits == ONE_BIT)&&(data_size == EIGHT_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<UPM1)|(1<<UPM0)|(3<<UCSZ0);
		SET(UCSRA_REG , U2X);
	}
	else if((mode == SYNCHRONUS )&&(parity_check == EVEN_PARITY)&&(stop_bits == ONE_BIT)&&(data_size == EIGHT_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<UMSEL)|(1<<UPM1)|(1<<UPM0)|(3<<UCSZ0);
	}
	else if((mode == MULTI_PROCESSOR )&&(parity_check == EVEN_PARITY)&&(stop_bits == ONE_BIT)&&(data_size == EIGHT_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<UPM1)|(1<<UPM0)|(3<<UCSZ0);
		SET(UCSRA_REG , MPCM);
	}
	/**************************************************************/

	else if((mode == ASYNC_NORMAL )&&(parity_check == NO_PARITY)&&(stop_bits == TWO_BITS)&&(data_size == EIGHT_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<USBS)|(3<<UCSZ0);
		CLR(UCSRA_REG , U2X);
	}
	else if((mode == ASYNC_DSPEED )&&(parity_check == NO_PARITY)&&(stop_bits == TWO_BITS)&&(data_size == EIGHT_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<USBS)|(3<<UCSZ0);
		SET(UCSRA_REG , U2X);
	}
	else if((mode == SYNCHRONUS )&&(parity_check == NO_PARITY)&&(stop_bits == TWO_BITS)&&(data_size == EIGHT_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<UMSEL)|(1<<USBS)|(3<<UCSZ0);
	}
	else if((mode == MULTI_PROCESSOR )&&(parity_check == NO_PARITY)&&(stop_bits == TWO_BITS)&&(data_size == EIGHT_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<USBS)|(3<<UCSZ0);
		SET(UCSRA_REG , MPCM);
	}
	/**************************************************************/
	else if((mode == ASYNC_NORMAL )&&(parity_check == EVEN_PARITY)&&(stop_bits == TWO_BITS)&&(data_size == EIGHT_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<UPM1)|(1<<USBS)|(3<<UCSZ0);
		CLR(UCSRA_REG , U2X);
	}
	else if((mode == ASYNC_DSPEED )&&(parity_check == EVEN_PARITY)&&(stop_bits == TWO_BITS)&&(data_size == EIGHT_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<UPM1)|(1<<USBS)|(3<<UCSZ0);
		SET(UCSRA_REG , U2X);
	}
	else if((mode == SYNCHRONUS )&&(parity_check == EVEN_PARITY)&&(stop_bits == TWO_BITS)&&(data_size == EIGHT_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<UMSEL)|(1<<UPM1)|(1<<USBS)|(3<<UCSZ0);
	}
	else if((mode == MULTI_PROCESSOR )&&(parity_check == EVEN_PARITY)&&(stop_bits == TWO_BITS)&&(data_size == EIGHT_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<UPM1)|(1<<USBS)|(3<<UCSZ0);
		SET(UCSRA_REG , MPCM);
	}
	/**************************************************************/
	else if((mode == ASYNC_NORMAL )&&(parity_check == ODD_PARITY)&&(stop_bits == TWO_BITS)&&(data_size == EIGHT_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<UPM1)|(1<<UPM0)|(1<<USBS)|(3<<UCSZ0);
		CLR(UCSRA_REG , U2X);
	}
	else if((mode == ASYNC_DSPEED )&&(parity_check == EVEN_PARITY)&&(stop_bits == TWO_BITS)&&(data_size == EIGHT_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<UPM1)|(1<<UPM0)|(1<<USBS)|(3<<UCSZ0);
		SET(UCSRA_REG , U2X);
	}
	else if((mode == SYNCHRONUS )&&(parity_check == EVEN_PARITY)&&(stop_bits == TWO_BITS)&&(data_size == EIGHT_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<UMSEL)|(1<<UPM1)|(1<<UPM0)|(1<<USBS)|(3<<UCSZ0);
	}
	else if((mode == MULTI_PROCESSOR )&&(parity_check == EVEN_PARITY)&&(stop_bits == TWO_BITS)&&(data_size == EIGHT_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<UPM1)|(1<<UPM0)|(1<<USBS)|(3<<UCSZ0);
		SET(UCSRA_REG , MPCM);
	}

	/**********************************************************************/
	/**************************************************************/
	else if((mode == ASYNC_NORMAL )&&(parity_check == NO_PARITY)&&(stop_bits == ONE_BIT)&&(data_size == NINE_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(3<<UCSZ0);
		CLR(UCSRA_REG , U2X);
		SET(UCSRB_REG , UCSZ2);
	}
	else if((mode == ASYNC_DSPEED )&&(parity_check == NO_PARITY)&&(stop_bits == ONE_BIT)&&(data_size == NINE_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(3<<UCSZ0);
		SET(UCSRA_REG , U2X);
		SET(UCSRB_REG , UCSZ2);
	}
	else if((mode == SYNCHRONUS )&&(parity_check == NO_PARITY)&&(stop_bits == ONE_BIT)&&(data_size == NINE_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<UMSEL)|(3<<UCSZ0);
		SET(UCSRB_REG , UCSZ2);
	}
	else if((mode == MULTI_PROCESSOR )&&(parity_check == NO_PARITY)&&(stop_bits == ONE_BIT)&&(data_size == NINE_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(3<<UCSZ0);
		SET(UCSRA_REG , MPCM);
		SET(UCSRB_REG , UCSZ2);
	}
	/**************************************************************/
	else if((mode == ASYNC_NORMAL )&&(parity_check == EVEN_PARITY)&&(stop_bits == ONE_BIT)&&(data_size == NINE_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<UPM1)|(3<<UCSZ0);
		CLR(UCSRA_REG , U2X);
		SET(UCSRB_REG , UCSZ2);
	}
	else if((mode == ASYNC_DSPEED )&&(parity_check == EVEN_PARITY)&&(stop_bits == ONE_BIT)&&(data_size == NINE_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<UPM1)|(3<<UCSZ0);
		SET(UCSRA_REG , U2X);
		SET(UCSRB_REG , UCSZ2);
	}
	else if((mode == SYNCHRONUS )&&(parity_check == EVEN_PARITY)&&(stop_bits == ONE_BIT)&&(data_size == NINE_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<UMSEL)|(1<<UPM1)|(3<<UCSZ0);
		SET(UCSRB_REG , UCSZ2);
	}
	else if((mode == MULTI_PROCESSOR )&&(parity_check == EVEN_PARITY)&&(stop_bits == ONE_BIT)&&(data_size == NINE_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<UPM1)|(3<<UCSZ0);
		SET(UCSRA_REG , MPCM);
		SET(UCSRB_REG , UCSZ2);
	}
	/**************************************************************/
	else if((mode == ASYNC_NORMAL )&&(parity_check == ODD_PARITY)&&(stop_bits == ONE_BIT)&&(data_size == NINE_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<UPM1)|(1<<UPM0)|(3<<UCSZ0);
		CLR(UCSRA_REG , U2X);
		SET(UCSRB_REG , UCSZ2);
	}
	else if((mode == ASYNC_DSPEED )&&(parity_check == EVEN_PARITY)&&(stop_bits == ONE_BIT)&&(data_size == NINE_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<UPM1)|(1<<UPM0)|(3<<UCSZ0);
		SET(UCSRA_REG , U2X);
		SET(UCSRB_REG , UCSZ2);
	}
	else if((mode == SYNCHRONUS )&&(parity_check == EVEN_PARITY)&&(stop_bits == ONE_BIT)&&(data_size == NINE_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<UMSEL)|(1<<UPM1)|(1<<UPM0)|(3<<UCSZ0);
		SET(UCSRB_REG , UCSZ2);
	}
	else if((mode == MULTI_PROCESSOR )&&(parity_check == EVEN_PARITY)&&(stop_bits == ONE_BIT)&&(data_size == NINE_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<UPM1)|(1<<UPM0)|(3<<UCSZ0);
		SET(UCSRA_REG , MPCM);
		SET(UCSRB_REG , UCSZ2);
	}
	/**************************************************************/

	else if((mode == ASYNC_NORMAL )&&(parity_check == NO_PARITY)&&(stop_bits == TWO_BITS)&&(data_size == NINE_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<USBS)|(3<<UCSZ0);
		CLR(UCSRA_REG , U2X);
		SET(UCSRB_REG , UCSZ2);
	}
	else if((mode == ASYNC_DSPEED )&&(parity_check == NO_PARITY)&&(stop_bits == TWO_BITS)&&(data_size == NINE_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<USBS)|(3<<UCSZ0);
		SET(UCSRA_REG , U2X);
		SET(UCSRB_REG , UCSZ2);
	}
	else if((mode == SYNCHRONUS )&&(parity_check == NO_PARITY)&&(stop_bits == TWO_BITS)&&(data_size == NINE_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<UMSEL)|(1<<USBS)|(3<<UCSZ0);
		SET(UCSRB_REG , UCSZ2);
	}
	else if((mode == MULTI_PROCESSOR )&&(parity_check == NO_PARITY)&&(stop_bits == TWO_BITS)&&(data_size == NINE_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<USBS)|(3<<UCSZ0);
		SET(UCSRA_REG , MPCM);
		SET(UCSRB_REG , UCSZ2);
	}
	/**************************************************************/
	else if((mode == ASYNC_NORMAL )&&(parity_check == EVEN_PARITY)&&(stop_bits == TWO_BITS)&&(data_size == NINE_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<UPM1)|(1<<USBS)|(3<<UCSZ0);
		CLR(UCSRA_REG , U2X);
		SET(UCSRB_REG , UCSZ2);
	}
	else if((mode == ASYNC_DSPEED )&&(parity_check == EVEN_PARITY)&&(stop_bits == TWO_BITS)&&(data_size == NINE_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<UPM1)|(1<<USBS)|(3<<UCSZ0);
		SET(UCSRA_REG , U2X);
		SET(UCSRB_REG , UCSZ2);
	}
	else if((mode == SYNCHRONUS )&&(parity_check == EVEN_PARITY)&&(stop_bits == TWO_BITS)&&(data_size == NINE_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<UMSEL)|(1<<UPM1)|(1<<USBS)|(3<<UCSZ0);
		SET(UCSRB_REG , UCSZ2);
	}
	else if((mode == MULTI_PROCESSOR )&&(parity_check == EVEN_PARITY)&&(stop_bits == TWO_BITS)&&(data_size == NINE_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<UPM1)|(1<<USBS)|(3<<UCSZ0);
		SET(UCSRA_REG , MPCM);
		SET(UCSRB_REG , UCSZ2);
	}
	/**************************************************************/
	else if((mode == ASYNC_NORMAL )&&(parity_check == ODD_PARITY)&&(stop_bits == TWO_BITS)&&(data_size == NINE_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<UPM1)|(1<<UPM0)|(1<<USBS)|(3<<UCSZ0);
		CLR(UCSRA_REG , U2X);
		SET(UCSRB_REG , UCSZ2);
	}
	else if((mode == ASYNC_DSPEED )&&(parity_check == EVEN_PARITY)&&(stop_bits == TWO_BITS)&&(data_size == NINE_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<UPM1)|(1<<UPM0)|(1<<USBS)|(3<<UCSZ0);
		SET(UCSRA_REG , U2X);
		SET(UCSRB_REG , UCSZ2);
	}
	else if((mode == SYNCHRONUS )&&(parity_check == EVEN_PARITY)&&(stop_bits == TWO_BITS)&&(data_size == NINE_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<UMSEL)|(1<<UPM1)|(1<<UPM0)|(1<<USBS)|(3<<UCSZ0);
		SET(UCSRB_REG , UCSZ2);
	}
	else if((mode == MULTI_PROCESSOR )&&(parity_check == EVEN_PARITY)&&(stop_bits == TWO_BITS)&&(data_size == NINE_BITS))
	{
		UCSRC_REG = (1<<URSEL)|(1<<UPM1)|(1<<UPM0)|(1<<USBS)|(3<<UCSZ0);
		SET(UCSRA_REG , MPCM);
		SET(UCSRB_REG , UCSZ2);
	}

	/**********************************************************************/

}
/**********************************************************************/
void USART_Transmit_String8( u8 * u8ptr_copy )
{
	u8 i=0;
	while(u8ptr_copy[i] != '\0')
	{
		USART_Transmit8(u8ptr_copy[i]);
		i++;
	}
}
void USART_Transmit8( u8 data )
{
	/* Wait for empty transmit buffer */
	while ( !( UCSRA_REG & (1<<UDRE)) );
	/* Put data into buffer, sends the data */
	UDR_REG = data;
}

void USART_Transmit9( u16 data )
{

	/* Wait for empty transmit buffer */
	while ( !( UCSRA_REG & (1<<UDRE))) ;
	/* Copy 9th bit to TXB8 */
	UCSRB_REG &= ~(1<<TXB8);
	if ( data & 0x0100 )
		UCSRB_REG |= (1<<TXB8);
	/* Put data into buffer, sends the data */
	UDR_REG = data;
}
/**********************************************************************/

u8 USART_Receive8( void )
{

	/* Wait for data to be received */
	while ( !(UCSRA_REG & (1<<RXC)) )
		;
	/* Get and return received data from buffer */
	return UDR_REG;
}

u8 USART_Receive9( void )
{

	u8 status, resh, resl;
	/* Wait for data to be received */
	while ( !(UCSRA_REG & (1<<RXC)) );
	/* Get status and 9th bit, then data */
	/* from buffer */
	status = UCSRA_REG;
	resh = UCSRB_REG;
	resl = UDR_REG;
	/* If error, return -1 */
	if ( status & (1<<FE)|(1<<DOR)|(1<<PE) )
		return -1;
	/* Filter the 9th bit, then return */
	resh = (resh >> 1) & 0x01;
	return ((resh << 8) | resl);
}

/**********************************************************************/

void (* PF_URXC) (void);
void (* PF_UDRE) (void);
void (* PF_UTXC) (void);

void __vector_13 (void) __attribute__ ((signal , used));

void __vector_13 (void)
{
	PF_URXC();
}

void __vector_14 (void) __attribute__ ((signal , used));

void __vector_14 (void)
{
	PF_UDRE();
}

void __vector_15 (void) __attribute__ ((signal , used));

void __vector_15 (void)
{
	PF_UTXC();
}

/**********************************************************************/

void CALLback_URXC (void (* ptr) (void))
{
	PF_URXC = (void (*) (void))ptr ;
}


void CALLback_UDRE (void (* ptr) (void))
{
	PF_UDRE = (void (*) (void))ptr ;
}

void CALLback_UTXC (void (* ptr) (void))
{
	PF_UTXC = (void (*) (void))ptr ;
}

/**********************************************************************/

void URXC_INT_Disable (void )
{
	CLR(UCSRB_REG , RXCIE);
}

/**********************************************************************/

void UDRE_INT_Disable (void )
{
	CLR(UCSRB_REG , UDRIE);
}

/**********************************************************************/

void UTXC_INT_Disable (void )
{
	CLR(UCSRB_REG , TXCIE);
}

/**********************************************************************/

void URXC_Flag_Clear(void)
{
	SET(UCSRA_REG , RXC);
}
/**********************************************************************/

void UTXC_Flag_Clear(void)
{
	SET(UCSRA_REG , TXC);
}

/**********************************************************************/

void UDRE_Flag_Clear(void)
{
	SET(UCSRA_REG , UDRE);
}

/**********************************************************************/

u8 URXC_Flag_Read(void)
{
	u8 read ;
	read = GET(UCSRA_REG , RXC);
	return read;
}

/**********************************************************************/

u8 UTXC_Flag_Read(void)
{
	u8 read ;
	read = GET(UCSRA_REG , TXC);
	return read;
}
/**********************************************************************/

u8 UDRE_Flag_Read(void)
{
	u8 read ;
	read = GET(UCSRA_REG , UDRE);
	return read;
}

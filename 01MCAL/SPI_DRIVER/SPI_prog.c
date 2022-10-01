
/*******************************************************/
/* AUTHOR 	: ABDULRAHMAN OSAMA MOHAMED                */
/* DEC		: SPI DRIVER                               */
/* DATE		: 26/2/2020                                */
/*******************************************************/

#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"DIO_interface.h"
#include"SPI_int.h"
#include"SPI_register.h"

/****************SPI FUNCTIONS ****************************************/
/**********************************************************************/
void (* PF_SPI) (void);

void __vector_12 (void) __attribute__ ((signal , used));

void __vector_12 (void)
{
	PF_SPI();
}

/**********************************************************************/

void CALLback_SPI (void (* ptr) (void))
{
	PF_SPI = (void (*) (void))ptr ;
}

/**********************************************************************/

void SPI_MasterInit(void)
{

	/* Set MOSI and SCK output, all others input */
	DIO_voidSetpinDirection(PORTB,CLK,OUT);
	DIO_voidSetpinDirection(PORTB,MOSI,OUT);
	DIO_voidSetpinDirection(PORTB,MISO,IN);
	DIO_voidSetpinDirection(PORTB,SS,OUT);
	DIO_voidSetpinValue(PORTB,SS,LOW);

	/* Enable SPI, Master, set clock rate fck/16 */
	//SET(SPCR_REG,SPIE);
	SET(SPCR_REG,SPE);
	//SET(SPCR_REG,DORD);
	SET(SPCR_REG,MSTR);
	//SET(SPCR_REG,CPOL);
	//SET(SPCR_REG,CPHA);
	//SET(SPCR_REG,SPR1);
	SET(SPCR_REG,SPR0);

	//SPCR_REG = (1<<SPE)|(1<<MSTR)|(1<<SPR0);
}

/**********************************************************************/

void SPI_MasterTransmit(u8 cData)
{
	/* Start transmission */
	SPDR_REG = cData;
	/* Wait for transmission complete */
	while(!(SPSR_REG & (1<<SPIF)));
}

/**********************************************************************/

void SPI_SlaveInit(void)
{

	/* Set MISO output, all others input */
	DIO_voidSetpinDirection(PORTB,MOSI,IN);
	DIO_voidSetpinDirection(PORTB,CLK,IN);
	DIO_voidSetpinDirection(PORTB,SS,IN);
	DIO_voidSetpinDirection(PORTB,MISO,OUT);

	/* Enable SPI */
	//SET(SPCR_REG,SPIE);
	SET(SPCR_REG,SPE);
	//SET(SPCR_REG,DORD);
	//SET(SPCR_REG,MSTR);
	//SET(SPCR_REG,CPOL);
	//SET(SPCR_REG,CPHA);
	//SET(SPCR_REG,SPR1);
	SET(SPCR_REG,SPR0);
}

/**********************************************************************/

u8 SPI_SlaveReceive(void)
{

	/* Wait for reception complete */
	while(!(SPSR_REG & (1<<SPIF)));
	/* Return data register */
	return SPDR_REG;
}

/**********************************************************************/
void SPI_INIT(u8 MASTER_SLAVE ,u8 SCK_Frequency ,u8 CLOCK_POLARITY ,u8 CLOCK_PHASE ,u8 DATA_ORDER ,u8 INTERRUPT_POLLING )
{
	if(MASTER_SLAVE == MASTER)
	{
		SET(SPCR_REG,MSTR);
	}
	else if(MASTER_SLAVE == SLAVE)
	{
		CLR(SPCR_REG,MSTR);
	}

	if(CLOCK_POLARITY == RISING)
	{
		CLR(SPCR_REG,CPOL);
	}
	else if(CLOCK_POLARITY == FALLING)
	{
		SET(SPCR_REG,CPOL);
	}

	if(CLOCK_PHASE == SAMPLE)
	{
		CLR(SPCR_REG,CPHA);
	}
	else if(CLOCK_PHASE == SETUP)
	{
		SET(SPCR_REG,CPHA);
	}

	if(DATA_ORDER == MSB)
	{
		CLR(SPCR_REG,DORD);
	}
	else if(DATA_ORDER == LSB)
	{
		SET(SPCR_REG,DORD);
	}

	if(INTERRUPT_POLLING == POLLING)
	{
		CLR(SPCR_REG,SPIE);
	}
	else if(INTERRUPT_POLLING == INTERRUPT)
	{
		SET(SPCR_REG,SPIE);
	}


	if(SCK_Frequency == FOSCN4)
	{
		CLR(SPCR_REG,SPR0);
		CLR(SPCR_REG,SPR1);
		CLR(SPSR_REG,SPI2X);
	}
	else if(SCK_Frequency == FOSCN16)
	{
		SET(SPCR_REG,SPR0);
		CLR(SPCR_REG,SPR1);
		CLR(SPSR_REG,SPI2X);
	}
	else if(SCK_Frequency == FOSCN64)
	{
		CLR(SPCR_REG,SPR0);
		SET(SPCR_REG,SPR1);
		CLR(SPSR_REG,SPI2X);
	}
	else if(SCK_Frequency == FOSCN128)
	{
		SET(SPCR_REG,SPR0);
		SET(SPCR_REG,SPR1);
		CLR(SPSR_REG,SPI2X);
	}
	else if(SCK_Frequency == FOSCD2)
	{
		CLR(SPCR_REG,SPR0);
		CLR(SPCR_REG,SPR1);
		SET(SPSR_REG,SPI2X);
	}
	else if(SCK_Frequency == FOSCD8)
	{
		SET(SPCR_REG,SPR0);
		CLR(SPCR_REG,SPR1);
		SET(SPSR_REG,SPI2X);
	}
	else if(SCK_Frequency == FOSCD32)
	{
		CLR(SPCR_REG,SPR0);
		SET(SPCR_REG,SPR1);
		SET(SPSR_REG,SPI2X);
	}
	else if(SCK_Frequency == FOSCD64)
	{
		SET(SPCR_REG,SPR0);
		SET(SPCR_REG,SPR1);
		SET(SPSR_REG,SPI2X);
	}
}

/*******************************************************/
/* AUTHOR 	: ABDULRAHMAN OSAMA MOHAMED                */
/* DEC		: LCD DRIVER                               */
/* DATE		: 30/1/2020                                */
/*******************************************************/

#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"LCD_int.h"
#include"DIO_interface.h"
#include<util/delay.h>

/****************PIN FUNCTIONS ****************************************/
/**********************************************************************/

void  LCD_8voidInit(void)
{
	/* set port direction to be out */
	DIO_voidSetportDirection(PORT_DATA , PORT_OUT);
	/*set control pins to be output */
	DIO_voidSetpinDirection(PORT_CONTROL , PIN5 , OUT);
	DIO_voidSetpinDirection(PORT_CONTROL , PIN6 , OUT);
	DIO_voidSetpinDirection(PORT_CONTROL , PIN7 , OUT);

	/* wait for 35 ms after vdd rises to 4.5 volt */
	_delay_ms(35);
	/* function set       0x38                    */
	LCD_SendCMD(0b00111000);
	/* wait for 1 ms                              */
	_delay_ms(1);
	/* Display ON/OFF     0x0f                    */
	LCD_SendCMD(0b00001111);
	/* wait for 1 ms                              */
	_delay_ms(1);
	/* display clear      0x01                    */
	LCD_SendCMD(0b00000001);
	/* wait for 1 ms                              */
	_delay_ms(2);
	/* Entry mode         0x06                    */
	LCD_SendCMD(0b00000110);
	/* End of initialisation                      */

}

/**********************************************************************/
/**********************************************************************/

void  LCD_4voidInit(void)
{
	/* wait for 35 ms after vdd rises to 4.5 volt */
	_delay_ms(35);
	/* function set       0x38                    */
	LCD_SendCMD(0b10100000);
	/* wait for 1 ms                              */
	_delay_ms(1);
	/* Display ON/OFF     0x0f                    */
	LCD_SendCMD(0b11110000);
	/* wait for 1 ms                              */
	_delay_ms(1);
	/* display clear      0x01                    */
	LCD_SendCMD(0b00010000);
	/* wait for 1 ms                              */
	_delay_ms(2);
	/* Entry mode         0x06                    */
	LCD_SendCMD(0b01100000);
	/* End of initialisation                      */

}
/**********************************************************************/
/**********************************************************************/

void  LCD_SendCMD(u8 u8Cmd_copy )
{ 
	/* 1-RS PIN =low     which means send command              */
	DIO_voidSetpinValue(PORT_CONTROL , RS_PIN , 0 );
	/* 2-RW PIN =low     which means write command             */
	DIO_voidSetpinValue(PORT_CONTROL , RW_PIN , 0 );
	/* 3-send command on the bus                               */
	DIO_voidSetportValue(PORT_DATA , u8Cmd_copy);
	/* 4-EN PIN =HIGH then LOW     which means ENABLE LATCH    */
	DIO_voidSetpinValue(PORT_CONTROL , EN_PIN , 1 );
	_delay_ms(1);
	DIO_voidSetpinValue(PORT_CONTROL , EN_PIN , 0 );

}



/***********************************************************************/
/***********************************************************************/

void  LCD_WriteData(u8 u8Data_copy )
{ 
	/* 1-RS PIN =HIGH     which means send DATA                */
	DIO_voidSetpinValue(PORT_CONTROL , RS_PIN , 1 );
	/* 2-RW PIN =low     which means write DATA                */
	DIO_voidSetpinValue(PORT_CONTROL , RW_PIN , 0 );
	/* 3-send command on the bus                               */
	DIO_voidSetportValue(PORT_DATA , u8Data_copy);
	/* 4-EN PIN =HIGH then LOW     which means ENABLE LATCH    */
	DIO_voidSetpinValue(PORT_CONTROL , EN_PIN , 1 );
	_delay_ms(1);
	DIO_voidSetpinValue(PORT_CONTROL , EN_PIN , 0 );

}

/***********************************************************************/
/***********************************************************************/

void LCD_voidWriteString(u8 * u8ptr_copy)
{
	u8 i=0;
	while(u8ptr_copy[i] != '\0')
	{
		LCD_WriteData(u8ptr_copy[i]);
		i++;
	}
}

/***********************************************************************/
/***********************************************************************/


void LCD_voidGotoXY(u8 x , u8 y)
{
	if(x==0)
	{
		LCD_SendCMD(0x80+y);
	}
	else if(x==1)
	{
		LCD_SendCMD(0xc0+y);
	}
}

/***********************************************************************/
/***********************************************************************/

int power(int a,int b)
{
	int i=1 ,res=1;
	for(i=1;i<=b;i++)
	{
		res*=a;
	}
	return res;
}



void LCD_WriteNum(s32 u16Num_copy)
{
	s32 temp = u16Num_copy ,reverse_num =0 ;
	s8 i, size =0  ,zeros= 0 ;
	while(u16Num_copy != 0)
	{
		size += 1;
		u16Num_copy /= 10 ;
	}
	u16Num_copy =temp ;

	if(((u16Num_copy % 10) == 0))
	{ zeros =1 ;}
	if(((u16Num_copy % 100) == 0))
	{ zeros =2 ;}
	if(((u16Num_copy % 1000) == 0))
	{ zeros =3 ;}
	if(((u16Num_copy % 10000) == 0))
	{ zeros =4 ;}
	if(((u16Num_copy % 100000) == 0))
	{ zeros =5 ;}
	if(((u16Num_copy % 1000000) == 0))
	{ zeros =6 ;}
	if(((u16Num_copy % 10000000) == 0))
	{ zeros =7 ;}
	if(((u16Num_copy % 100000000) == 0))
	{ zeros =8 ;}
	if(((u16Num_copy % 1000000000) == 0))
	{ zeros =9 ;}

	for(i=size ; i > 0; i--)
	{
		reverse_num += ((u16Num_copy % 10) * (power(10,i-1)));
		u16Num_copy /= 10 ;

	}

	while(reverse_num != 0)
	{
		i = (reverse_num % 10)  ;
		LCD_WriteData(i+ 48);
		reverse_num /= 10 ;
	}
	for(i=0;i<zeros;i++)
	{
		LCD_WriteData(48);
	}
}


/*
void LCD_WriteNum(u16 u16Num_copy)
{
	u16 temp =u16Num_copy ;
	u8 i, size =0 , reverse_num =0;
	while(u16Num_copy !=0)
	{
		size += 1;
		u16Num_copy /=10 ;
	}
	u16Num_copy =temp ;
	for(i=size-1;size>=0;size--)
	{
		reverse_num += ((u16Num_copy % 10)*(power(10,i)));
		u16Num_copy /= 10 ;
	}
	while(reverse_num !=0)
	{
		LCD_WriteData((reverse_num%10)+48);
		reverse_num /= 10 ;
	}
}
*/

/***********************************************************************/
/***********************************************************************/

void LCD_CLEAR_DISPLAY(void)
{
	LCD_SendCMD(0x01);
}

void LCD_RETURN_HOME(void)
{
	LCD_SendCMD(0x02);
}

void LCD_DISPLAY_SHIFT_RIGHT(void)
{
	LCD_SendCMD(0x1c);
}

void LCD_DISPLAY_SHIFT_LEFT(void)
{
	LCD_SendCMD(0x18);
}



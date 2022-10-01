/****************GUARD MY FILE********************/
#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H

#define PORT_CONTROL PORTB
#define PORT_DATA    PORTD

#define EN_PIN PIN5
#define RW_PIN PIN6
#define RS_PIN PIN7

/****************LED FUNCTIONS *********************/

void  LCD_8voidInit(void);
void  LCD_4voidInit(void);

void  LCD_SendCMD(u8 u8Cmd_copy );
void  LCD_WriteData(u8 u8Data_copy );
void LCD_voidWriteString(u8 * u8ptr_copy);

void LCD_voidGotoXY(u8 x , u8 y);

void LCD_WriteNum(u16 u16Num_copy);
int power(int a,int b);

void LCD_CLEAR_DISPLAY(void);
void LCD_RETURN_HOME(void);

void LCD_DISPLAY_SHIFT_RIGHT(void);
void LCD_DISPLAY_SHIFT_LEFT(void);


#endif
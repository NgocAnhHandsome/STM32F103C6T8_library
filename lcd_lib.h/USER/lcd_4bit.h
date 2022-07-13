/*
  ******************************************************************************
  * @file		lcd4bit.h                                                      *
  * @author	Luu Ngoc Anh                                                       *
  * @date		00/00/0000                                                     *
  ******************************************************************************
*/
	
#ifndef __LCD__H
#define __LCD__H

#ifdef __cplusplus
 extern "C" {
#endif
#define LCD_RS      GPIO_Pin_13
#define LCD_RW      GPIO_Pin_14
#define LCD_EN      GPIO_Pin_15

#define LCD_D4      GPIO_Pin_4
#define LCD_D5      GPIO_Pin_5
#define LCD_D6      GPIO_Pin_6
#define LCD_D7      GPIO_Pin_7
	 
void LCD_Init(void);
void LCD_Enable(void);
void LCD_Send4bit(unsigned char data);
void LCD_Command(unsigned char data);
void LCD_PutChar(unsigned char data);
void LCD_Puts(char *Str);
void LCD_Gotoxy(unsigned char x, unsigned char y);
	 
#ifdef __cplusplus
}
#endif

#endif

/********************************* END OF FILE ********************************/
/******************************************************************************/
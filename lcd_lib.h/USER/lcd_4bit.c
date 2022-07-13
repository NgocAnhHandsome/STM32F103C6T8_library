#include "lcd_4bit.h"
#include "stm32f10x.h"                  // Device header
#include "delay.h"


GPIO_InitTypeDef GPIO_InitStructure;

void LCD_Init(void)
{
	DelayInit();
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOC,ENABLE);
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin   = LCD_D4|LCD_D5|LCD_D6|LCD_D7;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin   = LCD_RS|LCD_RW|LCD_EN;
	GPIO_Init(GPIOC,&GPIO_InitStructure);
	
	LCD_Command(0x02); // di chuyen con tro vê dau man hinh
  LCD_Command(0x28); // giao thuc 4 bit, hien thi 2 hang, ki tu 5x8
  LCD_Command(0x0C); // cho phep hien thi man hinh
  LCD_Command(0x06); // tang ID, khong dich khung hinh
  LCD_Command(0x01); // xoa toan bo khung hinh
}
void LCD_Enable(void)
{
	GPIO_SetBits(GPIOC,LCD_EN);
	DelayMs(1);
	GPIO_ResetBits(GPIOC,LCD_EN);
	DelayMs(1);
}
void LCD_Send4bit(unsigned char data)
{
	GPIO_WriteBit(GPIOA,LCD_D4,data&1);
	GPIO_WriteBit(GPIOA,LCD_D5,(data >> 1)&1);
	GPIO_WriteBit(GPIOA,LCD_D6,(data >> 2)&1);
	GPIO_WriteBit(GPIOA,LCD_D7,(data >> 3)&1);
}
void LCD_Command(unsigned char data)
{
	LCD_Send4bit(data >> 4);
	LCD_Enable();
	LCD_Send4bit(data);
	LCD_Enable();
}
void LCD_PutChar(unsigned char data)
{
	GPIO_SetBits(GPIOC,LCD_RS);
	LCD_Command(data);
	GPIO_ResetBits(GPIOC,LCD_RS);
}
void LCD_Puts(char *Str)
{
	while(*Str)
	{
		LCD_PutChar(*Str);
		Str++;
	}
}
void LCD_Gotoxy(unsigned char x, unsigned char y)
{
	unsigned char Address;
	if(y == 0)
	{
		Address = 0x80 + x;
	}
	if(y == 1)
	{
		Address = 0xc0 + x;
	}
	LCD_Command(Address);
}
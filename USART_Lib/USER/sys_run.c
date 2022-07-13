/*
  ******************************************************************************
  * @file		abc.c                                                              *
  * @author	Luu Ngoc Anh                                                       *
  * @date		00/00/0000                                                         *
  ******************************************************************************
*/
#include "stm32f10x.h"                  // Device header
#include "sys_run.h" 
#include "usart_lib.h"

void Delay_ms(unsigned int _varTime)
{
	uint16_t i,j;
	for(i=0;i<_varTime;i++)
	{
		for(j=0;j<0x2aff;j++){}
	}
}
void Sys_Init(void)
{
	GPIO_InitTypeDef GPIO_Structure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
	
	GPIO_Structure.GPIO_Mode =   GPIO_Mode_Out_PP;
	GPIO_Structure.GPIO_Pin  =   GPIO_Pin_13;
	GPIO_Structure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC,&GPIO_Structure);
	
	UsartLib_Init(9600);
	GPIO_WriteBit(GPIOC,GPIO_Pin_13,0);
}
void Sys_Run(void)
{
	char s1[] = "bat den";
	char s2[] = "tat den";
	if(UsartLib_flag())
	{
			if(UsartLib_CompareStr(s1)==1)
			{
					GPIO_WriteBit(GPIOC,GPIO_Pin_13,0);
			}
			if(UsartLib_CompareStr(s2)==1)
			{
					GPIO_WriteBit(GPIOC,GPIO_Pin_13,1);
			}
	}
}

/**f******************************* END OF FILE ********************************/
/******************************************************************************/

#include "stm32f10x.h"   // Device header
#include "delay.h"

GPIO_InitTypeDef GpioInitStructure;

int main()
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
	GpioInitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GpioInitStructure.GPIO_Pin  = GPIO_Pin_13;
	GpioInitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC,&GpioInitStructure);
	DelayInit();
	while(1)
	{
		GPIO_ResetBits(GPIOC,GPIO_Pin_13);
		DelayMs(1000);
		GPIO_SetBits(GPIOC,GPIO_Pin_13);
		DelayMs(1000);
	}
}
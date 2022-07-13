#include "stm32f10x.h"                  // Device header
//#include "blink_led_lib.h"



void delay(uint16_t _vrTime)
{
	uint16_t i,j;
	for(i=0;i< _vrTime; i++)
	{
		for(j=0;j<0x2aff;j++){}
	}
}
void Blink_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOB,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable,ENABLE);
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);	
}

void Blink1(void){
		GPIO_ResetBits(GPIOA,GPIO_Pin_15);
		GPIO_ResetBits(GPIOB,GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_9);
		delay(50);
		GPIO_SetBits(GPIOA,GPIO_Pin_15);
		GPIO_SetBits(GPIOB,GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_9);
		delay(50);
}

void Blink2(void){
	int a[] = {0,1,0,1};
	int i=0;
	for(;i<2;i++){
		GPIO_WriteBit(GPIOA,GPIO_Pin_15,a[i]);
		GPIO_WriteBit(GPIOB,GPIO_Pin_4,a[i]);
		GPIO_WriteBit(GPIOB,GPIO_Pin_6,a[i]);
		GPIO_WriteBit(GPIOB,GPIO_Pin_8,a[i]);
		GPIO_WriteBit(GPIOB,GPIO_Pin_3,a[i+1]);
		GPIO_WriteBit(GPIOB,GPIO_Pin_5,a[i+1]);
		GPIO_WriteBit(GPIOB,GPIO_Pin_7,a[i+1]);
		GPIO_WriteBit(GPIOB,GPIO_Pin_9,a[i+1]);
		delay(100);
	}
}

void Blink3(void){
	unsigned int x[] = {0xfdff,0xfeff,0xf7f,0xffbf,0xffdf,0xffef,0xfff7};
	int i=0;
	for(;i<7;i++){
		GPIOB->ODR = x[i];
		delay(500);
	}
	GPIOB->ODR = 0xffff;
	GPIO_WriteBit(GPIOA,GPIO_Pin_15,0);
	delay(500);
	GPIO_WriteBit(GPIOA,GPIO_Pin_15,1);
}
void Blink4(void){
	unsigned int x[] = {0xfdff,0xfcff,0xfc7f,0xfc3f,0xfc1f,0xfc0f,0xfc07};
	int i=0;
	for(;i<7;i++){
		GPIOB->ODR = x[i];
		delay(100);
	}
	GPIO_WriteBit(GPIOA,GPIO_Pin_15,0);
	delay(100);
	GPIO_WriteBit(GPIOA,GPIO_Pin_15,1);
	delay(100);
	GPIOB->ODR = 0xffff;
	delay(100);
}

void Blink_OnLed(void)
{
		GPIO_ResetBits(GPIOA,GPIO_Pin_15);
		GPIO_ResetBits(GPIOB,GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_9);		
}
void Blink_OffLed(void)
{
		GPIO_SetBits(GPIOA,GPIO_Pin_15);
		GPIO_SetBits(GPIOB,GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_9);	
}
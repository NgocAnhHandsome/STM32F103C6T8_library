
#include "stm32f10x.h"                  // Device header
#include "sys_run.h"
#include "usart_lib.h"
#include "stdio.h"
#include "stdlib.h"

char s[100];
unsigned int i,j;
int a[100];
int n;
int main()
{
	Sys_Init();
	while(1)
	{
		Sys_Run();
	}
}

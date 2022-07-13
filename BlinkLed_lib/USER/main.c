#include "stm32f10x.h"                  // Device header
#include "blink_led_lib.h"

int main()
{
	Blink_Init();
	while(1)
	{
		Blink_OnLed();
	}
}

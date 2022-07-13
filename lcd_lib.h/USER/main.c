#include "lcd_8bit.h"

int main()
{
	LCD_Init();
	while(1)
	{
		LCD_Gotoxy(0,0);
		LCD_Puts("Ngoc");
		LCD_Gotoxy(13,0);
		LCD_Puts("Anh");
	}
}
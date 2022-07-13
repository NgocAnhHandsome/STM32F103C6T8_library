/*
  ******************************************************************************
  * @file		blink_led_lib.h                                                              *
  * @author	Luu Ngoc Anh                                                       *
  * @date		00/00/0000                                                         *
  ******************************************************************************
*/

#ifndef __BLINKLED__
#define __BLINKLED__

#ifdef __cplusplus
 extern "C" {
#endif
void delay(uint16_t _vrTime);
void Blink_Init(void);
void Blink_OnLed(void);
void Blink_OffLed(void);
void Blink1(void);
void Blink2(void);
void Blink3(void);
void Blink4(void);

#ifdef __cplusplus
}
#endif

#endif

/********************************* END OF FILE ********************************/
/******************************************************************************/
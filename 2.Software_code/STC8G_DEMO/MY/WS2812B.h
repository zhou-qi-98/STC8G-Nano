#include "STC8xxxx.H"
#ifndef __WS2812B_H__
#define __WS2812B_H__	

sbit WS_LED = P3^7;

void WS_Send_Data(bit dat);
void WS_Reset_Code();
void WS_Send_Color(unsigned char R,unsigned char G,unsigned char B);
#endif 
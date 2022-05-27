/*-----------------------------------------------*/
/*---作者：爱学习的王大可------------------------*/
/*---项目：STC8G_Nano最小系统开发板设计DEMO程序--*/
/*---芯片：STC8G1K17-----------------------------*/
/*---时间：2022年5月25日18:40--------------------*/
/*---Copyright --> 爱学习的王大可  保留所有权利--*/
/*-----------------------------------------------*/


/*头文件引入区域*/
#include "STC8xxxx.H"
#include "GPIO.H"
#include "oled.h"
#include "WS2812B.h"
#include "UART.H"
#include "stdio.h"
#include "bmp.h"
#include "Exti.h"

/*管脚定义区域*/
sbit LED = P1^0;
sbit KEY1 = P3^2;
sbit KEY2 = P3^3;

/*函数声明区域*/
void Delay10ms();
void Delay100ms();
void Time0_Init();


/*全局变量声明区*/
bit Timt0_flag=0;
u8 WakeUpSource;


/*下面开始执行主程序*/
void main(){
		GPIO_config();  //GPIO初始化
		P37=0;//先把5050幻彩关闭，否则上电会有绿灯
		OLED_Init();		//OLED初始化
		Time0_Init();   //定时器初始化
		Exti_config();		//中断初始化
		UART_config();	//串口1串口2初始化	
	  //OLED_ColorTurn(1);//反显
		OLED_DisplayTurn(0);
		OLED_Clear();
		OLED_DrawBMP(0,0,80,128,BMP1);
		LED=1;
    while(1)
		{
			if(Timt0_flag==1)
			{
				Timt0_flag=0;
				//LED=~LED;
				WS_Send_Color(1,1,1);
				//OLED_ShowString(0,4,"STC8G-Demo",16);
				//OLED_ShowString(0,8,"Author:ZQ",16);
				printf("板子：STC8G-Nano\r\n");
				printf("程序：STC8G-Demo_A0\r\n");
				printf("作者：周琦\r\n");
				printf("时间：22022/5/25 21:25\r\n\r\n");
			}
			if(WakeUpSource == 1)
			{
				WakeUpSource=0;
				printf("外中断INT0唤醒\r\n");
				LED=~LED;
			}				
    }
}

/*定时器0初始化*/
void Time0_Init(){
	TMOD= 0X01;
	TL0 = 0x18;		//设置定时初始值
	TH0 = 0xFC;		//设置定时初始值
	TF0 = 0;		//清除TF0标志
	EA=1;
	ET0 =1;	
	TR0 = 1;//定时器0开始计数
}

/*定时器0中断服务函数*/
void time() interrupt 1
{
	static int count=0;
	TL0 = 0x18;		//设置定时初始值
	TH0 = 0xFC;		//设置定时初始值
	count++;
	if(count>=1000)//12M晶振计时到达1S
	{
		count=0;
		Timt0_flag=1;
	}	
}

void Delay100ms()
{
	Delay10ms();Delay10ms();
	Delay10ms();Delay10ms();
	Delay10ms();Delay10ms();
	Delay10ms();Delay10ms();
	Delay10ms();Delay10ms();
}

void Delay10ms()		//@12.000MHz
{
	unsigned char i, j;

	i = 117;
	j = 184;
	do
	{
		while (--j);
	} while (--i);
}
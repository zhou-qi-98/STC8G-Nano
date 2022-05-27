/*-----------------------------------------------*/
/*---���ߣ���ѧϰ�������------------------------*/
/*---��Ŀ��STC8G_Nano��Сϵͳ���������DEMO����--*/
/*---оƬ��STC8G1K17-----------------------------*/
/*---ʱ�䣺2022��5��25��18:40--------------------*/
/*---Copyright --> ��ѧϰ�������  ��������Ȩ��--*/
/*-----------------------------------------------*/


/*ͷ�ļ���������*/
#include "STC8xxxx.H"
#include "GPIO.H"
#include "oled.h"
#include "WS2812B.h"
#include "UART.H"
#include "stdio.h"
#include "bmp.h"
#include "Exti.h"

/*�ܽŶ�������*/
sbit LED = P1^0;
sbit KEY1 = P3^2;
sbit KEY2 = P3^3;

/*������������*/
void Delay10ms();
void Delay100ms();
void Time0_Init();


/*ȫ�ֱ���������*/
bit Timt0_flag=0;
u8 WakeUpSource;


/*���濪ʼִ��������*/
void main(){
		GPIO_config();  //GPIO��ʼ��
		P37=0;//�Ȱ�5050�òʹرգ������ϵ�����̵�
		OLED_Init();		//OLED��ʼ��
		Time0_Init();   //��ʱ����ʼ��
		Exti_config();		//�жϳ�ʼ��
		UART_config();	//����1����2��ʼ��	
	  //OLED_ColorTurn(1);//����
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
				printf("���ӣ�STC8G-Nano\r\n");
				printf("����STC8G-Demo_A0\r\n");
				printf("���ߣ�����\r\n");
				printf("ʱ�䣺22022/5/25 21:25\r\n\r\n");
			}
			if(WakeUpSource == 1)
			{
				WakeUpSource=0;
				printf("���ж�INT0����\r\n");
				LED=~LED;
			}				
    }
}

/*��ʱ��0��ʼ��*/
void Time0_Init(){
	TMOD= 0X01;
	TL0 = 0x18;		//���ö�ʱ��ʼֵ
	TH0 = 0xFC;		//���ö�ʱ��ʼֵ
	TF0 = 0;		//���TF0��־
	EA=1;
	ET0 =1;	
	TR0 = 1;//��ʱ��0��ʼ����
}

/*��ʱ��0�жϷ�����*/
void time() interrupt 1
{
	static int count=0;
	TL0 = 0x18;		//���ö�ʱ��ʼֵ
	TH0 = 0xFC;		//���ö�ʱ��ʼֵ
	count++;
	if(count>=1000)//12M�����ʱ����1S
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
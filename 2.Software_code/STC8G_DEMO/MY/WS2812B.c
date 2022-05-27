/*-----------------------------------------------*/
/*---���ߣ���ѧϰ�������------------------------*/
/*---�ļ���WS2812B.c-----------------------------*/
/*---˵���������ò�5050�⺯��--------------------*/
/*---ʱ�䣺2022��5��25��18:40--------------------*/
/*---Copyright --> ��ѧϰ�������  ��������Ȩ��--*/
/*-----------------------------------------------*/

#include <intrins.h>
#include <WS2812B.h>


/*д����1��0����*/
void WS_Send_Data(bit dat)
{
	if(dat)
	{
		WS_LED=1;
		_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();
		_nop_();_nop_();_nop_();_nop_();_nop_();
		WS_LED=0;	
	}else
	{
		WS_LED=1;
		_nop_();_nop_();_nop_();_nop_();
		WS_LED=0;
		_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();
		_nop_();_nop_();
	}
}

/*��λ��*/
void WS_Reset_Code()
{
	unsigned char i=0;
	for (i = 0; i < 85; i++)
	_nop_();
}


void WS_Send_Color(unsigned char R,unsigned char G,unsigned char B)
{
	//WS_Reset_Code();
	WS_Send_Data(G&0X80);WS_Send_Data(G&0X40);WS_Send_Data(G&0X20);WS_Send_Data(G&0X10);
	WS_Send_Data(G&0X08);WS_Send_Data(G&0X04);WS_Send_Data(G&0X02);WS_Send_Data(G&0X01);
	
	WS_Send_Data(R&0X80);WS_Send_Data(R&0X40);WS_Send_Data(R&0X20);WS_Send_Data(R&0X10);
	WS_Send_Data(R&0X08);WS_Send_Data(R&0X04);WS_Send_Data(R&0X02);WS_Send_Data(R&0X01);
	
	WS_Send_Data(B&0X80);WS_Send_Data(B&0X40);WS_Send_Data(B&0X20);WS_Send_Data(B&0X10);
	WS_Send_Data(B&0X08);WS_Send_Data(B&0X04);WS_Send_Data(B&0X02);WS_Send_Data(B&0X01);
	WS_Reset_Code();
}
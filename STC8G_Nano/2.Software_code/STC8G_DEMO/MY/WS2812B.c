/*-----------------------------------------------*/
/*---作者：爱学习的王大可------------------------*/
/*---文件：WS2812B.c-----------------------------*/
/*---说明：驱动幻彩5050库函数--------------------*/
/*---时间：2022年5月25日18:40--------------------*/
/*---Copyright --> 爱学习的王大可  保留所有权利--*/
/*-----------------------------------------------*/

#include <intrins.h>
#include <WS2812B.h>


/*写数据1或0函数*/
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

/*复位码*/
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
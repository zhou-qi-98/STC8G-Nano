


/*定时器0初始化*/
void Time0_Init(){
	TMOD= 0X01;
	TL0 = 0x9C;		//设置定时初始值
	TH0 = 0xFF;		//设置定时初始值
	TF0 = 0;		//清除TF0标志
	EA=1;
	ET0 =1;	
}



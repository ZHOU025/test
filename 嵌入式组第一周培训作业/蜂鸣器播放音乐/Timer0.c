#include <REGX52.H>//定时器是内部的

//时钟+中断的寄存器   时钟是不会停的一旦开启，能改变的只有初始值
void Timer0Init(void)		//1毫秒@11.0592MHz
{
	//TMOD=0x00;
	TMOD &= 0xF0;		//设置定时器模式
	TMOD |= 0x01;		//设置定时器模式
	TL0 = 0x66;		//设置定时初值
	TH0 = 0xFC;		//设置定时初值
	TF0 = 0;		//清除TF0标志
	TR0 = 1;		//定时器0开始计时
	ET0=1;
	EA=1;
	PT0=0;
}



////          中断系统模板
//void Timer0_Routine() interrupt 1   
//{		
//		static unsigned int T0count;
//		TL0 = 0x66;		//设置定时初值
//		TH0 = 0xFC;		//设置定时初值
//		T0count++;
//		if(T0count>=1000)
//		{
//		T0count=0;
//		}
//		
//}


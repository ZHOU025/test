#include <REGX52.H>


//串口初始化，参数无，无返回
void UART_Init()     //4800bps@11.0592MHz
{
	SCON=0x40;//不使能
	PCON=0x80;   //加倍
	TMOD &= 0x0F;		//设置定时器模式
	TMOD |= 0x20;		//设置定时器模式
	TL1 = 0xF4;		//设定定时初值
	TH1 = 0xF4;		//设定定时器重装值
	TR1 = 1;		//定时器0开始计时
	ET1 = 0;		//不需要定时器1中断
	
}	
//串口要发送的一个数据，参数为要发送的一个字节，返回值无
void UART_SendByte(unsigned char Byte)
{
	SBUF=Byte;
	while(TI==0);
	TI=0;
}	
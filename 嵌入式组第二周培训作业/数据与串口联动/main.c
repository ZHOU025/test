#include <REGX52.H>
#include "AT24C02.h"
#include "Delay.h"
#include "UART.h"
#include "Key.h"
unsigned char Byte,KeyNum;
void main()
{
	UART_Init();//串口初始化
	while(1)
	{
	KeyNum=Key();//获取按键的值

	if(KeyNum==4){Byte=AT24C02_ReadByte(0);UART_SendByte(Byte);}//如果按下此按键，就可以存取当前数值。
	}		
}	

void UART_Routine() interrupt 4
{  
    if(RI==1)
	{
		Byte=SBUF;//将串口助手的十六进制数据 或文本数据 输入
		AT24C02_WriteByte(0,Byte);//自动把输入数据保存在芯片
		Delay(5);//每次保存都要延迟保证数据传输。
		RI=0;//RI需要手动置0
	}
	
}
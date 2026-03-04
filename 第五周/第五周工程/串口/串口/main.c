#include <REGX52.H>
#include "Delay.h"
#include "UART.h"
unsigned char i;
unsigned char UART[]={0x48,0x65,0x6c,0x6c,0x6f,0x35,0x31,0x21};

void main()
{	
	UART_Init();
	
	while(1)
	{
	for(i=0;i<8;i++)
	{UART_SendByte(UART[i]);}
	Delay(1000);
	if(i>=8){i=0;}
	}	
}	
//
void UART_Rountine()  interrupt 4
{    //判断是谁中断
    if(RI==1)
	{
		P2=~P2;
		
		RI=0;
	}
	
}





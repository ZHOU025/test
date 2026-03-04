#include <REGX52.H>
#include "Timer0.h"


	unsigned char i;
void main()
{	P2=0xfe;
	Timer0Init();
while(1)
	{

	}

}	
void Timer0_Routine() interrupt 1   
{		
		static unsigned int T0count;
		TL0 = 0x66;		//设置定时初值
		TH0 = 0xFC;		//设置定时初值
		T0count++;
		if(T0count>=1000)
		{
		T0count=0;
		i++;
		if(i>7)
		{i=0;}	
		P2=P2<<i;	
		}
}		
#include <REGX52.H>

void Timer1Init(void)		//1??@11.0592MHz
{
	
	TMOD &= 0x0f;		
	TMOD |= 0x10;	
	TL1 = 0x66;		
	TH1 = 0xFC;	
	TF1 = 0;		
	TR1 = 1;		
	ET1=1;
	EA=1;
	PT1=0;
}

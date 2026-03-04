#include <REGX52.H>
#include "Timer0.h"
#include "NIXIE.H"
#include "Key.h"


unsigned char KeyNum,RunFlag,Grade;
unsigned char Min,Second,MiniSecond;
void main()
{	

	Timer0Init();
	while(1)
	{
	

	Nixie_SetBuf(8,10);
	Nixie_SetBuf(7,10);
	Nixie_SetBuf(6,10);
	Nixie_SetBuf(5,Second/10);
	Nixie_SetBuf(4,Second%10);
	Nixie_SetBuf(3,10);
	Nixie_SetBuf(2,10);
	Nixie_SetBuf(1,10);
	
	}
}
	
	void Sec_Loop(void)
{
	
	MiniSecond++;
	if(MiniSecond>=100)
	{
	MiniSecond=0;
	Second++;
	}	
	if(Second>=60)
	{
	Second=0;
	Min++;
	}	
	if(Min>=60)
	{Min=0;}	
	
}	

void Timer0_Routine() interrupt 1   
{		
		static unsigned int T0count,T0count1,T0count2;
		TL0 = 0x66;		//设置定时初值
		TH0 = 0xFC;		//设置定时初值
		T0count++;
		if(T0count>=20)
		{
		T0count=0;
		Key_Loop();
		}
		T0count1++;
		if(T0count1>=2)
		{
		T0count1=0;
		Nixie_Loop();
		}
		T0count2++;
		if(T0count2>=10)
		{
		T0count2=0;
		Sec_Loop();
		}
		
}


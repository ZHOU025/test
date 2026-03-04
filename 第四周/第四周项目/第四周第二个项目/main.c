#include <REGX52.H>
#include "Timer0.h"
#include "Key.h"
#include <INTRINS.h>
unsigned char Keynum,LEDmode;

void main()
{
	P2=0xFE;
	Timer0Init();
	while(1)
 {   
	 Keynum=Key();
//	 if(Keynum)
//	 {
	if(Keynum==1)
	{
	LEDmode++;
	if(LEDmode>=2){LEDmode=0;}	
	}
	
//  }
}	
}	

void Timer0_Routine() interrupt 1
{		
		static unsigned int T0count;
		TL0 = 0x66;		//设置定时初值
		TH0 = 0xFC;		//设置定时初值
		T0count++;
		if(T0count>=500)
		{
		
		T0count=0;
		if(LEDmode==0)
		{
		P2=_crol_(P2,1);	
		}	
		if(LEDmode==1)
		{
		P2=_cror_(P2,1);
		}
		}
		
}




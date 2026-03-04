#include <REGX52.H>
#include "Timer0.h"
#include "NIXIE.H"
#include "Delay.h"
#include "Key.h"
#include "UART.h"

unsigned char KeyNum,RunFlag,Grade;
unsigned char Min,Second,MiniSecond;
void main()
{	
	
	UART_Init(); 
	Timer0Init();//初始化
	while(1)
	{
	KeyNum=Key();
	if(KeyNum==1)//计时开始或停止
	{
	RunFlag=!RunFlag;
	
	}
	if(KeyNum==2)//计时，成绩清零
	{
	Min=0;
	Second=0;
	MiniSecond=0;
	P2_7=1;	
	P2_6=1;	
	}	
	if(KeyNum==3)//判断成绩
	{
	if((Second*100+MiniSecond)>=950&&(Second*100+MiniSecond)<=1050)//如果在9.5秒到10.5秒为A,点亮一颗LED；
	{
	P2_7=0;
	P2_6=1;
	Grade=0x41;	
	}else if((Second*100+MiniSecond)>=850&&(Second*100+MiniSecond)<950)
	{
	P2_7=0;	
	P2_6=0;
	Grade=0x42;	//如果在8.5到9.5，成绩为B，亮两颗LED；
	}else if((Second*100+MiniSecond)>=1050&&(Second*100+MiniSecond)<1150)
	{
	P2_7=0;	
	P2_6=0;
	Grade=0x42;	//如果在8.5到9.5，成绩为B，亮两颗LED；	
	}
	}	
	if(KeyNum==4)//上传成绩到串口，在串口传输助手中获取等级
	{
	UART_SendByte(Grade);	
	}
	Nixie_SetBuf(8,Min/10);
	Nixie_SetBuf(7,Min%10);
	Nixie_SetBuf(6,11);
	Nixie_SetBuf(5,Second/10);
	Nixie_SetBuf(4,Second%10);
	Nixie_SetBuf(3,11);
	Nixie_SetBuf(2,MiniSecond/10);
	Nixie_SetBuf(1,MiniSecond%10);
	
	}
}
	/**
  * @brief 秒运行的规律
  * @param  无参数
  * @retval 无返回值
  */
	void Sec_Loop(void)
{
	if(RunFlag)
	{MiniSecond++;
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
}	
/**
  * @brief  中断系统
  * @param  无参数
  * @retval 无返回值
  */
void Timer0_Routine() interrupt 1   
{		
		static unsigned int T0count,T0count1,T0count2;
		TL0 = 0x66;		//设置定时初值 每一次溢出为一毫秒
		TH0 = 0xFC;		//设置定时初值
		T0count++;
		if(T0count>=20)//每二十毫秒进行按键扫描
		{
		T0count=0;
		Key_Loop();
		}
		T0count1++;
		if(T0count1>=2)//每两毫秒进行数码管的扫描
		{
		T0count1=0;
		Nixie_Loop();
		}
		T0count2++;
		if(T0count2>=10)//每十毫秒进行一次秒加加
		{
		T0count2=0;
		Sec_Loop();
		}
		
}


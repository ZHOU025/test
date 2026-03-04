#include <REGX52.H>
#include "Delay.h"

unsigned char Key_KeyNum,Temp;
/**
  * @brief  获取键码值
  * @param  参数无
  * @retval Temp返回键码值
  */
unsigned char Key(void)
{
	Temp=Key_KeyNum;
	Key_KeyNum=0;
	return Temp;

}	
/**
  * @brief 获取循环中的状态
  * @param  无参数
  * @retval Keynum是返回的状态
  */
unsigned char Key_GetState()
{
	unsigned char Keynum=0;//没有按按键时为零
	if(P3_1==0){Keynum=1;}
	if(P3_0==0){Keynum=2;}
	if(P3_2==0){Keynum=3;}
	if(P3_3==0){Keynum=4;}
	return Keynum;
}	
/**
  * @brief  在定时器中进行扫描
  * @param  无参数
  * @retval 无返回值
  */
void Key_Loop(void)
{
	static unsigned char NowState,LastState;
	LastState=NowState;
	NowState=Key_GetState();
	if(LastState==1&&NowState==0)
	{
		Key_KeyNum=1;	
	}
	if(LastState==2&&NowState==0)
	{
		Key_KeyNum=2;	
	}
	if(LastState==3&&NowState==0)
	{
		Key_KeyNum=3;	
	}
	if(LastState==4&&NowState==0)
	{
		Key_KeyNum=4;	
	}

}	
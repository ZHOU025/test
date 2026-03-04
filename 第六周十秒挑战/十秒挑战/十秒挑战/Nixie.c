#include <REGX52.H>
#include "Delay.h"

unsigned char Nixie_Buf[9]={0,10,10,10,10,10,10,10,10};
unsigned char Nixietable[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x00,0x40};

/**
  * @brief 在Nixie_Buf[]里设定数组的值
  * @param  Location是数组位数，Number数组在该位的数值
  * @retval 无返回值
  */
void Nixie_SetBuf(unsigned char Location,unsigned char Number)
{
	Nixie_Buf[Location]=Number;
}	

/**
  * @brief  获取数码管的状态
  * @param  location 获取位选，Number获取段选
  * @retval 无返回值
  */
void Nixie_Scan(unsigned char location,unsigned char Number)
{
	P0=0x00;
	switch(location)
	{	
		case 1:P2_4=0,P2_3=0,P2_2=0;break;
		case 2:P2_4=0,P2_3=0,P2_2=1;break;
		case 3:P2_4=0,P2_3=1,P2_2=0;break;
		case 4:P2_4=0,P2_3=1,P2_2=1;break;
		case 5:P2_4=1,P2_3=0,P2_2=0;break;
		case 6:P2_4=1,P2_3=0,P2_2=1;break;
		case 7:P2_4=1,P2_3=1,P2_2=0;break;
		case 8:P2_4=1,P2_3=1,P2_2=1;break;
	}
	P0=Nixietable[Number];

}
/**
  * @brief 扫描数码管
  * @param  无参数
  * @retval 无返回值
  */
void Nixie_Loop(void)
{
	static unsigned char i=1;
	Nixie_Scan(i,Nixie_Buf[i]);
	i++;
	if(i>8){i=1;}
}	
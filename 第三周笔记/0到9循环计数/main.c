#include <REGX52.H>
void Delay(unsigned char xms)		//@11.0592MHz
{   
	while(xms--)
	{unsigned char i, j;

	
	i = 11;
	j = 190;
	do
	{
		while (--j);
	} while (--i);
	}
}

unsigned char Nixietable[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
void Nixie(unsigned char location,number)
{
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
	P0=Nixietable[number];
	Delay(1000);
	P0=0x00;//同时显示多个数字会有残影，位数和段数同时出现。利用延迟规避。
}
void main()
{
	while(1){
		Nixie(8,0);
	
		Nixie(8,1);
		
		Nixie(8,2);
		
		Nixie(8,3);
		
		Nixie(8,4);
		
		Nixie(8,5);
		
		Nixie(8,6);
	
		Nixie(8,7);
		
		Nixie(8,8);
		
		Nixie(8,9);
		
	}	
}	
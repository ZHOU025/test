#include <REGX52.H>
#include "LCD1602.h" 
#include "Delay.h"
#include "MatrixKey.h"

unsigned char KeyNum;
unsigned int Password,count;
 void main()
 {	 LCD_Init();
	 LCD_ShowString(1,1,"Password:");LCD_ShowNum(2,1,Password,4);

	 while(1)
   {
	   KeyNum=MatrixKey();
	   if(KeyNum)
	{	
		if(KeyNum<=10)
		{
			if(count<4)
			{
			Password*=10;//相当于密码左移一位，不同于二进制	
			Password+=KeyNum%10;//将十变为零，获取一位密码
			count++;//计次加一
			}	
			LCD_ShowNum(2,1,Password,4);//更新显示   
		}
	       if(KeyNum==11)
			{
			if(Password==5200){
			LCD_ShowString(1,14,"OK ");
			Password=0;
			count=0;		
			LCD_ShowNum(2,1,Password,4);
			P2_0=0;	
			}else{
			LCD_ShowString(1,14,"ERR");
			Password=0;
			count=0;		
			LCD_ShowNum(2,1,Password,4);				
			}
		    }
			if(KeyNum==12)
			{
			Password=0;
			count=0;
			LCD_ShowNum(2,1,Password,4);
			LCD_ShowString(1,14,"   ");	
			}	
	 }
   }   
 }
 
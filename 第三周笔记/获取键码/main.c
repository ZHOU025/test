#include <REGX52.H>
#include "LCD1602.h" 
#include "Delay.h"
#include "MatrixKey.h"

unsigned char Keynumber;
 void main()
 {	 LCD_Init();
	 LCD_ShowString(1,1,"MatrixKey:");LCD_ShowNum(2,1,Keynumber,2);
   while(1)
   {
	   
	   Keynumber=MatrixKey() ;
	   if(Keynumber)
	{
	       LCD_ShowNum(2,1,Keynumber,2);   
	 }
   }   
 }
 
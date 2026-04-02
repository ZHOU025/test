#include <REGX52.H>
#include <intrins.h>

#define MAXTASK 2//任务的多少
#define TASKDEEP 32//自定义堆栈的深度
static unsigned char  Task_Stack[MAXTASK][TASKDEEP];
static unsigned char  Task_SP[MAXTASK];
unsigned char Task_id;
sbit LED0=P2^5;
sbit LED1=P2^6;


void Task_Load(unsigned int fn,unsigned char tid);
void Task0(void);
void Task1(void);
void Task_Switch(void);
void Delay1000ms();
void Delay500ms();


void main()
{
	
	Task_Load((unsigned int)Task0,0);//初始化自定义的堆栈任务0
	Task_Load((unsigned int)Task1,1);//初始化自定义的堆栈任务1
	Task_id=0; 
	SP=(unsigned char) Task_SP[0]; //使得SP指针第一次指向任务0的栈顶
  //函数结束时可以自动RET，取出SP所指的堆栈的值
	while(1);
}	


void Task0()//任务零
{
	volatile bit run=1;
	while(run)
	{
	LED0=0;    
	Delay500ms();
	LED0=1;   	
	Task_Switch();//任务转换
	}	
}	

void Task1()
{
	volatile bit run=1;
	while(run)
	{	
	LED1=0;    
	Delay1000ms();
	LED1=1; 	
	Task_Switch();//任务切换
	}	
}	

void Task_Load(unsigned int fn,unsigned char tid)
{
	Task_Stack[tid][TASKDEEP-2]=(unsigned char)(fn&0xFF);//任务的低八位
	Task_Stack[tid][TASKDEEP-1]=(unsigned char)(fn>>8);//任务的高八位
	Task_SP[tid]=(unsigned char)&Task_Stack[tid][TASKDEEP-2];//给指针数组记录此时的任务的堆栈地址
}	

void Task_Switch()
{
	Task_SP[Task_id]=SP;//记录此时的SP的值，方便切换任务时返回此状态
	if(Task_id==0)
	{Task_id=1;}
	else {Task_id=0;}
	SP=Task_SP[Task_id];//切换任务
	_nop_();
	_nop_();
}


void Delay1000ms()		//@11.0592MHz
{
	static unsigned char i, j, k;

	_nop_();
	_nop_();
	i = 43;
	j = 6;
	k = 203;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}
void Delay500ms()		//@11.0592MHz
{
	static unsigned char i, j, k;

	_nop_();
	_nop_();
	i = 22;
	j = 3;
	k = 227;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}

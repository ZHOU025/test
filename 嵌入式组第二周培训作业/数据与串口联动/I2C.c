#include <REGX52.H>

sbit I2C_SCL=P2^1;
sbit I2C_SDA=P2^0;
/**
  * @brief  I2C开始
  * @param  无
  * @retval 无
  */
void I2C_Start(void)
	{ //当scl为一的前提是sda稳定，所以先置sda先为一
		
	I2C_SDA=1;
	I2C_SCL=1;
	I2C_SDA=0;
	I2C_SCL=0;

}	

/**
  * @brief I2C结束
  * @param  无
  * @retval 无
  */
void I2C_Stop(void)
{	
	I2C_SDA=0;	//因为SDA不确定为1或0，所以先置0
	I2C_SCL=1;
	I2C_SDA=1;

}	

/**
  * @brief I2C发送一个字节
  * @param  Byte 要发送的一个字节
  * @retval 无
  */
void I2C_SendByte(unsigned char Byte)
{
unsigned char i;
	
	for(i=0;i<8;i++)
	{//SDA不置一因为开始时已经置一
	I2C_SDA=Byte&(0x80>>i);
	I2C_SCL=1;
	I2C_SCL=0;	
	}
	
}	
/**
  * @brief I2C要接受的一个字节 
  * @param  无
  * @retval Byte 返回读到的字节
  */
unsigned char ReceiveByte(void)
{
	unsigned char i,Byte=0x00;
	I2C_SDA=1;//使得从位可以进行操作
	for(i=0;i<8;i++)
	{
	I2C_SCL=1;	
	if(I2C_SDA){Byte|=(0x80>>i);}//if语句用以读每一位的I2C_SDA的数据情况	
	I2C_SCL=0;
	}
	return Byte;
}
/**
  * @brief  I2C发送应答
* @param  AckBit 发送应答位，0为应答，1为非
  * @retval 无
  */
void I2C_SendAck(unsigned char AckBit)
{
	I2C_SDA=AckBit;
	I2C_SCL=1;
	I2C_SCL=0;
}	
/**
  * @brief  I2C接收应答
* @param  无
  * @retval AckBit 接收应答位，0为接收应答，1为非
  */
unsigned char I2C_ReceiveAck(void)
{	
	unsigned char AckBit;
	I2C_SDA=1;//让从位操纵
	I2C_SCL=1;
	AckBit=I2C_SDA;
	I2C_SCL=0;
	return AckBit;
}	





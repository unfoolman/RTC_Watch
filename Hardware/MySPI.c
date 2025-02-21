#include "stm32f10x.h"                  // Device header
#include "DELAY.H"

void MySPI_W_SS(uint8_t Bit)
{
	GPIO_WriteBit(GPIOA,GPIO_Pin_4,(BitAction)Bit);
}

void MySPI_W_CLK(uint8_t Bit)
{
	GPIO_WriteBit(GPIOA,GPIO_Pin_5,(BitAction)Bit);
}

void MySPI_W_MOSI(uint8_t Bit)
{
	GPIO_WriteBit(GPIOA,GPIO_Pin_7,(BitAction)Bit);
}

uint8_t MySPI_R_MISO(void)
{
	return GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_6);
}

void MySPI_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_7;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_6;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStruct);
	
	MySPI_W_SS(1);
	MySPI_W_CLK(0);
}

void MySPI_Start(void)
{
	MySPI_W_SS(0);
}

void MySPI_Stop(void)
{
	MySPI_W_SS(1);
}

uint8_t MySPI_SwapByte(uint8_t Byte)
{
	uint8_t i, ReceiveData = 0x00;
	
	for(i=0;i<8;i++)
	{
		MySPI_W_MOSI(Byte & (0x80>>i));
		MySPI_W_CLK(1);
		if(MySPI_R_MISO()==1){ReceiveData |= (0x80>>i);}
		MySPI_W_CLK(0);
	}
	
	return ReceiveData;
}

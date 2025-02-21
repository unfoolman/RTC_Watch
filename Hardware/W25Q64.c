#include "stm32f10x.h"                  // Device header
#include "MYSPI.H"
#include "W25Q64_Ins.H"

void W25Q64_Init(void)
{
	MySPI_Init();
}

void W25Q64_WriteEnable(void)
{
	MySPI_Start();
	MySPI_SwapByte(W25Q64_Write_Enable);
	MySPI_Stop();
}

void W25Q64_WaitBusy(void)
{
	MySPI_Start();
	MySPI_SwapByte(W25Q64_ReadStatue_Register_1);
	while((MySPI_SwapByte(W25Q64_Dummy) & 0x01)==0x01);
	MySPI_Stop();
}

void W25Q64_PageProgram(uint32_t RegAddress,uint8_t *DataArray,uint16_t Count)
{
	uint16_t i;
	W25Q64_WriteEnable();
	MySPI_Start();
	MySPI_SwapByte(W25Q64_Page_Program);
	MySPI_SwapByte(RegAddress>>16);
	MySPI_SwapByte(RegAddress>>8);
	MySPI_SwapByte(RegAddress);
	for(i=0;i<Count;i++)
	{
		MySPI_SwapByte(DataArray[i]);
	}
	MySPI_Stop();
	W25Q64_WaitBusy();
}

void W25Q64_SectorClear(uint32_t Address)
{
	W25Q64_WriteEnable();
	MySPI_Start();
	MySPI_SwapByte(W25Q64_Sector_Erase_4);
	MySPI_SwapByte(Address>>16);
	MySPI_SwapByte(Address>>8);
	MySPI_SwapByte(Address);
	MySPI_Stop();
	W25Q64_WaitBusy();
}

void W25Q64_RegRead(uint32_t RegAddress,uint8_t *DataArray,uint16_t Count)
{
	uint32_t i;
	MySPI_Start();
	MySPI_SwapByte(W25Q64_Read_Data);
	MySPI_SwapByte(RegAddress>>16);
	MySPI_SwapByte(RegAddress>>8);
	MySPI_SwapByte(RegAddress);
	for(i=0;i<Count;i++)
	{
		DataArray[i]=MySPI_SwapByte(W25Q64_Dummy);
	}
	MySPI_Stop();
}

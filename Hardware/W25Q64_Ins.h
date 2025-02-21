#ifndef __W25Q64_H__
#define __W25Q64_H__

#define	W25Q64_Write_Enable					0x06
#define	W25Q64_Write_Disable				0x04
#define	W25Q64_ReadStatue_Register_1		0x05
#define	W25Q64_ReadStatue_Register_2		0x35
#define	W25Q64_Write_Status_Register		0x01
#define	W25Q64_Page_Program					0x02
#define	W25Q64_Quad_Program					0x32
#define	W25Q64_Block_Erase_64				0xD8
#define	W25Q64_Block_Erase_32				0x52
#define	W25Q64_Sector_Erase_4				0x20
#define	W25Q64_Chip_Erase					0xC7
#define	W25Q64_Erase_Suspend				0x75
#define	W25Q64_Erase_Resume					0x7A
#define	W25Q64_Power_down					0x89
#define	W25Q64_High_Performance_Mode		0xA3
#define	W25Q64_Continuous_Read_Mode_Reset 	0xFF
#define	W25Q64_Release_Power_down_HPM_Device ID		0xAB
#define	W25Q64_Manufacturer_Device_ID		0x90
#define	W25Q64_Read_Unique_ID				0x4B

#define	W25Q64_JEDEC_ID						0x9F
#define	W25Q64_Read_Data					0x03

#define	W25Q64_Dummy						0xFF

#endif

#ifndef __W25Q64_H__
#define __W25Q64_H__

void W25Q64_Init(void);
void W25Q64_SectorClear(uint32_t Address);
void W25Q64_PageProgram(uint32_t RegAddress,uint8_t *DataArray,uint16_t Count);
void W25Q64_RegRead(uint32_t RegAddress,uint8_t *DataArray,uint16_t Count);

#endif

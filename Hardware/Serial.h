#ifndef __SERIAL_H__
#define __SERIAL_H__

extern uint8_t Serial_TxArray[];
extern uint8_t Serial_RxArray[];
extern uint8_t Serial_ReceiveFlag;

void Serial_Init(void);
void Serial_SendByte(uint8_t Byte);
void Serial_SendArray(uint8_t *Array,uint8_t Length);
void Serial_SendNum(uint16_t Data,uint16_t Length);
void Serial_SendPacket(void);
void Serial_SendString(char *String);

uint8_t USART_GetReceiveFlag(void);

#endif

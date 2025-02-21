#ifndef __MYRTC_H__
#define __MYRTC_H__

extern uint16_t MyTimeArray[];

void MyRTC_Init(void);
void MyRTC_SetTime(void);
void MyRTC_ReadTime(void);
//void MyTimeArray_InstallYearVaule(uint16_t *year,uint8_t Encoder_Number_Edge,uint16_t Encoder_Number, uint8_t state);

#endif

#include "stm32f10x.h"                  // Device header
#include <time.h>
#include "ENCODER.H"

int16_t MyTimeArray[] = {2025,2,18,22,32,55};


//---------------------------------------------------------------------------------------------------

void MyRTC_SetTime(void);

void MyRTC_Init(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR,ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_BKP,ENABLE);
	
	PWR_BackupAccessCmd(ENABLE);
	
	if(BKP_ReadBackupRegister(BKP_DR1) != 0xA5A5)
	{
		RCC_LSEConfig(RCC_LSE_ON);
		while (RCC_GetFlagStatus(RCC_FLAG_LSERDY)==RESET);
		
		RCC_RTCCLKConfig(RCC_RTCCLKSource_LSE);
		RCC_RTCCLKCmd(ENABLE);
		
		RTC_WaitForSynchro();
		RTC_WaitForLastTask();
		
		RTC_SetPrescaler(32768-1);
		RTC_WaitForLastTask();
		
		MyRTC_SetTime();
		RTC_WaitForLastTask();
		
		BKP_WriteBackupRegister(BKP_DR1,0xA5A5);
	}
}

void MyRTC_SetTime(void)
{
	time_t time_cnt;
	struct tm time_date;
	time_date.tm_year = MyTimeArray[0]-1900;
	time_date.tm_mon = MyTimeArray[1]-1;
	time_date.tm_mday = MyTimeArray[2];
	time_date.tm_hour = MyTimeArray[3];
	time_date.tm_min = MyTimeArray[4];
	time_date.tm_sec = MyTimeArray[5];
	
	time_cnt = mktime(&time_date);
	
	RTC_SetCounter(time_cnt);
	RTC_WaitForLastTask();
}

void MyRTC_ReadTime(void)
{
	time_t time_cnt;
	struct tm time_date;
	
	time_cnt = RTC_GetCounter();
	
	time_date = *localtime(&time_cnt);
	
	MyTimeArray[0] = time_date.tm_year+1900;
	MyTimeArray[1] = time_date.tm_mon+1;
	MyTimeArray[2] = time_date.tm_mday;
	MyTimeArray[3] = time_date.tm_hour;
	MyTimeArray[4] = time_date.tm_min;
	MyTimeArray[5] = time_date.tm_sec;
	
	RTC_WaitForLastTask();
}

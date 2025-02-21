#include "stm32f10x.h"                  // Device header
#include "MYRTC.H"

uint16_t RTC_Time_SetYearValue(int16_t Encoder_Number_Year,int16_t Encoder_Number_Edge_Year)
{
	uint16_t Temp_Year;
	
	if(Encoder_Number_Year != Encoder_Number_Edge_Year)		//这部分用来判断旋转编码的值是正转还是反转
	{
		if(Encoder_Number_Year > Encoder_Number_Edge_Year)
		{
			MyTimeArray[0] += Temp_Year;
		}
		else if(Encoder_Number_Year < Encoder_Number_Edge_Year)
		{
			MyTimeArray[0] -= Temp_Year;
		}
		Encoder_Number_Year = Encoder_Number_Edge_Year;
	}
	
	return MyTimeArray[0];
}

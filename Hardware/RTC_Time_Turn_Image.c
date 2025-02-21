#include "stm32f10x.h"                  // Device header
#include "MYRTC.H"
#include "OLED.H"
#include "OLED_DATA.H"

void RTC_Time_Turn_Image_Swap(void)
{
	switch(MyTimeArray[3]/10)								//时钟左一数
	{
		case 0:	
			OLED_ShowImage(11,15,22,26,Number_Zero_22X26);
			break;
		case 1:	
			OLED_ShowImage(11,15,22,26,Number_One_22X26);
			break;
		case 2:	
			OLED_ShowImage(11,15,22,26,Number_Two_22X26);
			break;
		case 3:	
			OLED_ShowImage(11,15,22,26,Number_Three_22X26);
			break;
		case 4:	
			OLED_ShowImage(11,15,22,26,Number_Four_22X26);
			break;
		case 5:	
			OLED_ShowImage(11,15,22,26,Number_Five_22X26);
			break;
		case 6:	
			OLED_ShowImage(11,15,22,26,Number_Six_22X26);
			break;
		case 7:	
			OLED_ShowImage(11,15,22,26,Number_Seven_22X26);
			break;
		case 8:	
			OLED_ShowImage(11,15,22,26,Number_Eigth_22X26);
			break;
		case 9:	
			OLED_ShowImage(11,15,22,26,Number_Nine_22X26);
			break;
	}
	
	
	switch(MyTimeArray[3]%10)								//时钟左二数
	{
		case 0:	
			OLED_ShowImage(35,15,22,26,Number_Zero_22X26);
			break;
		case 1:	
			OLED_ShowImage(35,15,22,26,Number_One_22X26);
			break;
		case 2:	
			OLED_ShowImage(35,15,22,26,Number_Two_22X26);
			break;
		case 3:	
			OLED_ShowImage(35,15,22,26,Number_Three_22X26);
			break;
		case 4:	
			OLED_ShowImage(35,15,22,26,Number_Four_22X26);
			break;
		case 5:	
			OLED_ShowImage(35,15,22,26,Number_Five_22X26);
			break;
		case 6:	
			OLED_ShowImage(35,15,22,26,Number_Six_22X26);
			break;
		case 7:	
			OLED_ShowImage(35,15,22,26,Number_Seven_22X26);
			break;
		case 8:	
			OLED_ShowImage(35,15,22,26,Number_Eigth_22X26);
			break;
		case 9:	
			OLED_ShowImage(35,15,22,26,Number_Nine_22X26);
			break;
	}

	
	
	switch(MyTimeArray[4]/10)								//分钟左一数
	{
		case 0:	
			OLED_ShowImage(72,15,22,26,Number_Zero_22X26);
			break;
		case 1:	
			OLED_ShowImage(72,15,22,26,Number_One_22X26);
			break;
		case 2:	
			OLED_ShowImage(72,15,22,26,Number_Two_22X26);
			break;
		case 3:	
			OLED_ShowImage(72,15,22,26,Number_Three_22X26);
			break;
		case 4:	
			OLED_ShowImage(72,15,22,26,Number_Four_22X26);
			break;
		case 5:	
			OLED_ShowImage(72,15,22,26,Number_Five_22X26);
			break;
		case 6:	
			OLED_ShowImage(72,15,22,26,Number_Six_22X26);
			break;
		case 7:	
			OLED_ShowImage(72,15,22,26,Number_Seven_22X26);
			break;
		case 8:	
			OLED_ShowImage(72,15,22,26,Number_Eigth_22X26);
			break;
		case 9:	
			OLED_ShowImage(72,15,22,26,Number_Nine_22X26);
			break;
	}
	
	
	switch(MyTimeArray[4]%10)								//分钟左二数
	{
		case 0:	
			OLED_ShowImage(96,15,22,26,Number_Zero_22X26);
			break;
		case 1:	
			OLED_ShowImage(96,15,22,26,Number_One_22X26);
			break;
		case 2:	
			OLED_ShowImage(96,15,22,26,Number_Two_22X26);
			break;
		case 3:	
			OLED_ShowImage(96,15,22,26,Number_Three_22X26);
			break;
		case 4:	
			OLED_ShowImage(96,15,22,26,Number_Four_22X26);
			break;
		case 5:	
			OLED_ShowImage(96,15,22,26,Number_Five_22X26);
			break;
		case 6:	
			OLED_ShowImage(96,15,22,26,Number_Six_22X26);
			break;
		case 7:	
			OLED_ShowImage(96,15,22,26,Number_Seven_22X26);
			break;
		case 8:	
			OLED_ShowImage(96,15,22,26,Number_Eigth_22X26);
			break;
		case 9:	
			OLED_ShowImage(96,15,22,26,Number_Nine_22X26);
			break;
	}

	
	switch(MyTimeArray[0]%100/10)									//年份左一数
	{
		case 0:	
			OLED_ShowImage(13,48,12,12,Number_Zero_12X12);
			break;
		case 1:	
			OLED_ShowImage(13,48,12,12,Number_One_12X12);
			break;
		case 2:	
			OLED_ShowImage(13,48,12,12,Number_Two_12X12);
			break;
		case 3:	
			OLED_ShowImage(13,48,12,12,Number_Three_12X12);
			break;
		case 4:	
			OLED_ShowImage(13,48,12,12,Number_Four_12X12);
			break;
		case 5:	
			OLED_ShowImage(13,48,12,12,Number_Five_12X12);
			break;
		case 6:	
			OLED_ShowImage(13,48,12,12,Number_Six_12X12);
			break;
		case 7:	
			OLED_ShowImage(13,48,12,12,Number_Seven_12X12);
			break;
		case 8:	
			OLED_ShowImage(13,48,12,12,Number_Eigth_12X12);
			break;
		case 9:	
			OLED_ShowImage(13,48,12,12,Number_Nine_12X12);
			break;
	}
	
	switch(MyTimeArray[0]%10)									//年份左二数
	{
		case 0:	
			OLED_ShowImage(27,48,12,12,Number_Zero_12X12);
			break;
		case 1:	
			OLED_ShowImage(27,48,12,12,Number_One_12X12);
			break;
		case 2:	
			OLED_ShowImage(27,48,12,12,Number_Two_12X12);
			break;
		case 3:	
			OLED_ShowImage(27,48,12,12,Number_Three_12X12);
			break;
		case 4:	
			OLED_ShowImage(27,48,12,12,Number_Four_12X12);
			break;
		case 5:	
			OLED_ShowImage(27,48,12,12,Number_Five_12X12);
			break;
		case 6:	
			OLED_ShowImage(27,48,12,12,Number_Six_12X12);
			break;
		case 7:	
			OLED_ShowImage(27,48,12,12,Number_Seven_12X12);
			break;
		case 8:	
			OLED_ShowImage(27,48,12,12,Number_Eigth_12X12);
			break;
		case 9:	
			OLED_ShowImage(27,48,12,12,Number_Nine_12X12);
			break;
	}

	
	switch(MyTimeArray[1]/10)									//月份左一数
	{
		case 0:	
			OLED_ShowImage(54,48,12,12,Number_Zero_12X12);
			break;
		case 1:	
			OLED_ShowImage(54,48,12,12,Number_One_12X12);
			break;
		case 2:	
			OLED_ShowImage(54,48,12,12,Number_Two_12X12);
			break;
		case 3:	
			OLED_ShowImage(54,48,12,12,Number_Three_12X12);
			break;
		case 4:	
			OLED_ShowImage(54,48,12,12,Number_Four_12X12);
			break;
		case 5:	
			OLED_ShowImage(54,48,12,12,Number_Five_12X12);
			break;
		case 6:	
			OLED_ShowImage(54,48,12,12,Number_Six_12X12);
			break;
		case 7:	
			OLED_ShowImage(54,48,12,12,Number_Seven_12X12);
			break;
		case 8:	
			OLED_ShowImage(54,48,12,12,Number_Eigth_12X12);
			break;
		case 9:	
			OLED_ShowImage(54,48,12,12,Number_Nine_12X12);
			break;
	}

	
	switch(MyTimeArray[1]%10)									//月份左二数
	{
		case 0:	
			OLED_ShowImage(68,48,12,12,Number_Zero_12X12);
			break;
		case 1:	
			OLED_ShowImage(68,48,12,12,Number_One_12X12);
			break;
		case 2:	
			OLED_ShowImage(68,48,12,12,Number_Two_12X12);
			break;
		case 3:	
			OLED_ShowImage(68,48,12,12,Number_Three_12X12);
			break;
		case 4:	
			OLED_ShowImage(68,48,12,12,Number_Four_12X12);
			break;
		case 5:	
			OLED_ShowImage(68,48,12,12,Number_Five_12X12);
			break;
		case 6:	
			OLED_ShowImage(68,48,12,12,Number_Six_12X12);
			break;
		case 7:	
			OLED_ShowImage(68,48,12,12,Number_Seven_12X12);
			break;
		case 8:	
			OLED_ShowImage(68,48,12,12,Number_Eigth_12X12);
			break;
		case 9:	
			OLED_ShowImage(68,48,12,12,Number_Nine_12X12);
			break;
	}

	
	switch(MyTimeArray[2]/10)									//日期左一数
	{
		case 0:	
			OLED_ShowImage(95,48,12,12,Number_Zero_12X12);
			break;
		case 1:	
			OLED_ShowImage(95,48,12,12,Number_One_12X12);
			break;
		case 2:	
			OLED_ShowImage(95,48,12,12,Number_Two_12X12);
			break;
		case 3:	
			OLED_ShowImage(95,48,12,12,Number_Three_12X12);
			break;
		case 4:	
			OLED_ShowImage(95,48,12,12,Number_Four_12X12);
			break;
		case 5:	
			OLED_ShowImage(95,48,12,12,Number_Five_12X12);
			break;
		case 6:	
			OLED_ShowImage(95,48,12,12,Number_Six_12X12);
			break;
		case 7:	
			OLED_ShowImage(95,48,12,12,Number_Seven_12X12);
			break;
		case 8:	
			OLED_ShowImage(95,48,12,12,Number_Eigth_12X12);
			break;
		case 9:	
			OLED_ShowImage(95,48,12,12,Number_Nine_12X12);
			break;
	}

	
	switch(MyTimeArray[2]%10)									//日期左二数
	{
		case 0:	
			OLED_ShowImage(109,48,12,12,Number_Zero_12X12);
			break;
		case 1:	
			OLED_ShowImage(109,48,12,12,Number_One_12X12);
			break;
		case 2:	
			OLED_ShowImage(109,48,12,12,Number_Two_12X12);
			break;
		case 3:	
			OLED_ShowImage(109,48,12,12,Number_Three_12X12);
			break;
		case 4:	
			OLED_ShowImage(109,48,12,12,Number_Four_12X12);
			break;
		case 5:	
			OLED_ShowImage(109,48,12,12,Number_Five_12X12);
			break;
		case 6:	
			OLED_ShowImage(109,48,12,12,Number_Six_12X12);
			break;
		case 7:	
			OLED_ShowImage(109,48,12,12,Number_Seven_12X12);
			break;
		case 8:	
			OLED_ShowImage(109,48,12,12,Number_Eigth_12X12);
			break;
		case 9:	
			OLED_ShowImage(109,48,12,12,Number_Nine_12X12);
			break;
	}
	
	switch(MyTimeArray[5]/10)									//秒钟左一数
	{
		case 0:	
			OLED_ShowImage(51,4,12,12,Number_Zero_12X12);
			break;
		case 1:	
			OLED_ShowImage(51,4,12,12,Number_One_12X12);
			break;
		case 2:	
			OLED_ShowImage(51,4,12,12,Number_Two_12X12);
			break;
		case 3:	
			OLED_ShowImage(51,4,12,12,Number_Three_12X12);
			break;
		case 4:	
			OLED_ShowImage(51,4,12,12,Number_Four_12X12);
			break;
		case 5:	
			OLED_ShowImage(51,4,12,12,Number_Five_12X12);
			break;
		case 6:	
			OLED_ShowImage(51,4,12,12,Number_Six_12X12);
			break;
		case 7:	
			OLED_ShowImage(51,4,12,12,Number_Seven_12X12);
			break;
		case 8:	
			OLED_ShowImage(51,4,12,12,Number_Eigth_12X12);
			break;
		case 9:	
			OLED_ShowImage(51,4,12,12,Number_Nine_12X12);
			break;
	}
	switch(MyTimeArray[5]%10)									//秒钟左二数
	{
		case 0:	
			OLED_ShowImage(65,4,12,12,Number_Zero_12X12);
			break;
		case 1:	
			OLED_ShowImage(65,4,12,12,Number_One_12X12);
			break;
		case 2:	
			OLED_ShowImage(65,4,12,12,Number_Two_12X12);
			break;
		case 3:	
			OLED_ShowImage(65,4,12,12,Number_Three_12X12);
			break;
		case 4:	
			OLED_ShowImage(65,4,12,12,Number_Four_12X12);
			break;
		case 5:	
			OLED_ShowImage(65,4,12,12,Number_Five_12X12);
			break;
		case 6:	
			OLED_ShowImage(65,4,12,12,Number_Six_12X12);
			break;
		case 7:	
			OLED_ShowImage(65,4,12,12,Number_Seven_12X12);
			break;
		case 8:	
			OLED_ShowImage(65,4,12,12,Number_Eigth_12X12);
			break;
		case 9:	
			OLED_ShowImage(65,4,12,12,Number_Nine_12X12);
			break;
	}

}

#include "stm32f10x.h"                  // Device header
#include "OLED.H"
#include "W25Q64.H"
#include "MPU6050.H"
#include "SERIAL.H"
#include "ENCODER.H"
#include "KEY.H"
#include "OLED_DATA.H"
#include "MYRTC.H"
#include "RTC_TIME_TURN_IMAGE.H"
#include "DELAY.H"

int8_t KeyN;
uint8_t KeyN_edge = 0;
uint8_t state_table0 = 0;		//控制页面的变换
uint8_t state_table1 = 1;		//控制副页面的选中
uint8_t state_table2 = 1;		//控制第三页面的选中
//uint8_t Array1[] = {0x01,0x02,0x03,0x04};
//uint8_t Array2[4];
int16_t Encoder_Number;
int16_t Encoder_Number_Year;
int16_t Encoder_Number_Edge;
int16_t Encoder_Number_Edge1;
int16_t Encoder_Number_Edge_Year;
int16_t ACCEL_X,ACCEL_Y,ACCEL_Z,GYRO_X,GYRO_Y,GYRO_Z;
int8_t Roll_table1 = 0;
uint8_t Roll_table1_add;
int8_t Roll_table2 = 0;
uint8_t Roll_table2_add;

int main(void)
{
	Key_Init();
	OLED_Init();
	W25Q64_Init();
	MPU6050_Init();
	Encoder_Init();
	MyRTC_Init();
	
	MyRTC_SetTime();
	
//	W25Q64_SectorClear(0xAAAA01);				//W25Q65在这里清理
	
//	W25Q64_PageProgram(0xAAAA01,Array1,4);		//W25Q64在这里开始存储数据
//	W25Q64_RegRead(0xAAAA01,Array2,4);			//W25Q64在这里读取数据	

	Encoder_Number_Edge = EncoderCount_Get();
	Encoder_Number_Edge1 = EncoderCount_Get();
	
	while (1)
	{
		Encoder_Number = EncoderCount_Get();
		MyRTC_ReadTime();
		KeyN = KeyN + Key_GetNum();
		MPU6050_GetValue(&ACCEL_X,&ACCEL_Y,&ACCEL_Z,&GYRO_X,&GYRO_Y,&GYRO_Z);
		
		if(KeyN <= 0)				//防止 KeyN 为负数
		{
			KeyN = 0;
		}
		else if(KeyN >= 2)			//防止 KeyN 超数
		{
			KeyN = 2;
		}
		
		if(KeyN == 0 && KeyN_edge == 0)			//利用 KeyN 的值的变化改变显示的页面
		{
			state_table0 = 0;
		}
		else if(KeyN == 1 && KeyN_edge != 1)
		{
			state_table0 = 1;
		}
		else if(KeyN == 2 && KeyN_edge != 2)
		{
			state_table0 = 2;
		}
		
		KeyN_edge = KeyN;		//保证 KeyN_edge 获取的值一直都是0，不会一直波动
	
		OLED_Clear();			//在显示页面之前，做清屏处理
		
		if(state_table0 == 0)						//当state_table0 = 0时，显示主页面
		{
			state_table1 = 1;
			Roll_table1 = 0;
			
			OLED_ShowImage(0,0,128,64,OLED_Table0);
			
			RTC_Time_Turn_Image_Swap();
			
			OLED_Update();
		}
		else if(state_table0 == 1)					//当state_table0 = 1时，显示副页面
		{
			
			OLED_ShowImage(0,0,128,64,OLED_Table1);	
			OLED_ShowChinese(3,3-Roll_table1,"图片");
			OLED_ShowChinese(3,36-Roll_table1,"时钟设置");
			OLED_ShowChinese(3,69-Roll_table1,"陀螺仪");
			OLED_ShowChinese(3,93-Roll_table1,"简介");
			
			if(state_table1 == 1)					//这部分显示 副页面 的反色状态
			{
				OLED_ReverseArea(2,(state_table1-1)*17+3,128,16);
				Roll_table1_add = 16;
			}
			else if(state_table1 == 2)
			{
				OLED_ReverseArea(2,(state_table1-1)*17+3,128,16);
				Roll_table1_add = 16;
			}
			else if(state_table1 == 3)
			{
				OLED_ReverseArea(2,(state_table1-1)*17+3,128,16);
				Roll_table1_add = 16;
			}
			else if(state_table1 == 4)
			{
				OLED_ReverseArea(2,45,128,16);
			}
			
			if(Encoder_Number != Encoder_Number_Edge)		//这部分用来判断旋转编码的值是正转还是反转
			{
				if(Encoder_Number > Encoder_Number_Edge)
				{
					state_table1++;
					Roll_table1 = Roll_table1 + 16;
				}
				else if(Encoder_Number < Encoder_Number_Edge)
				{
					state_table1--;
					Roll_table1 = Roll_table1 - 16;
				}
				Encoder_Number_Edge = Encoder_Number;
			}
			
			if(state_table1 >= 5)						//防止反色显示超格
			{
				state_table1 = 4;
			}
			else if(state_table1 <= 0)						//防止反色显示出格
			{
				state_table1 = 1;
			}
			
			if(Roll_table1 > 48)						//防止反色显示超格
			{
				Roll_table1 = 48;
			}
			else if(Roll_table1 < 0)						//防止反色显示出格
			{
				Roll_table1 = 0;
			}
			
		}
		
		if(state_table0 == 2 && state_table1 == 1 && KeyN == 2)		/*当 state_table0 = 2，且 state_table1 = 1时*/
		{															/*按下按键6，进入 state_table0_1 界面*/
//			Roll_table1 = 0;		//将滚动状态清除
			
			OLED_ShowImage(1,1,60,60,Ikun);
			OLED_Reverse();
		}
		else if(state_table0 == 2 && state_table1 == 2 && KeyN == 2)/*当 state_table0 = 2，且 state_table1 = 2时*/
		{                                                           /*按下按键6，进入 state_table0_2 界面*/
//			Roll_table1 = 0;		//将滚动状态清除
			
			OLED_ShowImage(0,0,128,64,OLED_Table1);	
			OLED_ShowChinese(3,3-Roll_table2,"年份：");
			OLED_ShowNum(53,3-Roll_table2,MyTimeArray[0],4,OLED_8X16);
			OLED_ShowChinese(3,20-Roll_table2,"月份：");
			OLED_ShowNum(53,20-Roll_table2,MyTimeArray[1],2,OLED_8X16);
			OLED_ShowChinese(3,36-Roll_table2,"日期：");
			OLED_ShowNum(53,36-Roll_table2,MyTimeArray[2],2,OLED_8X16);
			OLED_ShowChinese(3,52-Roll_table2,"时钟：");
			OLED_ShowNum(53,52-Roll_table2,MyTimeArray[3],2,OLED_8X16);
			OLED_ShowChinese(3,68-Roll_table2,"分钟：");
			OLED_ShowNum(53,68-Roll_table2,MyTimeArray[4],2,OLED_8X16);
			OLED_ShowChinese(3,84-Roll_table2,"秒钟：");
			OLED_ShowNum(53,84-Roll_table2,MyTimeArray[5],2,OLED_8X16);
			
			if(state_table0 == 2 && state_table1 == 2 && state_table2 == 1)				//这部分显示在 时钟设置 的反色状态
			{
				OLED_ReverseArea(2,(state_table2-1)*17+3,128,16);
			}
			else if(state_table0 == 2 && state_table1 == 2 && state_table2 == 2)
			{
				OLED_ReverseArea(2,(state_table2-1)*17+3,128,16);
				Roll_table2 = 0;
			}
			else if(state_table0 == 2 && state_table1 == 2 && state_table2 == 3)
			{
				OLED_ReverseArea(2,(state_table2-2)*17+3,128,16);
				Roll_table2 = 16;
			}
			else if(state_table0 == 2 && state_table1 == 2 && state_table2 == 4)
			{
				OLED_ReverseArea(2,(state_table2-3)*17+3,128,16);
				Roll_table2 = 32;
			}
			else if(state_table0 == 2 && state_table1 == 2 && state_table2 == 5)
			{
				OLED_ReverseArea(2,(state_table2-3)*17-3,128,16);
				Roll_table2 = 37;
			}
			else if(state_table0 == 2 && state_table1 == 2 && state_table2 == 6)
			{
				OLED_ReverseArea(2,(state_table2-3)*17-4,128,16);
			}
			
			if(Encoder_Number != Encoder_Number_Edge1)		//这部分用来判断旋转编码的值是正转还是反转
			{
				if(Encoder_Number > Encoder_Number_Edge1)
				{
					state_table2++;
				}
				else if(Encoder_Number < Encoder_Number_Edge1)
				{
					state_table2--;
				}
				Encoder_Number_Edge1 = Encoder_Number;
			}

			
			if(state_table2 >= 7)						//防止反色显示超格
			{
				state_table2 = 6;
			}
			else if(state_table2 <= 0)						//防止反色显示出格
			{
				state_table2 = 1;
			}
			
//			if(KeyN == 3 && state_table2 ==1)
//			{
//				MyTimeArray_InstallYearVaule(&MyTimeArray[0],Encoder_Number_Edge,Encoder_Number_Year, state_table2);
//			}
			
			
		}
		else if(state_table0 == 2 && state_table1 == 3 && KeyN == 2)/*当 state_table0 = 2，且 state_table1 = 3时*/
		{                                                           /*按下按键6，进入 state_table0_3 界面*/
//			Roll_table1 = 0;		//将滚动状态清除
			
			OLED_ShowString(1,16,"X:",OLED_8X16);
			OLED_ShowString(1,32,"Y:",OLED_8X16);
			OLED_ShowString(1,50,"Z:",OLED_8X16);
			OLED_ShowString(16,1,"ACCEL",OLED_8X16);
			OLED_ShowString(80,1,"GYRO:",OLED_8X16);
			OLED_ShowSignedNum(16,16,ACCEL_X,5,OLED_8X16);
			OLED_ShowSignedNum(16,32,ACCEL_Y,5,OLED_8X16);
			OLED_ShowSignedNum(16,50,ACCEL_Z,5,OLED_8X16);
			OLED_ShowSignedNum(80,16,GYRO_X,5,OLED_8X16);
			OLED_ShowSignedNum(80,32,GYRO_Y,5,OLED_8X16);
			OLED_ShowSignedNum(80,50,GYRO_Z,5,OLED_8X16);
		}
		else if(state_table0 == 2 && state_table1 == 4 && KeyN == 2)/*当 state_table0 = 2，且 state_table1 = 4时*/
		{                                                           /*按下按键6，进入 state_table0_4 界面*/
//			Roll_table1 = 0;		//将滚动状态清除
			
			OLED_ShowChinese(1,1,"这个工程师很懒，");
			OLED_ShowChinese(1,18,"什么都没写。");
		}
		


		OLED_Update();
	}
}



/**
  *  @brief 	MPU6050模块
  *  @param 	int16_t ACCEL_X,ACCEL_Y,ACCEL_Z,GYRO_X,GYRO_Y,GYRO_Z;
  *  @retval 	

  */

/*
		MPU6050_GetValue(&ACCEL_X,&ACCEL_Y,&ACCEL_Z,&GYRO_X,&GYRO_Y,&GYRO_Z);
		OLED_ShowSignedNum(1,1,ACCEL_X,5,OLED_6X8);
		OLED_ShowSignedNum(1,10,ACCEL_Y,5,OLED_6X8);
		OLED_ShowSignedNum(1,19,ACCEL_Z,5,OLED_6X8);
		OLED_ShowSignedNum(1,28,GYRO_X,5,OLED_6X8);
		OLED_ShowSignedNum(1,37,GYRO_Y,5,OLED_6X8);
		OLED_ShowSignedNum(1,46,GYRO_Z,5,OLED_6X8);
		OLED_Update();
*/		





/**
  *  @brief 	旋转编码器模块
  *  @param 	int16_t Encoder_Number;
  *  @retval 	
  */
  
/* 
		Encoder_Number = EncoderCount_Get();
		OLED_ShowSignedNum(1,1,Encoder_Number,3,OLED_6X8);
		OLED_Update();
*/
  
  
  

/**
  *  @brief 	W25Q64模块
  *  @param 	uint8_t Array1[] = {0x01,0x02,0x03,0xAA};
				uint8_t Array2[4];

  *  @retval 	
  */
/*
	W25Q64_SectorClear(0x666666);
	W25Q64_PageProgram(0x666666,Array1,4);
	W25Q64_RegRead(0x666666,Array2,4);
	
	OLED_ShowHexNum(1,1,Array2[0],2,OLED_6X8);
	OLED_ShowHexNum(1,10,Array2[1],2,OLED_6X8);
	OLED_ShowHexNum(1,19,Array2[2],2,OLED_6X8);
	OLED_ShowHexNum(1,28,Array2[3],2,OLED_6X8);
*/





/**
  *  @brief 	按键模块
  *  @param 	uint8_t KeyN;
  *  @retval 	
  */
  

/*		KeyN = Key_GetNum();
		
		if(KeyN)
		{
			Num++;
			OLED_ShowNum(1,1,Num,2,OLED_6X8);
			OLED_Update();
		}
*/



/**
  *  @brief 	RTC模块
  *  @param 	uint16_t Array3[6];
  *  @retval 	
  */

/*		MyRTC_SetTime();
		OLED_ShowImage(1,1,128,64,OLED_Table);
		
		OLED_Update();
			MyRTC_ReadTime();
*/	


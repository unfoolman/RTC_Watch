#ifndef __OLED_DATA_H
#define __OLED_DATA_H

#include <stdint.h>

/*中文字符字节宽度*/
#define OLED_CHN_CHAR_WIDTH			3		//UTF-8编码格式给3，GB2312编码格式给2

/*字模基本单元*/
typedef struct 
{
	char Index[OLED_CHN_CHAR_WIDTH + 1];	//汉字索引
	uint8_t Data[32];						//字模数据
} ChineseCell_t;

/*ASCII字模数据声明*/
extern const uint8_t OLED_F8x16[][16];
extern const uint8_t OLED_F6x8[][6];

/*汉字字模数据声明*/
extern const ChineseCell_t OLED_CF16x16[];

/*图像数据声明*/
extern const uint8_t Diode[];

extern const uint8_t Ikun[];

extern const uint8_t OLED_Table0[];
extern const uint8_t OLED_Table1[];


extern const uint8_t Number_Zero_22X26[];
extern const uint8_t Number_One_22X26[];
extern const uint8_t Number_Two_22X26[];
extern const uint8_t Number_Three_22X26[];
extern const uint8_t Number_Four_22X26[];
extern const uint8_t Number_Five_22X26[];
extern const uint8_t Number_Six_22X26[];
extern const uint8_t Number_Seven_22X26[];
extern const uint8_t Number_Eigth_22X26[];
extern const uint8_t Number_Nine_22X26[];

extern const uint8_t Number_Zero_12X12[];
extern const uint8_t Number_One_12X12[];
extern const uint8_t Number_Two_12X12[];
extern const uint8_t Number_Three_12X12[];
extern const uint8_t Number_Four_12X12[];
extern const uint8_t Number_Five_12X12[];
extern const uint8_t Number_Six_12X12[];
extern const uint8_t Number_Seven_12X12[];
extern const uint8_t Number_Eigth_12X12[];
extern const uint8_t Number_Nine_12X12[];

/*按照上面的格式，在这个位置加入新的图像数据声明*/
//...

#endif


/*****************江协科技|版权所有****************/
/*****************jiangxiekeji.com*****************/

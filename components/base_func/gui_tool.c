#include "gui_tool.h"
#include "lcd.h"
#include "font.h"
#include "picture.h"
#include <stdio.h>

void Gui_DrawLine(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint32_t Color);
void Gui_Circle(uint16_t X, uint16_t Y, uint16_t R, uint32_t fc);
void Gui_ShowChar(uint16_t x0, uint16_t y0, uint8_t chr, uint32_t fc);
void Gui_ShowString(uint16_t x0, uint16_t y0, uint8_t *chr, uint32_t fc);
BGUI_Tool BGUI_tool = {//BGUI_tool.ShowString(0,0,"hello world!",0xFFFF);
       
	.DrawLine = Gui_DrawLine,
	.Circle = Gui_Circle,
	.ShowChar = Gui_ShowChar,
	.ShowString = Gui_ShowString,

};

void Gui_Circle(uint16_t X, uint16_t Y, uint16_t R, uint32_t fc)
{ // Bresenham算法
	unsigned short a, b;
	int c;
	a = 0;
	b = R;
	c = 3 - 2 * R;
	while (a < b)
	{
		BG_SIM_Lcd.DrawPoint(X + a, Y + b, fc); //        7
		BG_SIM_Lcd.DrawPoint(X - a, Y + b, fc); //        6
		BG_SIM_Lcd.DrawPoint(X + a, Y - b, fc); //        2
		BG_SIM_Lcd.DrawPoint(X - a, Y - b, fc); //        3
		BG_SIM_Lcd.DrawPoint(X + b, Y + a, fc); //        8
		BG_SIM_Lcd.DrawPoint(X - b, Y + a, fc); //        5
		BG_SIM_Lcd.DrawPoint(X + b, Y - a, fc); //        1
		BG_SIM_Lcd.DrawPoint(X - b, Y - a, fc); //        4

		if (c < 0)
			c = c + 4 * a + 6;
		else
		{
			c = c + 4 * (a - b) + 10;
			b -= 1;
		}
		a += 1;
	}
	if (a == b)
	{
		BG_SIM_Lcd.DrawPoint(X + a, Y + b, fc);
		BG_SIM_Lcd.DrawPoint(X + a, Y + b, fc);
		BG_SIM_Lcd.DrawPoint(X + a, Y - b, fc);
		BG_SIM_Lcd.DrawPoint(X - a, Y - b, fc);
		BG_SIM_Lcd.DrawPoint(X + b, Y + a, fc);
		BG_SIM_Lcd.DrawPoint(X - b, Y + a, fc);
		BG_SIM_Lcd.DrawPoint(X + b, Y - a, fc);
		BG_SIM_Lcd.DrawPoint(X - b, Y - a, fc);
	}
}

//  //显示2个数字
// //x,y :起点坐标
// //len :数字的位数
// //size:字体大小
// //mode:模式	0,填充模式;1,叠加模式
// //num:数值(0~4294967295);
// void OLED_ShowNum(uint8_t x,uint8_t y,unsigned int num,uint8_t len,uint8_t size2)
// {
// 	uint8_t t,temp;
// 	uint8_t enshow=0;
// 	for(t=0;t<len;t++)
// 	{
// 		temp=(num/oled_pow(10,len-t-1))%10;
// 		if(enshow==0&&t<(len-1))
// 		{
// 			if(temp==0)
// 			{
// 				OLED_ShowChar(x+(size2/2)*t,y,' ',size2);
// 				continue;
// 			}else enshow=1;

// 		}
// 	 	OLED_ShowChar(x+(size2/2)*t,y,temp+'0',size2);
// 	}
// }

void Gui_ShowChar(uint16_t x0, uint16_t y0, uint8_t chr, uint32_t fc)
{

	unsigned char c = 0, i = 0,y;
	uint8_t ch;
	c = chr - ' '; // 得到偏移后的值
	if (x0 > LCD_WIDTH - 1)
	{
		x0 = 0;
		y0 = y0 + 16;
	}
	for (uint8_t w = 0; w < 8; w++)
	{	
		y=y0;
		//printf("in func %d\n",c);
		for (uint8_t h = 0; h < 8; h++)
		{
			ch = F8x16[c * 16 + w];
			//printf("ch is %d\n",ch);
			if ((ch>>h & 0x01) == 1)
			{
				BG_SIM_Lcd.DrawPoint(x0 + w, y, fc);
				//printf("drawpoint 1 %d %d \n", x0 + w,y); // 使用 %u 或 %d 来格式化 unsigned char
			}
			
			y++;
		}
	}
	 
	for (uint8_t w = 0; w < 8; w++)
	{
		y=y0+8;
		for (uint8_t h = 0; h < 8; h++)
		{
			ch= F8x16[c * 16 + w + 8];
			if ((ch>>h & 0x01) == 1)
			{
				BG_SIM_Lcd.DrawPoint(x0 + w, y, fc);
				//printf("drawpoint 2 %d %d \n", x0 + w,y); 
			}
			ch= ch >> 1;
			y++;
		}
	}
}
void Gui_ShowString(uint16_t x0, uint16_t y0, uint8_t *chr, uint32_t fc)
{
	unsigned char j = 0;
	while (chr[j] != '\0')
	{
		Gui_ShowChar(x0, y0, chr[j], fc);
		x0 += 8;
		if (x0 > LCD_WIDTH-8)
		{
			x0 = 0;
			y0 += 16;
		}
		j++;
	}
}

void Gui_DrawLine(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint32_t Color)
{
	int dx,	 // difference in x's
		dy,	 // difference in y's
		dx2, // dx,dy * 2
		dy2,
		x_inc, // amount in pixel space to move during drawing
		y_inc, // amount in pixel space to move during drawing
		error, // the discriminant i.e. error i.e. decision variable
		index; // used for looping

	dx = x1 - x0; // 计算x距离
	dy = y1 - y0; // 计算y距离

	if (dx >= 0)
	{
		x_inc = 1;
	}
	else
	{
		x_inc = -1;
		dx = -dx;
	}

	if (dy >= 0)
	{
		y_inc = 1;
	}
	else
	{
		y_inc = -1;
		dy = -dy;
	}

	dx2 = dx << 1;
	dy2 = dy << 1;

	if (dx > dy) // x距离大于y距离，那么每个x轴上只有一个点，每个y轴上有若干个点
	{			 // 且线的点数等于x距离，以x轴递增画点
		// initialize error term
		error = dy2 - dx;

		// draw the line
		for (index = 0; index <= dx; index++) // 要画的点数不会超过x距离
		{
			// 画点
			BG_SIM_Lcd.DrawPoint(x0, y0, Color);

			// test if error has overflowed
			if (error >= 0) // 是否需要增加y坐标值
			{
				error -= dx2;

				// move to next line
				y0 += y_inc; // 增加y坐标值
			} // end if error overflowed

			// adjust the error term
			error += dy2;

			// move to the next pixel
			x0 += x_inc; // x坐标值每次画点后都递增1
		} // end for
	} // end if |slope| <= 1
	else // y轴大于x轴，则每个y轴上只有一个点，x轴若干个点
	{	 // 以y轴为递增画点
		// initialize error term
		error = dx2 - dy;

		// draw the line
		for (index = 0; index <= dy; index++)
		{
			// set the pixel
			BG_SIM_Lcd.DrawPoint(x0, y0, Color);

			// test if error overflowed
			if (error >= 0)
			{
				error -= dy2;

				// move to next line
				x0 += x_inc;
			} // end if error overflowed

			// adjust the error term
			error += dx2;

			// move to the next pixel
			y0 += y_inc;
		} // end for
	} // end else |slope| > 1
}
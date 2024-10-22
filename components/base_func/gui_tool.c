#include "gui_tool.h"
#include "lcd.h"

void Gui_DrawLine(uint16_t x0, uint16_t y0,uint16_t x1, uint16_t y1,uint32_t Color);
void Gui_Circle(uint16_t X,uint16_t Y,uint16_t R,uint32_t fc);
BGUI_Tool BGUI_tool = {

    .DrawLine = Gui_DrawLine,
    .Circle = Gui_Circle,

};


void Gui_Circle(uint16_t X,uint16_t Y,uint16_t R,uint32_t fc) {//Bresenham算法 
    unsigned short  a,b; 
    int c; 
    a=0; 
    b=R; 
    c=3-2*R; 
    while (a<b) 
    { 
        BG_SIM_Lcd.DrawPoint(X+a,Y+b,fc);     //        7 
        BG_SIM_Lcd.DrawPoint(X-a,Y+b,fc);     //        6 
        BG_SIM_Lcd.DrawPoint(X+a,Y-b,fc);     //        2 
        BG_SIM_Lcd.DrawPoint(X-a,Y-b,fc);     //        3 
        BG_SIM_Lcd.DrawPoint(X+b,Y+a,fc);     //        8 
        BG_SIM_Lcd.DrawPoint(X-b,Y+a,fc);     //        5 
        BG_SIM_Lcd.DrawPoint(X+b,Y-a,fc);     //        1 
        BG_SIM_Lcd.DrawPoint(X-b,Y-a,fc);     //        4 

        if(c<0) c=c+4*a+6; 
        else 
        { 
            c=c+4*(a-b)+10; 
            b-=1; 
        } 
       a+=1; 
    } 
    if (a==b) 
    { 
        BG_SIM_Lcd.DrawPoint(X+a,Y+b,fc); 
        BG_SIM_Lcd.DrawPoint(X+a,Y+b,fc); 
        BG_SIM_Lcd.DrawPoint(X+a,Y-b,fc); 
        BG_SIM_Lcd.DrawPoint(X-a,Y-b,fc); 
        BG_SIM_Lcd.DrawPoint(X+b,Y+a,fc); 
        BG_SIM_Lcd.DrawPoint(X-b,Y+a,fc); 
        BG_SIM_Lcd.DrawPoint(X+b,Y-a,fc); 
        BG_SIM_Lcd.DrawPoint(X-b,Y-a,fc); 
    } 
	
}
void Gui_DrawLine(uint16_t x0, uint16_t y0,uint16_t x1, uint16_t y1,uint32_t Color){
int dx,             // difference in x's
    dy,             // difference in y's
    dx2,            // dx,dy * 2
    dy2, 
    x_inc,          // amount in pixel space to move during drawing
    y_inc,          // amount in pixel space to move during drawing
    error,          // the discriminant i.e. error i.e. decision variable
    index;          // used for looping	


	
	dx = x1-x0;//计算x距离
	dy = y1-y0;//计算y距离

	if (dx>=0)
	{
		x_inc = 1;
	}
	else
	{
		x_inc = -1;
		dx    = -dx;  
	} 
	
	if (dy>=0)
	{
		y_inc = 1;
	} 
	else
	{
		y_inc = -1;
		dy    = -dy; 
	} 

	dx2 = dx << 1;
	dy2 = dy << 1;

	if (dx > dy)//x距离大于y距离，那么每个x轴上只有一个点，每个y轴上有若干个点
	{//且线的点数等于x距离，以x轴递增画点
		// initialize error term
		error = dy2 - dx; 

		// draw the line
		for (index=0; index <= dx; index++)//要画的点数不会超过x距离
		{
			//画点
			BG_SIM_Lcd.DrawPoint(x0,y0,Color);
			
			// test if error has overflowed
			if (error >= 0) //是否需要增加y坐标值
			{
				error-=dx2;

				// move to next line
				y0+=y_inc;//增加y坐标值
			} // end if error overflowed

			// adjust the error term
			error+=dy2;

			// move to the next pixel
			x0+=x_inc;//x坐标值每次画点后都递增1
		} // end for
	} // end if |slope| <= 1
	else//y轴大于x轴，则每个y轴上只有一个点，x轴若干个点
	{//以y轴为递增画点
		// initialize error term
		error = dx2 - dy; 

		// draw the line
		for (index=0; index <= dy; index++)
		{
			// set the pixel
			BG_SIM_Lcd.DrawPoint(x0,y0,Color);

			// test if error overflowed
			if (error >= 0)
			{
				error-=dy2;

				// move to next line
				x0+=x_inc;
			} // end if error overflowed

			// adjust the error term
			error+=dx2;

			// move to the next pixel
			y0+=y_inc;
		} // end for
	} // end else |slope| > 1
}
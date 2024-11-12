#include <SDL2/SDL.h>
#include <stdio.h>
#include <termios.h>
#include <stdio.h>
#include <ev.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>
#include <stdint.h>
#include <signal.h>
#include "lcd.h"
#include "input_handle.h"
#include "gui_tool.h"
#include "picture.h"
#include "bg_list.h"

struct timeval start_time;
char keyinput;
uint8_t running=1; 
uint8_t key = 2;
void timer_handler(int signum)
{
 
        BG_SIM_Lcd.Loop(&running);
     
        BG_SIM_Lcd.Clear(0x000000);
        
      //  BG_SIM_Lcd.DrawPoint(64,80,0xFFFFFF);
        //BGUI_tool.ShowString(1,1,"hello world!",0xFF00FF);

       // BGUI_tool.ShowImage(16,16,40,40,gImage_qq);//= malloc(sizeof(BG_List));
        BG_List List;    
        List = BG_List_Init("main-UI");
        List.Append(&List.head,1,"one");
        List.Append(&List.head,5,"one5");
        List.Append(&List.head,2,"one2");
        List.Append(&List.head,3,"one3");
        List.Append(&List.head,4,"one4");
        List.Show(List.head);
        //BGUI_tool.ShowChar(0,0,'c',0xFFFFFF);
        if(key==0){
            
            BGUI_tool.Circle(64,80,20,0xFFFFFF);
            

        }

        if(key==1){
            
           BGUI_tool.DrawLine(10,10,60,60,0xFF);
           

        }
   
        
        BG_SIM_Lcd.Update();
         if(running==0){
            BG_SIM_Lcd.DeInit();
           
        }
        

}

void time_init()
{
    struct itimerval itv;
    itv.it_interval.tv_sec = 0;
    itv.it_interval.tv_usec = 1000;
    itv.it_value.tv_sec = 0;
    itv.it_value.tv_usec = 1000;

    signal(SIGALRM, timer_handler);
    setitimer(ITIMER_REAL, &itv, NULL);
    gettimeofday(&start_time, NULL);
}


int main(int argc, char* argv[]) {
    
    BG_input_handle.KeyBoardInit();
    BG_SIM_Lcd.Init("Point",0);
    
    time_init();
    
    while(1){
        
       
        keyinput =  BG_input_handle.KeyBoardLoop();
        if(keyinput == 99) key=0;
        if(keyinput==100) key=1;
        printf("data is %d\n",keyinput);
      

    }
 
}

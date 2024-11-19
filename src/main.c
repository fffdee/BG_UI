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
#include "bg_list.h"
#include "page_manager.h"

struct timeval start_time;
char keyinput;
uint8_t running = 1;
uint8_t key = 2;
BG_Page BG_page;

void timer_handler(int signum)
{

    BG_SIM_Lcd.Loop(&running);
    //BG_SIM_Lcd.Clear(0x000000);
    
    BG_page.Loop(&BG_page);
    if (key == 0)
    {
        
        List.Up(&List);
        printf("id is %d \n",List.Data.current_id);

        key=10;

    }

    if (key == 1)
    {
        
        List.Down(&List);
        printf("id is %d \n",List.Data.current_id);
 
        key=10;

    }

    if (key == 2)
    {
       
        List.Enter(&List);
        printf("id is %d \n",List.Data.current_id);
  
        key=10;

    }
   
    //BG_SIM_Lcd.Update();
   
    if (running == 0)
    {
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

int main(int argc, char *argv[])
{

    BG_input_handle.KeyBoardInit();
    BG_SIM_Lcd.Init("BanGUI_LCD", 0);
    BG_page  = BG_Page_Init(table,MAX_PAGE);

    time_init();

    while (1)
    {

        keyinput = BG_input_handle.KeyBoardLoop();
        if (keyinput == 115){
            key = 0;
   
        }
            
        if (keyinput == 119){
             key = 1;    
     
        }
        if (keyinput == 0){
             key = 2;    
     
        }
           
        printf("data is %d\n", keyinput);
    }
}

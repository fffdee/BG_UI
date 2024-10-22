#include <SDL2/SDL.h>
#include <stdio.h>
#include "lcd.h"

uint8_t running=1; 

int main(int argc, char* argv[]) {

      
    BG_SIM_Lcd.Init("hh",0);
    while(running){
        
        BG_SIM_Lcd.Loop(&running);
     
        BG_SIM_Lcd.Clear(0x000000);
        //SDL_Delay(100);
        BG_SIM_Lcd.DrawPoint(0xFFFFFF,64,80);

    }

   BG_SIM_Lcd.DeInit();
    return 0;
}

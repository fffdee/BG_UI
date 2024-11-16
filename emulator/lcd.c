#include "lcd.h"
#include <SDL2/SDL.h>
void LCD_Init(const char* name, uint8_t location);
void LCD_DeInit();
void LCD_Clear(uint32_t color);
void LCD_Update();
void LCD_DrawPoint(uint16_t x, uint16_t y, uint32_t color);
uint8_t LCD_Loop(uint8_t *running);

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
SDL_Event event; 


BG_SIM_LCD BG_SIM_Lcd = {

    .Init = LCD_Init,
    .DeInit = LCD_DeInit,
    .DrawPoint = LCD_DrawPoint,
    .Clear = LCD_Clear,
    .Update = LCD_Update,
    .Loop = LCD_Loop,
};

void LCD_Init(const char* name, uint8_t location){

 // 初始化SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not void LCD_Clear(uint32_t color);initialize! SDL_Error: %s\n", SDL_GetError());
       // return 1;
    }
    if(location==0){
    // 创建窗口
    window = SDL_CreateWindow(name,
                              SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED,
                              LCD_WIDTH,
                              LCD_HEIGHT,
                              SDL_WINDOW_SHOWN);
     }
    if(location==1){
    // 创建窗口void LCD_Clear(uint32_t color);
    window = SDL_CreateWindow(name,
                              SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED,
                              LCD_HEIGHT,
                              LCD_WIDTH,
                              SDL_WINDOW_SHOWN);
     }
    if (window == NULL) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        SDL_Quit();
        //return 1;
    }

    // 创建渲染器
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
       // return 1;
    }

}

uint8_t LCD_Loop(uint8_t* running){

       
       while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                *running = 0;
            }
        
        }
}

void LCD_DeInit(){

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    
}

void LCD_Clear(uint32_t color){

    uint8_t R,G,B;
    R = (color & 0x00FF0000) >> 16; 
    G = (color & 0x0000FF00) >> 8 ;
    B = color & 0x000000FF ;    

    // 设置渲染器颜色（黑色）
    SDL_SetRenderDrawColor(renderer, R, G, B, 255);
    // 清除渲染器（设置为黑色背景）
    SDL_RenderClear(renderer);
    // SDL_RenderPresent(renderer);
    
}

void LCD_DrawPoint(uint16_t x, uint16_t y, uint32_t color){

    uint8_t R,G,B;
    R = (color & 0x00FF0000) >> 16; 
    G = (color & 0x0000FF00) >> 8 ;
    B = color & 0x000000FF ;   
    // 设置渲染器颜色（黑色）
    SDL_SetRenderDrawColor(renderer, R, G, B, 255);
    SDL_RenderDrawPoint(renderer, x, y);
  //   SDL_RenderPresent(renderer);
    
}

void LCD_Update(){

     // 更新屏幕

    SDL_RenderPresent(renderer);
}
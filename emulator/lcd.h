#ifndef __LCD_H__
#define __LCD_H__

#include<stdint.h>

#define LCD_HEIGHT 240
#define LCD_WIDTH  320


typedef struct 
{
    void (*Init)(const char*,uint8_t);
    void (*DeInit)(void);
    void (*DrawPoint)(uint16_t,uint16_t,uint32_t);
    void (*Clear)(uint32_t);
    void (*Update)(void);
    uint8_t (*Loop)(uint8_t*);    

}BG_SIM_LCD;


extern BG_SIM_LCD BG_SIM_Lcd;



#endif
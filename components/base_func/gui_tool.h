#ifndef __GUI_TOOL_H__
#define __GUI_TOOL_H__

#include<stdint.h>
#include "lcd.h"
typedef struct 
{
    void (*Init)(void);
    void (*Clear)(uint32_t);
    void (*Update)(void);
    void (*DrawLine)(uint16_t, uint16_t,uint16_t, uint16_t,uint32_t);
    void (*Circle)(uint16_t,uint16_t,uint16_t,uint32_t);
    void (*ShowChar)(uint16_t, uint16_t, uint8_t, uint32_t);
    void (*ShowNum)(uint16_t, uint16_t, uint32_t, uint32_t);
    void (*ShowString)(uint16_t, uint16_t, uint8_t*,uint32_t);
    void (*ShowImage)(uint16_t, uint16_t, uint16_t, uint16_t, const uint8_t *);
    void (*DrawPoint)(uint16_t, uint16_t,uint32_t);
}BGUI_Tool;

extern BGUI_Tool BGUI_tool;


#endif
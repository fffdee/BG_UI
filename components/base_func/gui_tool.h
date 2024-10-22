#ifndef __GUI_TOOL_H__
#define __GUI_TOOL_H__

#include<stdint.h>

typedef struct gui_tool
{
    void (*DrawLine)(uint16_t, uint16_t,uint16_t, uint16_t,uint32_t);
    void (*Circle)(uint16_t,uint16_t,uint16_t,uint32_t);

}BGUI_Tool;

extern BGUI_Tool BGUI_tool;


#endif
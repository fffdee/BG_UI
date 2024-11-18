#ifndef __PAGE_H__
#define __PAGE_H__

#include <stdint.h>

#define MAX_ID 32

typedef enum{

    MAIN_PAGE=0,
    REFLESH_PAGE,
    
    


}BG_PAGE_CMD;

typedef struct 
{
    uint8_t last_id;
    uint8_t current_id;
    uint8_t next_id;
    uint8_t funcstion_cmd;
    void (*PageCmdHandle[MAX_ID])(uint8_t*);



}BG_Page_Data;


typedef struct 
{
    void (*Page_Scheduler)();
    void (*Page_Refresh)();
    void (*InputController)(uint8_t);
    void (*ReturnMainPage)(void);

}BG_Page;

extern BG_Page BG_page;

#endif



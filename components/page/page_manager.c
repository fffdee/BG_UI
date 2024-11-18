
#include "lcd.h"
#include "input_handle.h"
#include "gui_tool.h"
#include "picture.h"
#include "bg_list.h"
#include "page_manager.h"

BG_List List;

uint8_t data[9] = { 33 ,44 ,55 ,66, 77, 88, 99 ,100 ,111};
void home_page();
void list_page();
void list_page_in();

BG_Page_Table table[MAX_PAGE] = {

    {"home page",HOME_PAGE,LIST_PAGE,LIST_PAGE,HOME_PAGE,HOME_PAGE,home_page},
    {"list page",LIST_PAGE,HOME_PAGE,HOME_PAGE,LIST_PAGE_IN,LIST_PAGE,list_page},
    {"list page in",LIST_PAGE_IN,LIST_PAGE_IN,LIST_PAGE_IN,LIST_PAGE_IN,LIST_PAGE,list_page_in},

};



void home_page()
{

}

void list_page()
{

} 


void list_page_in()
{

        List.Timer_update(&List);
        List.Show(&List);
    
}

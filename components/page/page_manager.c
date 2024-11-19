
#include "lcd.h"
#include "input_handle.h"
#include "gui_tool.h"
#include "picture.h"
#include "bg_list.h"
#include "page_manager.h"

BG_List List;

uint8_t data[9] = {33, 44, 55, 66, 77, 88, 99, 100, 111};
void home_page();
void list_page();
void list_page_in();

BG_Page_Table table[MAX_PAGE] = {

    {"home page", HOME_PAGE, LIST_PAGE, LIST_PAGE, HOME_PAGE, HOME_PAGE, SETUP, home_page},
    {"list page", LIST_PAGE, HOME_PAGE, HOME_PAGE, LIST_PAGE_IN, LIST_PAGE, SETUP, list_page},
    {"list page in", LIST_PAGE_IN, LIST_PAGE_IN, LIST_PAGE_IN, LIST_PAGE_IN, LIST_PAGE, SETUP, list_page_in},

};

void home_page()
{
}

void list_page()
{
}

void list_page_in()
{

    if (BG_page.Data.table[BG_page.Data.running_id].setup == 1)
    {
        List = BG_List_Init("GUITAR", BG_SIM_Lcd.Update, BG_SIM_Lcd.Clear);
        List.Append(&List, "Dist", data[0], "val");
        List.Append(&List, "Delay", data[1], "km");
        List.Append(&List, "Chors", data[2], "m/s");
        List.Append(&List, "Reverb", data[3], "cc");
        List.Append(&List, "Pitch", data[4], "tt");
        List.Append(&List, "Change", data[5], "gg");
        List.Append(&List, "KKGO", data[6], "ff");
        List.Append(&List, "CS GO", data[7], "ie");
        List.Append(&List, "CF", data[8], "gogo");
    }

    List.Timer_update(&List);
    List.Show(&List);
}

#include "bg_page.h"

void BG_page_loop(BG_Page* page)
{   
    
    page->Data.table[page->Data.running_id].current_operation();
}

void BG_page_enter(BG_Page* page)
{
    page->Data.running_id = page->Data.table[page->Data.running_id].enter;
}

void BG_page_exit(BG_Page* page)
{
    page->Data.running_id = page->Data.table[page->Data.running_id].exit;
}

void BG_page_last(BG_Page* page)
{
    page->Data.running_id = page->Data.table[page->Data.running_id].up;
}

void BG_page_next(BG_Page* page)
{
    page->Data.running_id = page->Data.table[page->Data.running_id].down;
}

void BG_set_page(BG_Page* page,uint8_t id)
{
    page->Data.running_id = id;
}


BG_Page BG_Page_Init(BG_Page_Table *table, uint8_t size){

    BG_Page BG_page = {
        .Loop = BG_page_loop,
        .Enter = BG_page_enter,
        .Exit = BG_page_exit,
        .Last = BG_page_last,
        .Next = BG_page_next,
        .SetPage = BG_set_page,
        .Data.running_id = 2,     // home page ID
        .Data.max_id_count = size,
        .Data.table = table,
    };

    

    return BG_page;
}

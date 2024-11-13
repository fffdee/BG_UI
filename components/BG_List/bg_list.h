#ifndef _BG_LIST_H__
#define _BG_LIST_H__

#include<stdint.h>

#define FLASH_TIME 200
// 定义链表节点结构体
typedef struct Node {
    int data;
    int id;
    const char* name; 
    struct Node* next;
} Node;

typedef struct
{
    const char* title;
    uint8_t current_id;
    uint8_t max_id;
    uint8_t min_show_count;
    uint8_t max_show_count;
    uint8_t isEnter;
    uint8_t flash_flag;
    uint16_t flash_time; 
    uint16_t flash_run_time;
}BG_List_Data;

typedef struct BG_List{

    void (*Append)(struct BG_List*,const char*, uint16_t );
    void (*Delete)(Node**, int);
    void (*Show)(struct BG_List*);
    void (*Up)(struct BG_List*);
    void (*Down)(struct BG_List*);
    void (*Enter)(struct BG_List*);
    BG_List_Data Data; 
    Node* head;    

}BG_List;

BG_List BG_List_Init(const char * title);



#endif
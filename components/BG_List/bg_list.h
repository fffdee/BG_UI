#ifndef _BG_LIST_H__
#define _BG_LIST_H__

#include<stdint.h>

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

}BG_List_Data;

typedef struct{

    void (*Append)(Node**, int,const char*);
    void (*Delete)(Node**, int);
    void (*Show)(Node*,uint8_t,char* );
    void (*Up)(uint8_t*);
    void (*Down)(uint8_t*);
    BG_List_Data Data; 
    Node* head;   

}BG_List;

BG_List BG_List_Init(const char * title);



#endif
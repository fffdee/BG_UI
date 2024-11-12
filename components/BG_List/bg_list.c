#include "bg_list.h"
#include <stdio.h>
#include <stdlib.h>
#include "gui_tool.h"
#include "lcd.h"


// 创建一个新的节点
Node* createNode(int id,const char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        exit(EXIT_FAILURE); // 如果内存分配失败，退出程序
    }
    newNode->id = id;
    newNode->name = name;
    newNode->next = NULL;
    return newNode;
}

// 在链表末尾添加一个新节点
void appendNode(Node** head, int id,const char* name) {
    Node* newNode = createNode(id,name);
    if (*head == NULL) {
        *head = newNode;
        return;
    }   
    Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

// 删除具有特定值的节点
void deleteNode(Node** head, int key) {
    Node* temp = *head, *prev = NULL;
    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return;
    prev->next = temp->next;
    free(temp);
}

// 查找具有特定值的节点
Node* searchNode(Node* head, int key) {
    Node* current = head;
    while (current != NULL) {
        if (current->id == key) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// 修改链表中节点的数据
void updateNode(Node* head, int oldData, int newData) {
    Node* current = searchNode(head, oldData);
    if (current != NULL) {
        current->data = newData;
    }
}

void List_select(uint8_t id){

    for(uint16_t x=0; x<LCD_WIDTH-5;x++)
    {
        for(uint16_t y=0; y<16;y++){
            BG_SIM_Lcd.DrawPoint(x,y+id*16,0xFFFFFF);
        }
    }
}
// 打印链表
void printList(Node* node,uint8_t id,char* title) {
    
    BGUI_tool.DrawLine(0,0,LCD_WIDTH,0,0xFFFFFF);
    BGUI_tool.DrawLine(0,0,0,16,0xFFFFFF);
    BGUI_tool.ShowString(LCD_WIDTH/2-(sizeof(title)-2)*4,1,title,0xFFFFFF);
    BGUI_tool.DrawLine(0,16,LCD_WIDTH,16,0xFFFFFF);
    BGUI_tool.DrawLine(LCD_WIDTH-1,0,LCD_WIDTH-1,16,0xFFFFFF);
    while (node != NULL) {

        
        if(id==node->id){
              List_select(id);
              BGUI_tool.ShowString(5,node->id*16,node->name,0x00);
             // printf("ok");
        }else{
              BGUI_tool.ShowString(5,node->id*16,node->name,0xffffff);
              // printf("err");
        }
      
        BGUI_tool.DrawLine(0,(node->id)*16,0,(node->id+1)*16,0xFFFFFF);
        BGUI_tool.DrawLine(0,(node->id+1)*16,LCD_WIDTH-5,(node->id+1)*16,0xFFFFFF);
        BGUI_tool.DrawLine(LCD_WIDTH-4,(node->id)*16,LCD_WIDTH-4,(node->id+1)*16,0xFFFFFF);
        BGUI_tool.DrawLine(LCD_WIDTH-1,(node->id)*16,LCD_WIDTH-1,(node->id+1)*16,0xFFFFFF);
        node = node->next;

    }

}

// 释放链表内存
void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}
void Select_up(uint8_t *id)
{
    *id++;
 
}

void Select_down(uint8_t *id)
{
    *id--;
}

BG_List BG_List_Init(const char * title)
{
    BG_List BG_list = {

        .Append = appendNode,
        .Delete = deleteNode,
        .Show = printList,
        .Up   = Select_up,
        .Down = Select_down,
       
    };

    BG_list.Data.title = title;
    BG_list.Data.current_id = 4;
    BG_list.head = NULL;
 


    return BG_list;
}
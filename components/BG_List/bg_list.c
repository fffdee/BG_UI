#include "bg_list.h"
#include <stdio.h>
#include <stdlib.h>
#include "gui_tool.h"
#include "lcd.h"

// 创建一个新的节点
Node *createNode(int id, const char *name, uint16_t data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        exit(EXIT_FAILURE); // 如果内存分配失败，退出程序
    }
    newNode->id = id;
    newNode->data = data;
    newNode->name = name;
    newNode->next = NULL;
    return newNode;
}

void appendNode(BG_List *list, const char *name, uint16_t data)
{
    // 创建新节点
    Node *newNode = createNode(list->Data.max_id + 1, name, data);

    // 如果链表为空，则新节点成为头节点
    if (list->head == NULL)
    {
        list->head = newNode;
    }
    else
    {
        // 遍历链表到末尾
        Node *current = list->head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        // 将新节点添加到链表末尾
        current->next = newNode;
    }

    // 更新链表的最大id
    list->Data.max_id = newNode->id;
}

// 删除具有特定值的节点
void deleteNode(Node **head, int key)
{
    Node *temp = *head, *prev = NULL;
    if (temp != NULL && temp->data == key)
    {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        return;
    prev->next = temp->next;
    free(temp);
}

// 查找具有特定值的节点
Node *searchNode(Node *head, int key)
{
    Node *current = head;
    while (current != NULL)
    {
        if (current->id == key)
        {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// 修改链表中节点的数据
void updateNode(Node *head, int oldData, int newData)
{
    Node *current = searchNode(head, oldData);
    if (current != NULL)
    {
        current->data = newData;
    }
}

void List_select(uint8_t id, uint8_t min_count)
{

    for (uint16_t x = 0; x < LCD_WIDTH - 5; x++)
    {
        for (uint16_t y = 0; y < 16; y++)
        {
            BG_SIM_Lcd.DrawPoint(x, y + (id - min_count) * 16, 0xFFFFFF);
        }
    }
}
void ShowList(BG_List *list)
{
    if (list == NULL || list->head == NULL)
    {
        printf("list is NULL or list->head is NULL");
        return;
    }

    BGUI_tool.DrawLine(0, 0, LCD_WIDTH, 0, 0xFFFFFF);
    BGUI_tool.DrawLine(0, 0, 0, 16, 0xFFFFFF);
    BGUI_tool.ShowString(LCD_WIDTH / 2 - (sizeof(list->Data.title) - 2) * 4, 1, (uint8_t *)list->Data.title, 0xFFFFFF);
    BGUI_tool.DrawLine(0, 16, LCD_WIDTH, 16, 0xFFFFFF);
    BGUI_tool.DrawLine(LCD_WIDTH - 1, 0, LCD_WIDTH -1, 16, 0xFFFFFF);

    Node *current = list->head; // 使用临时指针来遍历链表
    while (current != NULL)
    {
        if (current->id - list->Data.min_show_count > 0)
        {
            if (list->Data.current_id == current->id)
            {
                List_select(list->Data.current_id, list->Data.min_show_count);
                BGUI_tool.ShowString(5, (current->id - list->Data.min_show_count) * 16, (uint8_t *)current->name, 0x00);
            }
            else
            {
                BGUI_tool.ShowString(5, (current->id - list->Data.min_show_count) * 16, (uint8_t *)current->name, 0xffffff);
            }
        }
       // printf("Data.min_show_count = %d\n", list->Data.min_show_count);
        BGUI_tool.DrawLine(0, (current->id) * 16, 0, (current->id + 1) * 16, 0xFFFFFF);
        BGUI_tool.DrawLine(0, (current->id + 1 - list->Data.min_show_count) * 16, LCD_WIDTH -LCD_WIDTH/40-1, (current->id + 1 - list->Data.min_show_count) * 16, 0xFFFFFF);
        BGUI_tool.DrawLine(LCD_WIDTH - LCD_WIDTH/40-1, (current->id) * 16, LCD_WIDTH -LCD_WIDTH/40-1, (current->id + 1) * 16, 0xFFFFFF);
        BGUI_tool.DrawLine(LCD_WIDTH - 1, (current->id) * 16, LCD_WIDTH - 1, (current->id + 1) * 16, 0xFFFFFF);
        for(uint8_t count=0;count<LCD_WIDTH/40;count++){
               if((list->Data.min_show_count+list->Data.max_show_count)==list->Data.max_id){
                    BGUI_tool.DrawLine(LCD_WIDTH - count-2
                , (list->Data.min_show_count%list->Data.max_show_count) * (LCD_HEIGHT-16)/7 +16, LCD_WIDTH - count-2
                , list->Data.max_id * (LCD_HEIGHT-16)/list->Data.max_id+16 
                , 0xFFFFFF);
               }
               else{
                BGUI_tool.DrawLine(LCD_WIDTH - count-2
                , (list->Data.min_show_count%list->Data.max_show_count) * (LCD_HEIGHT-16)/7 +16, LCD_WIDTH - count-2
                , ((list->Data.min_show_count+list->Data.max_show_count)%list->Data.max_id) * (LCD_HEIGHT-16)/list->Data.max_id+16 
                , 0xFFFFFF);
               }
        }
     
        // BGUI_tool.DrawLine(LCD_WIDTH - 3, (current->id) * 16, LCD_WIDTH - 3, (current->id + 1) * 16, 0xFFFFFF);
        current = current->next; // 移动到下一个节点
    }
}

// 释放链表内存
void freeList(Node *head)
{
    Node *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}
void Select_up(BG_List *list)
{

    if (list->Data.current_id == list->Data.max_id)
    {
        list->Data.current_id = 1;
    }
    else
    {
        list->Data.current_id += 1;
    }
    if (list->Data.current_id <= list->Data.max_show_count)
    {
        list->Data.min_show_count = 0;
    }
    else
    {
        list->Data.min_show_count = list->Data.current_id - list->Data.max_show_count;
    }
}

void Select_down(BG_List *list)
{

    if (list->Data.current_id <= 1)
    {
        list->Data.current_id = list->Data.max_id;
    }
    else
    {
        list->Data.current_id -= 1;
    }
    if (list->Data.current_id <= list->Data.max_show_count)
    {
        list->Data.min_show_count = 0;
    }
    else
    {
        list->Data.min_show_count = list->Data.current_id - list->Data.max_show_count;
    }
}

BG_List BG_List_Init(const char *title)
{
    BG_List BG_list = {

        .Append = appendNode,
        .Delete = deleteNode,
        .Show = ShowList,
        .Up = Select_up,
        .Down = Select_down,

    };

    BG_list.Data.title = title;
    BG_list.Data.current_id = 4;
    BG_list.Data.max_show_count = LCD_HEIGHT / 16 - 1;
    if (BG_list.Data.current_id <= BG_list.Data.max_show_count)
    {
        BG_list.Data.min_show_count = 0;
    }
    else
    {
        BG_list.Data.min_show_count = BG_list.Data.current_id - BG_list.Data.max_show_count;
    }

    BG_list.head = NULL;

    return BG_list;
}
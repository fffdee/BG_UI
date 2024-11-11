#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构体
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// 创建一个新的节点
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        exit(EXIT_FAILURE); // 如果内存分配失败，退出程序
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// 在链表末尾添加一个新节点
void appendNode(Node** head, int data) {
    Node* newNode = createNode(data);
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
        if (current->data == key) {
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

// 打印链表
void printList(Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
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

int main() {
    Node* head = NULL;

    // 添加节点
    appendNode(&head, 1);
    appendNode(&head, 2);
    appendNode(&head, 3);
    appendNode(&head, 4);

    // 打印链表
    printf("Initial list: ");
    printList(head);

    // 删除节点
    deleteNode(&head, 3);
    printf("List after deleting 3: ");
    printList(head);

    // 查找节点
    Node* foundNode = searchNode(head, 2);
    if (foundNode != NULL) {
        printf("Node with data 2 found.\n");
    } else {
        printf("Node with data 2 not found.\n");
    }

    // 修改节点
    updateNode(head, 2, 5);
    printf("List after updating 2 to 5: ");
    printList(head);

    // 释放链表内存
    freeList(head);
    return 0;
}

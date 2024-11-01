#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct HashTableEntry {
    int key;
    Node* node;
    struct HashTableEntry* next;
} HashTableEntry;

#define TABLE_SIZE 10

HashTableEntry* hashTable[TABLE_SIZE];

unsigned int hashFunction(int key) {
    return key % TABLE_SIZE;
}

void initHashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = NULL;
    }
}

void insertHashTable(int key, Node* node) {
    unsigned int index = hashFunction(key);
    HashTableEntry* newEntry = (HashTableEntry*)malloc(sizeof(HashTableEntry));
    newEntry->key = key;
    newEntry->node = node;
    newEntry->next = hashTable[index]; // Insert at the beginning of the list
    hashTable[index] = newEntry;
}

void deleteHashTable(int key) {
    unsigned int index = hashFunction(key);
    HashTableEntry* entry = hashTable[index];
    HashTableEntry* prev = NULL;
    while (entry != NULL && entry->key != key) {
        prev = entry;
        entry = entry->next;
    }
    if (entry == NULL) return; // Key not found
    if (prev == NULL) {
        hashTable[index] = entry->next;
    } else {
        prev->next = entry->next;
    }
    free(entry);
}

Node* searchHashTable(int key) {
    unsigned int index = hashFunction(key);
    HashTableEntry* entry = hashTable[index];
    while (entry != NULL) {
        if (entry->key == key) {
            return entry->node;
        }
        entry = entry->next;
    }
    return NULL; // Key not found
}

void appendNode(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
    insertHashTable(data, newNode);
}

void deleteNode(Node** head, int data) {
    Node* temp = *head, *prev = NULL;
    if (temp != NULL && temp->data == data) {
        *head = temp->next;
        deleteHashTable(data);
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return; // Data not found
    prev->next = temp->next;
    deleteHashTable(data);
    free(temp);
}

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void freeHashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        HashTableEntry* entry = hashTable[i];
        while (entry != NULL) {
            HashTableEntry* temp = entry;
            entry = entry->next;
            free(temp);
        }
    }
}

int main() {
    Node* head = NULL;
    initHashTable();

    appendNode(&head, 10);
    appendNode(&head, 20);
    appendNode(&head, 30);
    appendNode(&head, 40);
    appendNode(&head, 50);

    printf("Created Linked list is: ");
    printList(head);

    Node* foundNode = searchHashTable(30);
    if (foundNode != NULL) {
        printf("Node with data 30 found.\n");
    } else {
        printf("Node with data 30 not found.\n");
    }

    deleteNode(&head, 20);
    printf("Linked List after Deletion of 20: ");
    printList(head);

    // Free the linked list
    Node* current = head;
    Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    // Free the hash table
    freeHashTable();

    return 0;
}

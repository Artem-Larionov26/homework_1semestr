#pragma once

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct SortedList {
    Node* head;
} SortedList;

// Initialize an empty list
SortedList* initList();

// Function that adds an item while maintaining sorting
void insertSorted(SortedList* list, int value);

// Function that deletes the value
int deleteValue(SortedList* list, int value);

// Function that prints the list
void printList(SortedList* list);

// Function that frees up the memory of a list
void freeList(SortedList* list);
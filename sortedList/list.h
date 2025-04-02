#pragma once

#include <stdbool.h>

typedef struct Node Node;

typedef struct SortedList SortedList;

// Initialize an empty list
SortedList* initList(void);

// Function that adds an item while maintaining sorting
int insertSorted(SortedList* list, int value);

// Function that deletes the value
bool deleteValue(SortedList* list, int value);

// Function that prints the list
void printList(SortedList* list);

// Function that frees up the memory of a list
void freeList(SortedList** list);
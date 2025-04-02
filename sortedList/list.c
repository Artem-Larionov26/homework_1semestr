#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct SortedList {
    Node* head;
} SortedList;

SortedList* initList(void) {
    return calloc(1, sizeof(SortedList));
}

int insertSorted(SortedList* list, int value) {
    Node* newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        return 1;
    }
    newNode->data = value;
    if (list->head == NULL || list->head->data >= value) {
        newNode->next = list->head;
        list->head = newNode;
        return 0;
    }
    Node* current = list->head;
    while (current->next != NULL && current->next->data < value) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
    return 0;
}

bool deleteValue(SortedList* list, int value) {
    if (list->head == NULL) {
        return false;
    }
    Node* current = list->head;
    if (current->data == value) {
        list->head = current->next;
        free(current);
        return true;
    }
    while (current->next != NULL && current->next->data < value) {
        current = current->next;
    }
    if (current->next == NULL || current->next->data > value) {
            return false;
    }
    Node* temp = current->next;
    current->next = temp->next;
    free(temp);
    return true;
}

void printList(SortedList* list) {
    if (list->head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node* current = list->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void freeList(SortedList** list) {
    Node* current = (*list)->head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    free(*list);
    *list == NULL;
}
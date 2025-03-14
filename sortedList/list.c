#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

SortedList* initList() {
    SortedList* list = malloc(sizeof(SortedList));
    if (list == NULL) {
        printf("Memory allocation error!\n");
        return NULL;
    }
    list->head = NULL;
    return list;
}

void insertSorted(SortedList* list, int value) {
    Node* newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation error!\n");
        return;
    }
    newNode->data = value;
    if (list->head == NULL || list->head->data >= value) {
        newNode->next = list->head;
        list->head = newNode;
        return;
    }

    Node* current = list->head;
    while (current->next != NULL && current->next->data < value) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
}

int deleteValue(SortedList* list, int value) {
    if (list->head == NULL) {
        printf("List is empty!\n");
        return 0;
    }
    Node* current = list->head;
    if (current->data == value) {
        list->head = current->next;
        free(current);
        return 1;
    }
    while (current->next != NULL && current->next->data != value) {
        current = current->next;
    }
    if (current->next == NULL) {
        printf("Value not found!\n")
        return 0;
    }
    Node* temp = current->next;
    current->next = temp->next;
    free(temp);
    return 1;
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

void freeList(SortedList* list) {
    Node* current = list->head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    free(list);
}
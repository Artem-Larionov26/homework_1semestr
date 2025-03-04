#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include "list.h"

typedef struct ListElement {
    char name[50];
    char phone[20];
    ListElement* next;
}ListElement;

typedef struct List {
    ListElement* head;
    ListElement* tail;
    int size;
}List;

List* createList(int* errorCode) {
    List* list = malloc(sizeof(List));
    ListElement* head = calloc(1, sizeof(ListElement));
    ListElement* tail = calloc(1, sizeof(ListElement));
    if (list == NULL || head == NULL || tail == NULL) {
        *errorCode = 1;
        return NULL;
    }
    list->head = head;
    list->head->next = NULL;
    list->tail = head;
    list->tail->next = NULL;
    list->size = 0;
    return list;
}

int addContact(List* list, Position position, char* name, char* phone, int* errorCode) {
    ListElement* element = malloc(sizeof(ListElement));
    if (element == NULL) {
        *errorCode = 1;
        return 0;
    }
    strcpy_s(element->name, 50, name);
    strcpy_s(element->phone, 20, phone);
    if (position != NULL) {
        element->next = position->next;
        position->next = element;
        if (list->size == 0) {
            list->tail = element;
            list->head->next = element;
        }
        ++list->size;
    }
}

Position firstElement(List* list) {
    return list->head;
}

void addInHead(List* list, char* name, char* phone, int* errorCode) {
    addContact(list, firstElement(list), name, phone, errorCode);
}

void addInTail(List* list, char* name, char* phone, int* errorCode) {
    Position position = list->tail;
    addContact(list, position, name, phone, &errorCode);
    list->tail = next(position);
}

void deleteElement(List* list, Position position) {
    if (position != NULL && position->next != NULL) {
        ListElement* tmp = position->next;
        position->next = position->next->next;
        free(tmp);
        tmp = NULL;
        --list->size;
    }
}

Position getElement(List* list, int index) {
    ListElement* indexElement = list->head;
    for (int i = 0; i < index; i++) {
        if (indexElement->next != NULL) {
            indexElement = indexElement->next;
        }
        else {
            break;
        }
    }
    return indexElement;
}

void getNameAndPhone(List* list, Position position, char* name, char* phone, int* errorCode) {
    if (position == NULL || position->next == NULL) {
        *errorCode = 1;
        return NULL;
    }
    strcpy_s(name, 50, position->next->name);
    strcpy_s(phone, 20, position->next->phone);
}

Value getSizeList(List* list) {
    return list->size;
}

bool isLast(List* list, Position position) {
    return position->next == NULL;
}

bool isValid(List* list, Position position) {
    return position != NULL;
}

bool isEmpty(List* list) {
    return list->head->next == NULL;
}

Position next(Position position) {
    return position->next;
}

void deleteList(List* list) {
    while (list->head->next != NULL) {
        deleteElement(list, firstElement(list));
    }
    free(list->head);
    free(list);
    list = NULL;
}
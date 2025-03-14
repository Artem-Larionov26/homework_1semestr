#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "list.h"
#include "testsList.h"

bool testInitList() {
    SortedList* list = initList();
    bool isValid = (list != NULL && list->head == NULL);
    freeList(list);
    if (!isValid) {
        printf("Error: testInitList failed!\n");
    }
    return isValid;
}

bool testSingleInsert() {
    SortedList* list = initList();
    insertSorted(list, 42);
    bool isValid = (list->head != NULL && list->head->data == 42 && list->head->next == NULL);
    freeList(list);
    if (!isValid) printf("Error: testSingleInsert failed!\n");
    return isValid;
}

bool testSortedInsert() {
    SortedList* list = initList();
    insertSorted(list, 3);
    insertSorted(list, 1);
    insertSorted(list, 4);
    insertSorted(list, 2);
    bool isValid = (list->head->data == 1 &&
        list->head->next->data == 2 &&
        list->head->next->next->data == 3 &&
        list->head->next->next->next->data == 4 &&
        list->head->next->next->next->next == NULL);
    freeList(list);
    if (!isValid) printf("Error: testSortedInsert failed!\n");
    return isValid;
}

bool testDeleteExisting() {
    SortedList* list = initList();
    insertSorted(list, 1);
    insertSorted(list, 2);
    insertSorted(list, 3);
    int removed = deleteValue(list, 2);
    bool isValid = (removed == 1 &&
        list->head->data == 1 &&
        list->head->next->data == 3 &&
        list->head->next->next == NULL);
    freeList(list);
    if (!isValid) printf("Error: testRemoveExisting failed!\n");
    return isValid;
}

bool testDeleteFromEmpty() {
    SortedList* list = initList();
    int removed = deleteValue(list, 5);
    bool isValid = (removed == 0 && list->head == NULL);
    freeList(list);
    if (!isValid) printf("Error: testRemoveFromEmpty failed!\n");
    return isValid;
}

bool testAccessElement() {
    SortedList* list = initList();
    insertSorted(list, 10);
    insertSorted(list, 20);
    insertSorted(list, 30);
    Node* second = list->head->next;
    bool isValid = (second->data == 20);
    freeList(list);
    if (!isValid) printf("Error: testAccessElement failed!\n");
    return isValid;
}

bool testList() {
    return testInitList() && testSingleInsert() && testSortedInsert() && testDeleteExisting() && testDeleteFromEmpty() && testAccessElement();
}
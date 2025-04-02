#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "list.h"
#include "testsList.h"

bool testInitList(void) {
    SortedList* list = initList();
    bool isValid = (list != NULL);
    freeList(&list);
    if (!isValid) {
        printf("Error: testInitList failed!\n");
    }
    return isValid;
}

bool testSingleInsert(void) {
    SortedList* list = initList();
    if (list == NULL) {
        printf("Error: testSingleInsert failed due to initList returning NULL!\n");
        return false;
    }
    int result = insertSorted(list, 42);
    bool isValid = (result == 0 && deleteValue(list, 42));
    freeList(&list);
    if (!isValid) {
        printf("Error: testSingleInsert failed!\n");
    }
    return isValid;
}

bool testSortedInsert(void) {
    SortedList* list = initList();
    if (list == NULL) {
        printf("Error: testSortedInsert failed due to initList returning NULL!\n");
        return false;
    }
    insertSorted(list, 3);
    insertSorted(list, 1);
    insertSorted(list, 4);
    insertSorted(list, 2);
    bool isValid = (deleteValue(list, 1) &&
        deleteValue(list, 2) &&
        deleteValue(list, 3) &&
        deleteValue(list, 4) &&
        !deleteValue(list, 5));
    freeList(&list);
    if (!isValid) {
        printf("Error: testSortedInsert failed!\n");
    }
    return isValid;
}

bool testDeleteExisting(void) {
    SortedList* list = initList();
    insertSorted(list, 1);
    insertSorted(list, 2);
    insertSorted(list, 3);
    bool removed = deleteValue(list, 2);
    bool isValid = (removed &&
        !deleteValue(list, 2) &&
        deleteValue(list, 1) &&
        deleteValue(list, 3));
    freeList(&list);
    if (!isValid) {
        printf("Error: testRemoveExisting failed!\n");
    }
    return isValid;
}

bool testDeleteFromEmpty(void) {
    SortedList* list = initList();
    bool removed = deleteValue(list, 5);
    bool isValid = !removed;
    freeList(&list);
    if (!isValid) printf("Error: testRemoveFromEmpty failed!\n");
    return isValid;
}

bool testList(void) {
    return testInitList() && testSingleInsert() && testSortedInsert() && testDeleteExisting() && testDeleteFromEmpty();
}
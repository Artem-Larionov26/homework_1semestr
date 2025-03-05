#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "testsList.h"
#include "list.h"

bool testCreateList() {
    int errorCode = 0;
    List* list = createList(&errorCode);
    addInHead(list, 1, &errorCode);
    bool result = (list != NULL);
    deleteList(list);
    return result && errorCode == 0;
}

bool testGetValue() {
    int errorCode = 0;
    List* list = createList(&errorCode);
    addInHead(list, 1, &errorCode);
    bool result = (getValue(list, firstElement(list)) == 1);
    deleteList(list);
    return result && errorCode == 0;
}

bool testAddInHead() {
    int errorCode = 0;
    List* list = createList(&errorCode);
    addInHead(list, 1, &errorCode);
    bool result = (getValue(list, firstElement(list)) == 1);
    deleteList(list);
    return result && errorCode == 0;
}

bool testAddInTail() {
    int errorCode = 0;
    List* list = createList(&errorCode);
    Position position = firstElement(list);
    addInTail(list, 1, &errorCode);
    addInTail(list, 2, &errorCode);
    addInTail(list, 3, &errorCode);
    bool result = (getValue(list, firstElement(list)) == 1);
    deleteElement(list, position);
    result = (getValue(list, firstElement(list)) == 2);
    deleteElement(list, position);
    result = (getValue(list, firstElement(list)) == 3);
    deleteList(list);
    return result && errorCode == 0;
}

bool testAddValue() {
    int errorCode = 0;
    List* list = createList(&errorCode);
    Position position = firstElement(list);
    addValue(list, position, 1, &errorCode);
    addValue(list, position, 2, &errorCode);
    bool result = (getValue(list, firstElement(list)) == 2);
    deleteElement(list, position);
    result = (getValue(list, firstElement(list)) == 1);
    deleteList(list);
    return result && errorCode == 0;
}

bool testDeleteElement() {
    int errorCode = 0;
    List* list = createList(&errorCode);
    Position position = firstElement(list);
    addInHead(list, 3, &errorCode);
    addInHead(list, 2, &errorCode);
    addInHead(list, 1, &errorCode);
    deleteElement(list, position);
    bool result = (getValue(list, position) == 2);
    deleteList(list);
    return result && errorCode == 0;
}

bool testGetElement() {
    int errorCode = 0;
    List* list = createList(&errorCode);
    addInHead(list, 1, &errorCode);
    addInHead(list, 2, &errorCode);
    addInHead(list, 3, &errorCode);
    bool result = (getValue(list, getElement(list, 1)) == 2);
    deleteList(list);
    return result && errorCode == 0;
}

bool testList() {
    return testCreateList() && testGetValue() && testAddInHead() && testAddInTail() && testAddValue() && testDeleteElement() && testGetElement();
}
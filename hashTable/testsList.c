#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "testsList.h"
#include "list.h"

bool testCreateList() {
    int errorCode = 0;
    List* list = createList(&errorCode);
    Value value = { NULL, 1 };
    addInHead(list, value, &errorCode);
    bool result = (list != NULL);
    deleteList(list);
    return result && errorCode == 0;
}

bool testGetValue() {
    int errorCode = 0;
    List* list = createList(&errorCode);
    Value value = { NULL, 1 };
    addInHead(list, value, &errorCode);
    bool result = (getValue(list, firstElement(list)).counter == 1);
    deleteList(list);
    return result && errorCode == 0;
}

bool testAddInHead() {
    int errorCode = 0;
    List* list = createList(&errorCode);
    Value value = { NULL, 1 };
    addInHead(list, value, &errorCode);
    bool result = (getValue(list, firstElement(list)).counter == 1);
    deleteList(list);
    return result && errorCode == 0;
}

bool testAddInTail() {
    int errorCode = 0;
    List* list = createList(&errorCode);
    Value value1 = { NULL, 1 };
    Value value2 = { NULL, 2 };
    Value value3 = { NULL, 3 };
    addInTail(list, value1, &errorCode);
    addInTail(list, value2, &errorCode);
    addInTail(list, value3, &errorCode);
    bool result = (getValue(list, firstElement(list)).counter == 1);
    deleteElement(list, firstElement(list));
    result = (getValue(list, firstElement(list)).counter == 2);
    deleteElement(list, firstElement(list));
    result = (getValue(list, firstElement(list)).counter == 3);
    deleteList(list);
    return result && errorCode == 0;
}

bool testAddValue() {
    int errorCode = 0;
    List* list = createList(&errorCode);
    Position position = firstElement(list);
    Value value1 = { NULL, 1 };
    Value value2 = { NULL, 2 };
    addValue(list, position, value1, &errorCode);
    addValue(list, position, value2, &errorCode);
    bool result = (getValue(list, firstElement(list)).counter == 2);
    deleteElement(list, position);
    result = (getValue(list, firstElement(list)).counter == 1);
    deleteList(list);
    return result && errorCode == 0;
}

bool testDeleteElement() {
    int errorCode = 0;
    List* list = createList(&errorCode);
    Position position = firstElement(list);
    Value value1 = { NULL, 1 };
    Value value2 = { NULL, 2 };
    Value value3 = { NULL, 3 };
    addInHead(list, value3, &errorCode);
    addInHead(list, value2, &errorCode);
    addInHead(list, value1, &errorCode);
    deleteElement(list, position);
    bool result = (getValue(list, position).counter == 2);
    deleteList(list);
    return result && errorCode == 0;
}

bool testGetElement() {
    int errorCode = 0;
    List* list = createList(&errorCode);
    Value value1 = { NULL, 1 };
    Value value2 = { NULL, 2 };
    Value value3 = { NULL, 3 };
    addInHead(list, value1, &errorCode);
    addInHead(list, value2, &errorCode);
    addInHead(list, value3, &errorCode);
    bool result = (getValue(list, getElement(list, 1)).counter == 2);
    deleteList(list);
    return result && errorCode == 0;
}

bool testList() {
    return testCreateList() && testGetValue() && testAddInHead() && testAddInTail() && testAddValue() && testDeleteElement() && testGetElement();
}
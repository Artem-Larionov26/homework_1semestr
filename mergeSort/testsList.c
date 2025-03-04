#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "testsList.h"
#include "list.h"

bool testCreateList() {
    int errorCode = 0;
    List* list = createList(&errorCode);
    addInHead(list, "Daria", "010707", &errorCode);
    bool result = (list != NULL);
    deleteList(list);
    return result && errorCode == 0;
}

bool testGetNameAndPhoneAndAddInHead() {
    int errorCode = 0;
    List* list = createList(&errorCode);
    addInHead(list, "Daria", "010707", &errorCode);
    char name[50] = { '\0' };
    char phone[20] = { '\0' };
    getNameAndPhone(list, firstElement(list), name, phone, &errorCode);
    bool result = (!strcmp(name, "Daria") && !strcmp(phone, "010707"));
    deleteList(list);
    return result && errorCode == 0;
}

bool testAddContact() {
    int errorCode = 0;
    List* list = createList(&errorCode);
    Position position = firstElement(list);
    addContact(list, position, "Daria", "010707", &errorCode);
    position = next(firstElement(list));
    addContact(list, position, "Artem", "260506", &errorCode);
    char name1[80] = { '\0' };
    char phone1[20] = { '\0' };
    getNameAndPhone(list, firstElement(list), name1, phone1, &errorCode);
    bool result = (!strcmp(name1, "Daria") && !strcmp(phone1, "010707"));
    char name2[50] = { '\0' };
    char phone2[20] = { '\0' };
    getNameAndPhone(list, next(firstElement(list)), name2, phone2, &errorCode);
    result = (!strcmp(name2, "Artem") && !strcmp(phone2, "260506"));
    deleteList(list);
    return result && errorCode == 0;
}

bool testAddInTail() {
    int errorCode = 0;
    List* list = createList(&errorCode);
    Position position = firstElement(list);
    addInTail(list, "Inga", "220680", &errorCode);
    position = next(firstElement(list));
    addInTail(list, "Pavel", "140677", &errorCode);
    char name1[50] = { '\0' };
    char phone1[20] = { '\0' };
    getNameAndPhone(list, firstElement(list), name1, phone1, &errorCode);
    bool result = (!strcmp(name1, "Inga") && !strcmp(phone1, "220680"));
    getNameAndPhone(list, next(firstElement(list)), name1, phone1, &errorCode);
    result = (!strcmp(name1, "Pavel") && !strcmp(phone1, "140677"));
    deleteList(list);
    return result && errorCode == 0;
}

bool testDeleteElement() {
    int errorCode = 0;
    List* list = createList(&errorCode);
    Position position = firstElement(list);
    addInHead(list, "Artem", "260506", &errorCode);
    addInHead(list, "Daria", "010707", &errorCode);
    addInHead(list, "Nastya", "200418", &errorCode);
    deleteElement(list, position);
    char name[50] = { '\0' };
    char phone[20] = { '\0' };
    getNameAndPhone(list, firstElement(list), name, phone, &errorCode);
    bool result = (!strcmp(name, "Daria") && !strcmp(phone, "010707"));
    deleteList(list);
    return result && errorCode == 0;
}

bool testGetElement() {
    int errorCode = 0;
    List* list = createList(&errorCode);
    addInHead(list, "Artem", "260506", &errorCode);
    addInHead(list, "Daria", "010707", &errorCode);
    addInHead(list, "Nastya", "200418", &errorCode);
    char name[50] = { '\0' };
    char phone[20] = { '\0' };
    getNameAndPhone(list, getElement(list, 1), name, phone, &errorCode);
    bool result = (!strcmp(name, "Daria") && !strcmp(phone, "010707"));
    deleteList(list);
    return result && errorCode == 0;
}

bool testList() {
    return testCreateList() && testGetNameAndPhoneAndAddInHead() && testAddContact() && testAddInTail() && testDeleteElement() && testGetElement();
}
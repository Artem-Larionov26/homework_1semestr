#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "list.h"
#include "readFromFile.h"
#include "mergeSort.h"
#include "tests.h"
#include "testsList.h"

bool testReadFromFile() {
    bool result = true;
    char* referenceNames[] = { "Nastya", "Daria", "Artem" };
    char* referencePhones[] = { "200418", "010707", "260506" };
    int index = 0;
    int errorCode = 0;
    List* list = createList(&errorCode);
    readFromFile("fileForTest.txt", list, &errorCode);
    for (Position i = firstElement(list); !isLast(list, i); i = next(i)) {
        char name[50] = { NULL };
        char phone[20] = { NULL };
        getNameAndPhone(list, i, name, phone, &errorCode);
        if (strcmp(name, referenceNames[index]) || strcmp(phone, referencePhones[index])) {
            result = false;
        }
        ++index;
    }
    deleteList(list);
    return result && errorCode == 0;
}

bool testMergeSorting() {
    bool result = true;
    int errorCode = 0;
    List* list = createList(&errorCode);
    addInTail(list, "Artem", "260506", &errorCode);
    addInTail(list, "Daria", "010707", &errorCode);
    addInTail(list, "Nastya", "200418", &errorCode);
    char* testStringByName[] = { "Artem", "Daria", "Nastya" };
    char* testStringByPhone[] = { "010707", "200418", "260506" };
    List* sortedListByName = mergeSorting(list, true, &errorCode);
    List* sortedListByPhone = mergeSorting(list, false, &errorCode);
    Position positionByName = firstElement(sortedListByName);
    Position positionByPhone = firstElement(sortedListByPhone);
    for (int i = 0; i < getSizeList(list); ++i) {
        char name[50] = { '\0' };
        char phone[50] = { '\0' };
        getNameAndPhone(sortedListByName, positionByName, name, phone, &errorCode);
        if (strcmp(name, testStringByName[i])) {
            result = false;
        }
        getNameAndPhone(sortedListByPhone, positionByPhone, name, phone, &errorCode);
        if (strcmp(phone, testStringByPhone[i])) {
            result = false;
        }
        positionByName = next(positionByName);
        positionByPhone = next(positionByPhone);
    }
    deleteList(list);
    deleteList(sortedListByName);
    deleteList(sortedListByPhone);
    return result && errorCode == 0;
}

bool testProgram() {
    return testList() && testReadFromFile() && testMergeSorting();
}
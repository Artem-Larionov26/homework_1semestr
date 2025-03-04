#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "list.h"
#include "readFromFile.h"
#include "mergeSort.h"
#include "tests.h"

int main() {
    if (!testProgram()) {
        printf("Test failed!\n");
        return 1;
    }
    int operationNumber = 0;
    int errorCode = 0;
    List* list = createList(&errorCode);
    readFromFile("phoneBook.txt", list, &errorCode);
    printf("To sort by name enter 0\nTo sort by phone number enter 1\n");
    printf("Enter operation number: ");
    scanf_s("%d", &operationNumber);
    List* sortedList = operationNumber == 0 ? mergeSorting(list, true, &errorCode) : mergeSorting(list, false, &errorCode);
    deleteList(list);
    if (errorCode == 0) {
        for (Position i = firstElement(sortedList); !isLast(sortedList, i); i = next(i)) {
            char name[50] = { '\0' };
            char phone[20] = { '\0' };
            getNameAndPhone(sortedList, i, name, phone, &errorCode);
            printf("%s %s\n", name, phone);
        }
    }
    else if (errorCode == 1) {
        printf("Memory allocation error!\n");
        return 1;
    }
    else if (errorCode == 2) {
        printf("Error opening file!\n");
        return 2;
    }

    deleteList(sortedList);
}
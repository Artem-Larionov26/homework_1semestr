#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "readFromFile.h"
#include "list.h"

void readFromFile(const char* filename, List* list, int* errorCode) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        *errorCode = 2;
        fclose(file);
        return;
    }
    char name[50] = { ' ' };
    char phone[20] = { ' ' };
    while (fscanf(file, "%s %s", name, phone) == 2) {
        addContact(list, firstElement(list), name, phone, errorCode);
    }
    fclose(file);
}
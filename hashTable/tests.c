#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "hashTable.h"
#include "tests.h"
#include "testsList.h"

bool testProgram() {
    int errorCode = 0;
    bool result = false;
    HashTable* hashTable = createHashTable(&errorCode);
    char* testText1 = calloc(20, sizeof(char));
    char* testText2 = calloc(20, sizeof(char));
    char* testText3 = calloc(20, sizeof(char));
    char* testText4 = calloc(20, sizeof(char));
    if (testText1 == NULL && testText2 == NULL && testText3 == NULL && testText4 == NULL) {
        return false;
    }
    strcpy_s(testText1, 19, "asdfgh");
    strcpy_s(testText2, 19, "qwerty");
    strcpy_s(testText3, 19, "asdfgh");
    strcpy_s(testText4, 19, "zxcvbn");
    Value value1 = { testText1, 1 };
    Value value2 = { testText2, 1 };
    Value value3 = { testText3, 1 };
    Value value4 = { testText4, 1 };
    addValueToHashTable(hashTable, value1, &errorCode);
    addValueToHashTable(hashTable, value2, &errorCode);
    addValueToHashTable(hashTable, value3, &errorCode);
    addValueToHashTable(hashTable, value4, &errorCode);
    if (getWordFrequencyFromHashTable(hashTable, "asdfgh") == 2 &&
        getWordFrequencyFromHashTable(hashTable, "qwerty") == 1 &&
        getWordFrequencyFromHashTable(hashTable, "poiuyt") == 0) {
        result = true;
    }
    deleteHashTable(hashTable);
    return result && errorCode == 0 && testList();
}
#include "readingFromFile.h"
#include <stdio.h>
#include <stdbool.h>

int readerForTask(int* array) {
    FILE* file = fopen("fileForTask.txt", "r");
    if (file == NULL) {
        printf("File not found!\n");
        return -1;
    }
    int readingLengthForTask = 0;
    while (fscanf_s(file, "%d; ", &array[readingLengthForTask]) == 1) {
        readingLengthForTask++;
    }
    return *array;
    fclose(file);
}

int readerForTest(int* array) {
    FILE* testfile = fopen("fileForTest.txt", "r");
    if (testfile == NULL) {
        printf("File not found!\n");
        return -1;
    }
    int readingLengthForTest = 0;
    while (fscanf_s(testfile, "%d; ", &array[readingLengthForTest]) == 1) {
        readingLengthForTest++;
    }
    return *array;
    fclose(testfile);
}
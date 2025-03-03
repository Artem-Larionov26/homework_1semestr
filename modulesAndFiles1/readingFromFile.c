#include "readingFromFile.h"
#include <stdio.h>
#include <stdbool.h>

int readFromFile(const char* filename, int* array) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("File not found!\n");
        return -1;
    }
    int readingLength = 0;
    while (fscanf_s(file, "%d; ", &array[readingLength]) == 1) {
        readingLength++;
    }
    fclose(file);
    return *array;
}
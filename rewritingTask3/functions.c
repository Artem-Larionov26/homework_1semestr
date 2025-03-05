#include "functions.h"
#include <stdio.h>
#include <stdbool.h>

#define MAX_NUMBERS 100

int readFromFile(const char* filename, int* array) {
    FILE* file = fopen(filename, "r+");
    if (file == NULL) {
        printf("File not found!\n");
        return -1;
    }
    int readingLength = 0;
    while (fscanf_s(file, "%d; ", &array[readingLength]) == 1) {
        readingLength++;
    }
    fclose(file);
    return readingLength;
}

void reverseArray(int* array, int size) {
    for (int i = 0; i < size / 2; i++) {
        int temp = array[i];
        array[i] = array[size - 1 - i];
        array[size - 1 - i] = temp;
    }
}

void writeToFile(const char* filename, int* array, int size) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: Could not open file for writing!\n");
        return;
    }
    for (int i = 0; i < size; i++) {
        fprintf(file, "%d ", array[i]);
    }
    fclose(file);
}
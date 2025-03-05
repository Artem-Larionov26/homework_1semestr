#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "insertionSort.h"

void insertionSortEvenIndices(int array[], int size) {
    for (int i = 2; i < size; i += 2) {
        int key = array[i];
        int j = i - 2;
        while (j >= 0 && array[j] > key) {
            array[j + 2] = array[j];
            j -= 2;
        }
        array[j + 2] = key;
    }
}

void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}
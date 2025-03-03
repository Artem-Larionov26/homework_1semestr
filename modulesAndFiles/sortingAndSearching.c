#include "sortingAndSearching.h"
#include <stdio.h>
#include <stdlib.h>

int findMostFrequent(int array[], int size) {
    if (size == 0) {
        printf("Array is empty!\n");
        return -1;
    }
    int min = array[0];
    int max = array[0];
    for (int i = 1; i < size; i++) {
        if (min > array[i]) {
            min = array[i];
        }
        if (max < array[i]) {
            max = array[i];
        }
    }
    int* auxiliaryArray = (int*)calloc(max - min + 1, sizeof(int));
    for (int i = 0; i < size; i++) {
        auxiliaryArray[array[i] - min]++;
    }
    int maxFrequency = 0;
    int mostFrequent = 0;
    for (int i = 0; i < max - min + 1; i++) {
        if (auxiliaryArray[i] > maxFrequency) {
            maxFrequency = auxiliaryArray[i];
            mostFrequent = i + min;
        }
    }
    free(auxiliaryArray);
    return mostFrequent;
}
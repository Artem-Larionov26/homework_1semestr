#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

void swap(int* left, int* right) {
    if (left != right) {
        *left ^= *right;
        *right ^= *left;
        *left ^= *right;
    }
}

void bubbleSort(int* array, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                swap(&array[j], &array[j + 1]);
            }
        }
    }
}

void fillArray(int* array, int size) {
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 100000;
    }
}

void countingSort(int* array, int size) { 
    int min = array[0];
    int max = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] < min) {
            min = array[i];
        }
        if (array[i] > max) {
            max = array[i];
        }
    }
    int* auxiliaryArray = (int*)calloc(max - min + 1, sizeof(int));
    if (auxiliaryArray == NULL) {
        printf("Memory allocation error for the counting array\n");
        return;
    }
    for (int i = 0; i < size; i++) {
        auxiliaryArray[array[i] - min]++;
    }
    int index = 0;
    for (int i = 0; i < max - min + 1; i++) {
        while (auxiliaryArray[i] > 0) {
            array[index] = i + min;
            index++;
            auxiliaryArray[i]--;
        }
    }
    free(auxiliaryArray);
}

void copyArray(int* source, int* destination, int size) {
    for (int i = 0; i < size; i++) {
        destination[i] = source[i];
    }
}

bool arraysAreEqual(int array1[], int array2[], int size) {
    for (int i = 0; i < size; i++) {
        if (array1[i] != array2[i]) {
            return false;
        }
    }
    return true;
}

bool bubbleSortingTest() {
    int array[] = { 1, 8, 12, 3, 5 };
    int sortedArray[] = { 1, 3, 5, 8, 12 };
    bubbleSort(array, 5);
    return arraysAreEqual(array, sortedArray, 5);
}

bool testForSortingByCounting() {
    int array[] = { 1, 8, 12, 3, 5 };
    int sortedArray[] = { 1, 3, 5, 8, 12 };
    countingSort(array, 5);
    return arraysAreEqual(array, sortedArray, 5);
}

int main(void) {
    if (!bubbleSortingTest() || !testForSortingByCounting()) {
        printf("Tests failed\n");
        return -1;
    }
    printf("Tests passed\n");
    const int size = 100000;
    int* originalArray = (int*)malloc(size * sizeof(int));
    int* bubbleArray = (int*)malloc(size * sizeof(int));
    int* countingArray = (int*)malloc(size * sizeof(int));
    if (originalArray == NULL || bubbleArray == NULL || countingArray == NULL) {
        printf("Memory allocation error for the array\n");
        free(originalArray);
        free(bubbleArray);
        free(countingArray);
        return -1;
    }
    srand(time(0));
    fillArray(originalArray, size);
    copyArray(originalArray, bubbleArray, size);
    copyArray(originalArray, countingArray, size);
    clock_t start = clock();
    bubbleSort(bubbleArray, size);
    clock_t end = clock();
    double bubbleTime = (double)(end - start) / CLOCKS_PER_SEC;
    start = clock();
    countingSort(countingArray, size);
    end = clock();
    double countingTime = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Bubble sorting took %f seconds\n", bubbleTime);
    printf("Sorting by counting took %f seconds\n", countingTime);
    free(originalArray);
    free(bubbleArray);
    free(countingArray);
    return 0;
}

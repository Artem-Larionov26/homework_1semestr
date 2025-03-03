#include "sortingAndSearching.h"
#include <stdio.h>
#include <stdlib.h>

void swap(int* right, int* left) {
    if (right != left) {
        *left ^= *right;
        *right ^= *left;
        *left ^= *right;
    }
}

int arraySort(int array[], int leftIndex, int rightIndex) {
    int pivot = array[rand() % (rightIndex - leftIndex) + leftIndex];
    int endIndex = rightIndex;
    int startIndex = leftIndex;
    while (startIndex <= endIndex) {
        while (array[startIndex] < pivot) {
            startIndex++;
        }
        while (array[endIndex] > pivot) {
            endIndex--;
        }
        if (startIndex <= endIndex) {
            swap(&array[startIndex], &array[endIndex]);
            startIndex++;
            endIndex--;
        }
    }
    return startIndex;
}

void qSort(int array[], int leftIndex, int rightIndex) {
    if (leftIndex < rightIndex) {
        int separator = arraySort(array, leftIndex, rightIndex);
        qSort(array, leftIndex, separator - 1);
        qSort(array, separator, rightIndex);
    }
}

int findMostFrequent(int array[], int size) {
    if (size == 0) {
        printf("Array is empty!\n");
        return -1;
    }
    int mostFreaqment = -1;
    int countOfFreaqmentMax = 0;
    int countOfFreaqment = 0;
    for (int i = 0; i < size - 1; i++) {
        countOfFreaqment++;
        if (array[i] != array[i + 1]) {
            if (countOfFreaqmentMax < countOfFreaqment) {
                countOfFreaqmentMax = countOfFreaqment;
                mostFreaqment = array[i];
            }
            countOfFreaqment = 0;
        }
    }
    countOfFreaqment++;
    if (countOfFreaqment > countOfFreaqmentMax) {
        mostFreaqment = array[size - 1];
    }
    return mostFreaqment;
}
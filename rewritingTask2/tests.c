#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "insertionSort.h"

bool arraysEqual(int arr1[], int arr2[], int size) {
    for (int i = 0; i < size; i++) {
        if (arr1[i] != arr2[i]) {
            return false;
        }
    }
    return true;
}

bool test1() {
    int array[] = { 5 };
    int expected[] = { 5 };
    insertionSortEvenIndices(array, 1);
    return arraysEqual(array, expected, 1);
}

bool test2() {
    int array[] = {3, 1};
    int expected[] = {3, 1};
    insertionSortEvenIndices(array, 2);
    return arraysEqual(array, expected, 2);
}

bool test3() {
    int array[] = {9, 2, 5, 1, 7, 4};
    int expected[] = {5, 2, 7, 1, 9, 4};
    insertionSortEvenIndices(array, 6);
    return arraysEqual(array, expected, 6);
}

bool test4() {
    int array[] = {1, 2, 3, 4, 5, 6};
    int expected[] = {1, 2, 3, 4, 5, 6};
    insertionSortEvenIndices(array, 6);
    return arraysEqual(array, expected, 6);
}

bool test5() {
    int array[] = {-3, 2, -1, 4, -5, 6};
    int expected[] = {-5, 2, -3, 4, -1, 6};
    insertionSortEvenIndices(array, 6);
    return arraysEqual(array, expected, 6);
}

bool test6() {
    int array[] = {3, 2, 3, 4, 1, 6};
    int expected[] = {1, 2, 3, 4, 3, 6};
    insertionSortEvenIndices(array, 6);
    return arraysEqual(array, expected, 6);
}

bool allTests() {
    return test1() && test2() && test3() && test4() && test5() && test6();
}
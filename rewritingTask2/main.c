#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "insertionSort.h"
#include "tests.h"

int main() {
    if (!allTests()) {
        printf("Tests failed!\n");
        return -1;
    }
    int size = 0;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int* array = malloc(size * sizeof(int));
    printf("Enter %d of the array elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }
    insertionSortEvenIndices(array, size);
    printf("Array after sorting even indexes:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    return 0;
}

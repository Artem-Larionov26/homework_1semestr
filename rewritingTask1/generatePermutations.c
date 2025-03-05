#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "generatePermutations.h"

void swap(int* right, int* left) {
    if (right != left) {
        *left ^= *right;
        *right ^= *left;
        *left ^= *right;
    }
}

void generatePermutations(int array[], int left, int right) {
    if (left == right) {
        for (int i = 0; i <= right; i++) {
            printf("%d", array[i]);
        }
        printf("\n");
        return;
    }
    for (int i = left; i <= right; i++) {
        swap(&array[left], &array[i]);
        generatePermutations(array, left + 1, right);
        swap(&array[left], &array[i]);
    }
}


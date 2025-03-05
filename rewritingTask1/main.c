#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "generatePermutations.h"

int main() {
    int N = 0;
    printf("Enter N: ");
    scanf("%d", &N);
    int* array = malloc(N * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation error!\n");
    }
    for (int i = 0; i < N; i++) {
        array[i] = i + 1;
    }
    generatePermutations(array, 0, N - 1);
    return 0;
}

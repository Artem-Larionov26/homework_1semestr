﻿#include <stdio.h>
#include <stdbool.h>

void nullElements(int array[]) {
    int counter = 0;
    while (array[counter] == 0) {
        ++counter;
    }
    printf("\nNull elements:\n array size: %d\n----------", counter);
}

int main(void) {
    int arrayForNullElements[31] = { 0 };
    nullElements(arrayForNullElements);
}
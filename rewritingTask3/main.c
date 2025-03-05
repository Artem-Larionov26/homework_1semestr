#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "functions.h"
#include "tests.h"

#define MAX_NUMBERS 100

int main() {
    if (!allTests()) {
        printf("Tests failed!\n");
        return -1;
    }
    int numbers[MAX_NUMBERS] = { 0 };
    int count = readFromFile("numbers.txt", numbers);
    reverseArray(numbers, count);
    writeToFile("numbers.txt", numbers, count);
    printf("The numbers have been successfully expanded and written to a file!\n");
    return 0;
}
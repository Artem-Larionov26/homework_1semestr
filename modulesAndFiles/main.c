#include "sortingAndSearching.h"
#include "tests.h"
#include "readingFromFile.h"
#include <stdio.h>

int main(void) {
    if (runAllTests() != 6 || !testForReading()) {
        printf("Tests failed!\n");
        return -1;
    }
    int array[15] = { 0 };
    readerForTask(array);
    printf("The most frequent element: %d\n", findMostFrequent(array, 15));
}
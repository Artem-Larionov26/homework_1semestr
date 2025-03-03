#include "tests.h"
#include "sortingAndSearching.h"
#include "readingFromFile.h"
#include <stdio.h>
#include <stdbool.h>

bool runTests(int array[], int size, int expectedResult) {
    int result = findMostFrequent(array, size);
    return result == expectedResult;
}

bool testForReading() {
    int testArray[9] = { 0 };
    readFromFile("fileForTest.txt", testArray);
    int expected = 1;
    return findMostFrequent(testArray, 9) == expected;
}

int runAllTests(void) {
    int passedTests = 0;
    int array1[] = { 1, 2, 2, 3, 3, 3 };
    if (runTests(array1, 6, 3)) {
        passedTests++;
    }
    int array2[] = { 10, 20, 30, 40, 50 };
    if (runTests(array2, 5, 10)) {
        passedTests++;
    }
    int array3[] = { 5, 5, 6, 6, 7, 7 };
    if (runTests(array3, 6, 5)) {
        passedTests++;
    }
    int array4[] = { 68 };
    if (runTests(array4, 1, 68)) {
        passedTests++;
    }
    int array5[] = {-18, -6, -5, -3, -2, -2, -2, -1 };
    if (runTests(array5, 8, -2)) {
        passedTests++;
    }
    int array6[] = { 7, 7, 7, 7, 7, 7, 7 };
    if (runTests(array6, 7, 7)) {
        passedTests++;
    }
    return passedTests;
}
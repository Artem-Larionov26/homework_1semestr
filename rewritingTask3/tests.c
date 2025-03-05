#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "functions.h"
#include "tests.h"

bool arraysEqual(int* arr1, int* arr2, int size) {
    for (int i = 0; i < size; i++) {
        if (arr1[i] != arr2[i]) {
            return false;
        }
    }
    return true;
}

bool testReadFromFile() {
    int expected[] = { 10, 20, 30 };
    int array[100] = { 0 };
    int count = readFromFile("testFileForRead.txt", array);
    return count == 3 && arraysEqual(array, expected, 3);
}

bool testReverseArray() {
    int array[] = { 10, 20, 30 };
    int expected[] = { 30, 20, 10 };
    reverseArray(array, 3);
    return arraysEqual(array, expected, 3);
}

bool testWriteToFile() {
    int array[] = { 30, 20, 10 };
    int expected[] = { 30, 20, 10 };
    int readArray[100] = { 0 };
    writeToFile("testFileForWrite.txt", array, 3);
    int count = readFromFile("testFileForWrite.txt", readArray);
    return count == 3 && arraysEqual(readArray, expected, 3);
}

bool allTests() {
    return testReadFromFile() && testReverseArray() && testWriteToFile();
}
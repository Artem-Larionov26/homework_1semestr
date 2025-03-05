#pragma once

#include <stdbool.h>

// Function that compares two arrays
bool arraysEqual(int* arr1, int* arr2, int size);

// Function that verifies the correctness of reading from a file
bool testReadFromFile();

// Function that checks the correctness of the expansion of numbers
bool testReverseArray();

// Function that verifies the correctness of writing numbers to a file
bool testWriteToFile();

// Function that verifies the correctness of all tests
bool allTests();
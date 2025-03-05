#pragma once

// Function that reads a file and returns the number of numbers read
int readFromFile(const char* filename, int* array);

// Function that expands an array of numbers
void reverseArray(int* array, int size);

// Function that writes numbers from an array to a file
void writeToFile(const char* filename, int* array, int size);
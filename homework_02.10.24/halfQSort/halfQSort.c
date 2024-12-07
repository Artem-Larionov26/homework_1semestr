#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

void swap(int* left, int* right) {
	if (left != right) {
		*left ^= *right;
		*right ^= *left;
		*left ^= *right;
	}
}

void fillArray(int array[], int size) {
	for (int i = 0; i < size; i++) {
		array[i] = rand() % 100;
	}
}

void printArray(int array[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
}

void halfQSort(int array[], int size) {
	int firstElement = array[0];
	int i = 0;
	int j = size - 1;
	while (i <= j) {
		while ((array[i] < firstElement) && (i <= j)) {
			i++;
		}
		while ((firstElement <= array[j]) && (i <= j)) {
			j--;
		}
		if (i <= j) {
			swap(&array[i], &array[j]);
			i++;
			j--;
		}
	}
}

bool isPartitionedCorrectly(int array[], int size, int originalFirstElement) {
	int i = 0;
	while ((i < size) && (array[i] < originalFirstElement)) {
		i++;
	}
	while (i < size) {
		if (array[i] < originalFirstElement) {
			return false;
		}
		i++;
	}
	return true;
}

void runTests() {
	int array1[] = { 42, 17, 88, 39, 25, 67, 13, 53 };
	int size1 = 8;
	int firstElement1 = array1[0];
	halfQSort(array1, size1);
	printf("Test 1: ");
	if (isPartitionedCorrectly(array1, size1, firstElement1)) {
		printf("Passed\n");
	} else {
		printf("Failed\n");
	}

	int array2[] = { 10 };
	int size2 = 1;
	int firstElement2 = array2[0];
	halfQSort(array2, size2);
	printf("Test 2: ");
	if (isPartitionedCorrectly(array2, size2, firstElement2)) {
		printf("Passed\n");
	}
	else {
		printf("Failed\n");
	}

	int array3[] = { 7, 7, 7, 7, 7 };
	int size3 = 5;
	int firstElement3 = array3[0];
	halfQSort(array3, size3);
	printf("Test 3: ");
	if (isPartitionedCorrectly(array3, size3, firstElement3)) {
		printf("Passed\n");
	}
	else {
		printf("Failed\n");
	}

	int array4[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	int size4 = 10;
	int firstElement4 = array4[0];
	halfQSort(array4, size4);
	printf("Test 4: ");
	if (isPartitionedCorrectly(array4, size4, firstElement4)) {
		printf("Passed\n");
	}
	else {
		printf("Failed\n");
	}
}

int main(void) {
	runTests();
	int arraySize = 11;
	int array[11] = { 0 };
	printf("Original Array: ");
	fillArray(array, arraySize);
	printArray(array, arraySize);
	int firstElement = array[0];
	halfQSort(array, arraySize);
	printf("Result: ");
	printArray(array, arraySize);
	if (isPartitionedCorrectly(array, arraySize, firstElement)) {
		printf("Partitioning is correct.\n");
	}
	else {
		printf("Partitioning is incorrect.\n");
	}
	return 0;
}

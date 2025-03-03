#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<stdbool.h>

void swap(int* left, int* right) {
	if (left != right) {
		*left ^= *right;
		*right ^= *left;
		*left ^= *right;
	}
}

void fillArray(int array[], int size) {
	printf("Original array: ");
	for (int i = 0; i < size; i++) {
		array[i] = rand() % 100;
		printf("%d ", array[i]);
	}
}

void printArray(int array[], int size) {
	printf("\nResult: ");
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

int isPartitionedCorrectly(int array[], int size) {
	int firstElement = array[0];
	int i = 0;
	while ((i < size) && (array[i] < firstElement)) {
		i++;
	}
	while (i < size) {
		if (array[i] < firstElement) {
			return 0;
		}
		i++;
	}
	return 1;
}

void runTests() {
	int array1[] = { 42, 17, 88, 39, 25, 67, 13, 53 };
	int size1 = 8;
	halfQSort(array1, size1);
	printf("Test 1: ");
	printArray(array1, size1);
	if (isPartitionedCorrectly(array1, size1)) {
		printf("Passed\n");
	} else {
		printf("Failed\n");
	}

	int array2[] = { 10 };
	int size2 = 1;
	halfQSort(array2, size2);
	printf("Test 2: ");
	printArray(array2, size2);
	if (isPartitionedCorrectly(array2, size2)) {
		printf("Passed\n");
	}
	else {
		printf("Failed\n");
	}

	int array3[] = { 7, 7, 7, 7, 7 };
	int size3 = 5;
	halfQSort(array3, size3);
	printf("Test 3: ");
	printArray(array3, size3);
	if (isPartitionedCorrectly(array3, size3)) {
		printf("Passed\n");
	}
	else {
		printf("Failed\n");
	}

	int array4[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	int size4 = 10;
	halfQSort(array4, size4);
	printf("Test 4: ");
	printArray(array4, size4);
	if (isPartitionedCorrectly(array4, size4)) {
		printf("Passed\n");
	}
	else {
		printf("Failed\n");
	}
}

int main(void) {
	int array[11] = { 0 };
	fillArray(array, 11);
	halfQSort(array, 11);
	printArray(array, 11);
	runTests();
	return 0;
}

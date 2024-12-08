#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int findMostFrequent(int array[], int size) {
	if (size == 0) {
		printf("Array is empty!\n");
		return -1;
	}
	int min = array[0];
	int max = array[0];
	for (int i = 1; i < size; i++) {
		if (min > array[i]) {
			min = array[i];
		}
		if (max < array[i]) {
			max = array[i];
		}
	}
	int* auxiliaryArray = (int*)calloc(max - min + 1, sizeof(int));
	for (int i = 0; i < size; i++) {
		auxiliaryArray[array[i] - min]++;
	}
	int maxFrequency = 0;
	int mostFrequent = 0;
	for (int i = 0; i < max - min + 1; i++) {
		if (auxiliaryArray[i] > maxFrequency) {
			maxFrequency = auxiliaryArray[i];
			mostFrequent = i + min;
		}
	}
	free(auxiliaryArray);
	return mostFrequent;
}

bool runTests(int array[], int size, int expectedResult) {
	int result = findMostFrequent(array, size);
	if (result == expectedResult) {
		return true;
	} else {
		return false;
	}
}

void runAllTests() {
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
	int array5[] = { -1, -8, -18, -2, -4, -6, -2, -5, -1, -2 };
	if (runTests(array5, 10, -2)) {
		passedTests++;
	}
	int array6[] = { 7, 7, 7, 7, 7, 7, 7 };
	if (runTests(array6, 7, 7)) {
		passedTests++;
	}
	printf("Total tests passed: %d\n", passedTests);
}

int main(void) {
	runAllTests();
	return 0;
}
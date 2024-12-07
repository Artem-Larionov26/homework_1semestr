#include <stdio.h>
#include <stdbool.h>


void swap(int* left, int* right) {
	if (left != right) {
		*left ^= *right;
		*right ^= *left;
		*left ^= *right;
	}
}

void reverseElements(int array[], int start, int end) {
	while (start < end) {
		swap(&array[start], &array[end]);
		start++;
		end--;
	}
}

void rearrangeSegments(int array[], int m, int n) {
	reverseElements(array, 0, m-1);
	reverseElements(array, m, m + n - 1);
	reverseElements(array, 0, m + n - 1);
}

bool compareArrays(int array1[], int array2[], int size) {
	for (int i = 0; i < size; i++) {
		if (array1[i] != array2[i]) {
			return false;
		}
	}
	return true;
}

void runTests() {
	int array1[] = { 1, 2, 3, 4 };
	int expected1[] = { 3, 4, 1, 2 };
	rearrangeSegments(array1, 2, 2);
	if (compareArrays(array1, expected1, 4)) {
		printf("Test 1 passed!\n");
	} else {
		printf("Test 1 failed!\n");
	}

	int array2[] = { 1, 2, 3, 4, 5 };
	int expected2[] = { 4, 5, 1, 2, 3 };
	rearrangeSegments(array2, 3, 2);
	if (compareArrays(array2, expected2, 5)) {
		printf("Test 2 passed!\n");
	}
	else {
		printf("Test 2 failed!\n");
	}

	int array3[] = { 42 };
	int expected3[] = { 42 };
	rearrangeSegments(array3, 1, 0);
	if (compareArrays(array3, expected3, 1)) {
		printf("Test 3 passed!\n");
	}
	else {
		printf("Test 3 failed!\n");
	}

	int array4[] = { 7, 7, 7, 7 };
	int expected4[] = { 7, 7, 7, 7 };
	rearrangeSegments(array4, 2, 2);
	if (compareArrays(array4, expected4, 4)) {
		printf("Test 4 passed!\n");
	}
	else {
		printf("Test 4 failed!\n");
	}
}

int main() {
	runTests();
	int array[] = { 1, 2, 3, 4, 5, 6, 7 ,8 };
	int m = 4;
	int n = 4;
	int arraySize = 8;
	printf("Initial array:");
	for (int i = 0; i < arraySize; i++) {
		printf("%d", array[i]);
	}
	printf("\n");
	rearrangeSegments(array, m, n);
	printf("Array after permutation:");
	for (int i = 0; i < arraySize; i++) {
		printf("%d", array[i]);
	}
	printf("\n");
	return 0;
}
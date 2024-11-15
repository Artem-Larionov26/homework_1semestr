#include<stdio.h>


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

void rerrangingSegments(int array[], int m, int n) {
	reverseElements(array, 0, m-1);
	reverseElements(array, m, m + n - 1);
	reverseElements(array, 0, m + n - 1);
}

void runTests() {
	int array1[] = { 1, 2, 3, 4 };
	int expected1[] = { 3, 4, 1, 2 };
	rerrangingSegments(array1, 2, 2);
	int test1 = 1;
	for (int i = 0; i < 4; i++) {
		if (array1[i] != expected1[i]) {
			test1 = 0;
			break;
		}
	}
	if (test1) {
		printf("Test 1 passed\n");
	} else {
		printf("Test 1 failed\n");
	}

	int array2[] = { 1, 2, 3, 4, 5 };
	int expected2[] = { 4, 5, 1, 2, 3 };
	rerrangingSegments(array2, 3, 2);
	int test2 = 1;
	for (int i = 0; i < 5; i++) {
		if (array2[i] != expected2[i]) {
			test2 = 0;
			break;
		}
	}
	if (test2) {
		printf("Test 2 passed\n");
	} else {
		printf("Test 2 failed\n");
	}

	int array3[] = { 42 };
	int expected3[] = { 42 };
	rerrangingSegments(array3, 1, 0);
	int test3 = 1;
	for (int i = 0; i < 1; i++) {
		if (array3[i] != expected3[i]) {
			test3 = 0;
			break;
		}
	}
	if (test3) {
		printf("Test 3 passed\n");
	} else {
		printf("Test 3 failed\n");
	}

	int array4[] = { 7, 7, 7, 7 };
	int expected4[] = { 7, 7, 7, 7 };
	rerrangingSegments(array4, 2, 2);
	int test4 = 1;
	for (int i = 0; i < 4; i++) {
		if (array4[i] != expected4[i]) {
			test4 = 0;
			break;
		}
	}
	if (test4) {
		printf("Test 4 passed\n");
	} else {
		printf("Test 4 failed\n");
	}
}

int main() {
	int array[] = { 1, 2, 3, 4, 5, 6, 7 ,8 };
	int m = 4;
	int n = 4;
	printf("Initial array:");
	for (int i = 0; i < 8; i++) {
		printf("%d", array[i]);
	}
	printf("\n");
	rerrangingSegments(array, m, n);
	printf("Array after permutation:");
	for (int i = 0; i < 8; i++) {
		printf("%d", array[i]);
	}
	printf("\n");
	runTests();
	return 0;
}
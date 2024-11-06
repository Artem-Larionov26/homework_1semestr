#include <stdio.h>

int countNullElements(int array[], int arraySize) {
	int countNullElements = 0;
	for (int i = 0; i < arraySize; i++) {
		if (array[i] == 0) {
			countNullElements++;
		}
	}
	return countNullElements;
}

void runTests() {
	int test1[] = { 1, 0, 3, 0, 5 };
	int test2[] = {0, 0, 0};
	int test3[] = {1, 2, 3, 4, 5};
	int test4[] = {0};


	printf("Test 1: ");
	printf(countNullElements(test1, 5) == 2 ? "Passed\n" : "Failed\n");
	printf("Test 2: ");
	printf(countNullElements(test2, 3) == 3 ? "Passed\n" : "Failed\n");
	printf("Test 3: ");
	printf(countNullElements(test3, 5) == 0 ? "Passed\n" : "Failed\n");
	printf("Test 4: ");
	printf(countNullElements(test4, 1) == 1 ? "Passed\n" : "Failed\n");
}

int main(void) {
	int array[] = { 0, 1, 0, 4, 5, 0, 0, 0, 8, 0, 9, 3 };
	int answer = countNullElements(array, 12);
	printf("The number of zero elements in the array: %d\n", answer);
	runTests();
	return 0;
}
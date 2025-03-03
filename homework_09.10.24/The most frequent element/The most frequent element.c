#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int findMostFrequent(int array[], int size) {
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
	if (auxiliaryArray == NULL) {
		printf("Memory allocation failed!\n");
		return -1;
	}
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

void runTests(int array[], int size) {
	int result = findMostFrequent(array, size);
	printf("Most frequent element: %d\n", result);
}

int main(void) {
	printf("Test1:\nExpeced: 3\n");
	int array1[] = { 1, 2, 2, 3, 3, 3 };
	runTests(array1, 6);
	printf("Test2:\nExpeced: Any of the numbers in the array\n");
	int array2[] = { 10, 20, 30, 40, 50 };
	runTests(array2, 5);
	printf("Test3:\nExpeced: Any of the numbers in the array\n");
	int array3[] = { 5, 5, 6, 6, 7, 7 };
	runTests(array3, 6);
	printf("Test4:\nExpeced: 68\n");
	int array4[] = { 68 };
	runTests(array4, 1);
	printf("Test5:\nExpeced: -2\n");
	int array5[] = { -1, -8, -18, -2, -4, -6, -2, -5, -1, -2 };
	runTests(array5, 10);
	printf("Test6:\nExpeced: 7\n");
	int array6[] = { 7, 7, 7, 7, 7, 7, 7 };
	runTests(array6, 7);
	int array[] = { 1, 3, 2, 5, 1, 1, 7, 3, 3, 2, 4, 4, 3, 6, 3, 3 };
	int result = findMostFrequent(array, 16);
	printf("Most frequent element: %d\n", result);
	return 0;
}
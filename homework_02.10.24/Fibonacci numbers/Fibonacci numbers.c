#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

int recursivelyFibonacci(int number) {
	if (number == 0) {
		return 0;
	} else if (number <= 2) {
		return 1;
	}
	return (recursivelyFibonacci(number - 1) + recursivelyFibonacci(number - 2));
}

int iterativelyFibonacci(int number) {
	if (number == 0) {
		return 0;
	} else if (number <= 2) {
		return 1;
	}
	int variable1 = 1;
	int variable2 = 1;
	int res = 0;
	for (int i = 3; i <= number; i++) {
		res = variable1 + variable2;
		variable1 = variable2;
		variable2 = res;
	}
	return variable2;
}

void comparePerfomance() {
	int number = 47;
	clock_t start1 = clock();
	int recResult = recursivelyFibonacci(number);
	clock_t end1 = clock();
	double recTime = (double)(end1 - start1) / CLOCKS_PER_SEC;
	clock_t start2 = clock();
	int iterResult = iterativelyFibonacci(number);
	clock_t end2 = clock();
	double iterTime = (double)(end2 - start2) / CLOCKS_PER_SEC;
	if (recResult != iterResult) {
		printf("The results don't match\n");
		return;
	}
	printf("Recursively: %f seconds\nIteratively: %f seconds\n", recTime, iterTime);
}

bool comparingArrays(int array1[], int array2[], int size) {
	for (int i = 0; i < size; i++) {
		if (array1[i] != array2[i]) {
			return false;
		}
	}
	return true;
}

bool testRecursively() {
	int array[8] = { 0 };
	int arrayFib[8] = { 0, 1, 1, 2, 3, 5 ,8, 13 };
	for (int i = 0; i < 8; i++) {
		array[i] = recursivelyFibonacci(i);
	}
	return comparingArrays(array, arrayFib, 8);
}

bool testIteratively() {
	int array[8] = { 0 };
	int arrayFib[8] = { 0, 1, 1, 2, 3, 5 ,8, 13 };
	for (int i = 0; i < 8; i++) {
		array[i] = iterativelyFibonacci(i);
	}
	return comparingArrays(array, arrayFib, 8);
}

int main(void) {
	if (!testRecursively && !testIteratively) {
		printf("Test failed!\n");
		return -1;
	}
	comparePerfomance();
	return 0;
}

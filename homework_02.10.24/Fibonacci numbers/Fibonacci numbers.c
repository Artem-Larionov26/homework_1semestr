#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

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
	} 
	int previous = 0;
	int current = 1;
	int result = 0;
	for (int i = 2; i <= number; i++) {
		result = previous + current;
		previous = current;
		current = result;
	}
	return current;
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

void analyzePerformance() {
	int number = 0;
	while (number < 50) { 
		clock_t startRec = clock();
		recursivelyFibonacci(number);
		clock_t endRec = clock();
		double recTime = (double)(endRec - startRec) / CLOCKS_PER_SEC;
		clock_t startIter = clock();
		iterativelyFibonacci(number);
		clock_t endIter = clock();
		double iterTime = (double)(endIter - startIter) / CLOCKS_PER_SEC;
		if (recTime > 0.01 && recTime > iterTime * 2) {
			printf("\nNoticeable slowdown starts at Fibonacci number: %d\n", number);
			break;
		}
		number++;
	}
}

bool compareArrays(int array1[], int array2[], int size) {
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
	return compareArrays(array, arrayFib, 8);
}

bool testIteratively() {
	int array[8] = { 0 };
	int arrayFib[8] = { 0, 1, 1, 2, 3, 5 ,8, 13 };
	for (int i = 0; i < 8; i++) {
		array[i] = iterativelyFibonacci(i);
	}
	return compareArrays(array, arrayFib, 8);
}

int main(void) {
	if (!testRecursively() || !testIteratively()) {
		printf("Test failed!\n");
		return -1;
	}
	printf("Test passed!\n");
	comparePerfomance();
	analyzePerformance();
	return 0;
}

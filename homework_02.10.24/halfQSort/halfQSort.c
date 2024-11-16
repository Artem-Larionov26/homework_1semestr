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


int main(void) {
	int array[11] = { 0 };
	fillArray(array, 11);
	halfQSort(array, 11);
	printArray(array, 11);
	return 0;
}

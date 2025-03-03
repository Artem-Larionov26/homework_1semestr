#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

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
}

bool comparingArrays(int array1[], int array2[], int size) {
	for (int i = 0; i < size; i++) {
		if (array1[i] != array2[i]) {
			return false;
		}
	}
	return true;
}

void insertSort(int array[], int start, int end) {
	int newElement = 0;
	int location = 0;
	for (int i = start; i <= end; i++) {
		newElement = array[i];
		location = i - 1;
		while (location >= 0 && array[location] > newElement) {
			array[location + 1] = array[location];
			location--;
		}
		array[location + 1] = newElement;
	}
}

void smartQsort(int array[], int start, int end) {
	if (end - start + 1 < 10) {
		insertSort(array, start, end);
	} else {
		if (start < end) {
			int supportingElement = array[start];
			int left = start;
			int right = end;
			while (left <= right) {
				while ((array[left] < supportingElement) && (left <= right)) {
					left++;
				}
				while ((array[right] >= supportingElement) && (left <= right)) {
					right--;
				}
				if (left <= right) {
					swap(&array[left], &array[right]);
					left++;
					right--;
				}
			}
			smartQsort(array, start, right);
			smartQsort(array, left, end);
		}
	}
}

bool testInsert() {
	int array[] = { 8, 2, 4, 6, 1, 3, 7, 0, 5 };
	int resultingArray[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
	smartQsort(array, 0, 8);
	return comparingArrays(array, resultingArray, 9);
}

bool testQsort() {
	int array[] = { 12, 8, 25, 0, 3, 1, 35, 6, 10, 7, 15, 28, 49 };
	int resultingArray[] = { 0, 1, 3, 6, 7, 8, 10, 12, 15, 25, 28, 35, 49 };
	smartQsort(array, 0, 12);
	return comparingArrays(array, resultingArray, 13);
}

int main(void) {
	if (!testInsert() && !testQsort()) {
		printf("Test failed!\n");
		return -1;
	}
	int array[12] = { 0 };
	int size = 12;
	fillArray(array, size);
	printf("Original array: \n");
	printArray(array, size);
	printf("\n");
	smartQsort(array, 0, size - 1);
	printf("Sorted array: \n");
	printArray(array, size);
}

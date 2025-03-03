#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

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

void swap(int* left, int* right) {
	if (left != right) {
		*left ^= *right;
		*right ^= *left;
		*left ^= *right;
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

bool binarySearch(int array[], int size, int searchElement) {
	int left = 0;
	int right = size - 1;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (array[mid] == searchElement) {
			return true;
		}
		else if (array[mid] > searchElement) {
			right = mid - 1;
		}
		else if (array[mid] < searchElement) {
			left = mid + 1;
		}
	}
	return false;
}

void insertSort(int array[], int start, int end) {
	int newElement = 0;
	int location = 0;
	for (int i = start; i <= end; ++i) {
		newElement = array[i];
		location = i - 1;
		while (location >= 0 && array[location] > newElement) {
			array[location + 1] = array[location];
			location--;
		}
		array[location + 1] = newElement;
	}
}

void searchQsort(int array[], int start, int end) {
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
			searchQsort(array, start, right);
			searchQsort(array, left, end);
		}
	}
}

void searchingForNumbers() {
	int n = 0;
	int k = 0;
	printf("Enter the size of the array (n): ");
	scanf("%d", &n);
	printf("Enter the number of numbers to check (k): ");
	scanf("%d", &k);
	int* arrayToSearch = (int*)calloc(n, sizeof(int));
	int* checkNumbers = (int*)calloc(k, sizeof(int));
	if (arrayToSearch == NULL || checkNumbers == NULL) {
		printf("Memory allocation error\n");
		free(arrayToSearch);
		free(checkNumbers);
		return;
	}
	fillArray(arrayToSearch, n);
	searchQsort(arrayToSearch, 0, n - 1);
	printf("Array to search: ");
	printArray(arrayToSearch, n);
	fillArray(checkNumbers, k);
	for (int i = 0; i < k; i++) {
		if (binarySearch(arrayToSearch, n, checkNumbers[i])) {
			printf("\nThe number %d was found in the array", checkNumbers[i]);
		}
		else {
			printf("\nThe number %d wasn't found in the array", checkNumbers[i]);
		}
	}
	free(arrayToSearch);
	free(checkNumbers);
}

bool testBinarySearch() {
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	for (int i = 0; i < 8; i++) {
		if (!binarySearch(array, 8, array[i])) {
			return false;
		}
	}
	return true;
}

bool testSearchQsort() {
	int array[] = { 8, 2, 6, 5, 9, 3, 4, 1, 7 };
	int resultingArray[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	searchQsort(array, 0, 8);
	return comparingArrays(array, resultingArray, 9);
}

int main() {
	if (!testBinarySearch() && !testSearchQsort()) {
		printf("Test failed!\n");
		return -1;
	}
	searchingForNumbers();
	return 0;
}


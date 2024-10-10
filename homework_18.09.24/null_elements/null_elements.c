#include <stdio.h>

void countNullElements(int array[], int arraySize) {
	int countNullElements = 0;
	for (int i = 0; i < arraySize; i++) {
		if (array[i] == 0) {
			countNullElements++;
		}
	}
	printf("The number of zero elements in the array: %d\n", countNullElements);
}

int main(void) {
	int array[] = { 0, 1, 0, 4, 5, 0, 0, 0, 8, 0, 9, 3 };
	int arraySize = sizeof(array) / sizeof(array[0]);
	countNullElements(array, arraySize);
}
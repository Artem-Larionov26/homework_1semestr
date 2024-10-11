#include <stdio.h>

void swap(int* right, int* left) {
	if (right != left) {
		*left ^= *right;
		*right ^= *left;
		*left ^= *right;
	}
}

void twoVariants() {
	int a = 5, b = 3;
	swap(&a, &b);
	printf("The original version: a = 5, b = 3\nResult: a = %d, b = %d\n", a, b);
}

int main(void) {
	twoVariants();
}

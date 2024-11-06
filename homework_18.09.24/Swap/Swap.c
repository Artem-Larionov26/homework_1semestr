#include <stdio.h>

void swap(int* right, int* left) {
	if (right != left) {
		*left ^= *right;
		*right ^= *left;
		*left ^= *right;
	}
}

void twoVariants() {
	int a = 5, 
		b = 3;
	swap(&a, &b);
	printf("The original version: a = 5, b = 3\nResult: a = %d, b = %d\n", a, b);
}

void runTests() {
	int test1_a = 5,
		test1_b = 10;
	int test2_a = -3,
		test2_b = 7;
	int test3_a = 0,
		test3_b = 0;
	int test4_a = 100,
		test4_b = -100;

	swap(&test1_a, &test1_b);
	printf("Test 1: a = 5, b = 10 -> after the exchange a = %d, b = %d\n", test1_a, test1_b);
	swap(&test2_a, &test2_b);
	printf("Test 2: a = -3, b = 7 -> after the exchange a = %d, b = %d\n", test2_a, test2_b);
	swap(&test3_a, &test3_b);
	printf("Test 3: a = 0, b = 0 -> after the exchange a = %d, b = %d\n", test3_a, test3_b);
	swap(&test4_a, &test4_b);
	printf("Test 4: a = 100, b = -100 -> after the exchange a = %d, b = %d\n", test4_a, test4_b);
}

int main(void) {
	twoVariants();
	runTests();
	return 0;
}

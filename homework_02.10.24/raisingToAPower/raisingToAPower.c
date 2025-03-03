#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

double powerLinear(int base, int degree) {
	double result = 1;
	for (int i = 0; i < abs(degree); i++) {
		result *= base;
	}
	if (degree >= 0) {
		return result;
	} else {
		return (1 / result);
	}
}

double powerFast(int base, int degree) {
	double result = 1;
	int degreeAbs = abs(degree);
	while (degreeAbs) {
		if (degreeAbs % 2 == 0) {
			degreeAbs /= 2;
			base *= base;
		} else {
			degreeAbs--;
			result *= base;
		}
	}
	if (degree >= 0) {
		return result;
	} else {
		return (1 / result);
	}
}

void testPower(int base, int degree) {
	double linearResult = powerLinear(base, degree);
	double fastResult = powerFast(base, degree);
	printf("Base: %d, Degree: %d\n", base, degree);
	printf("Linear power result: %f\n", linearResult);
	printf("Fast power result: %f\n", fastResult);
	if (linearResult == fastResult) {
		printf("Test passed!\n");
	} else {
		printf("Test failed!\n");
	}
}

int main(void) {
	printf("Testing power functions:\n");
	testPower(2, 10);
	testPower(2, -3);
	testPower(5, 0);
	testPower(-2, 3);
	testPower(-2, 4);
	testPower(0, 8);
	testPower(0, 0);
	return 0;
}

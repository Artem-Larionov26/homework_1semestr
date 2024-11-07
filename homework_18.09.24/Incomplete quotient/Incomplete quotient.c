#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int incompleteQuotient(int a, int b) {
	if (b == 0) {
		printf("Error: division by zero!\n");
		exit(EXIT_FAILURE);
	}
	int quotient = 0;
	int negativeResult = 0;
	if (a < 0) {
		a = -a;
		negativeResult = !negativeResult;
	}
	if (b < 0) {
		b = -b;
		negativeResult = !negativeResult;
	}
	while (a >= b) {
		a = a - b;
		quotient++;
	}
	if (negativeResult) {
		quotient = -quotient;
	}
	return quotient;
}

void runTests() {
	printf("Test 1: 10 / 3 = %d (3 is expected)\n", incompleteQuotient(10, 3));
	printf("Test 2: -10 / 3 = %d (-3 is expected)\n", incompleteQuotient(-10, 3));
	printf("Test 3: 10 / -3 = %d (-3 is expected)\n", incompleteQuotient(10, -3));
	printf("Test 4: -10 / -3 = %d (3 is expected)\n", incompleteQuotient(-10, -3));
	printf("Test 5: 7 / 1 = %d (7 is expected)\n", incompleteQuotient(7, 1));
	printf("Test 6: 0 / 5 = %d (0 is expected)\n", incompleteQuotient(0, 5));
	printf("Test 7: 5 / -1 = %d (-5 is expected)\n", incompleteQuotient(5, -1));
	printf("Test 8: 5 / 0 (error is expected)\n");
	incompleteQuotient(5, 0);
}

int main() {
	setlocale(LC_ALL, "Rus");
	int result = incompleteQuotient(18, -8);
	printf("Incomplete quotient: %d\n", result);
	runTests();
	return 0;
}
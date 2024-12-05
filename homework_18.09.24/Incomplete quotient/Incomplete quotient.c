#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int incompleteQuotient(int a, int b, int* error) {
	if (b == 0) {
		*error = 1;
		return 0;
	}
	*error = 0;
	int quotient = 0;
	int devidend = fabs(a);
	int devider = fabs(b);
	while (devidend >= devider) {
		devidend = devidend - devider;
		quotient++;
	}
	if ((a >= 0 && b > 0) || (a < 0 && b < 0)) {
		return quotient;
	} else if (devidend == 0 || b < 0) {
		return -quotient;
	} else {
		return -quotient - 1;
	}
}

void runTests() {
	int error = 0;
	printf("Test 1: 10 / 3 = %d (3 is expected)\n", incompleteQuotient(10, 3, &error));
	printf("Test 2: -10 / 3 = %d (-4 is expected)\n", incompleteQuotient(-10, 3, &error));
	printf("Test 3: 10 / -3 = %d (-4 is expected)\n", incompleteQuotient(10, -3, &error));
	printf("Test 4: -10 / -3 = %d (3 is expected)\n", incompleteQuotient(-10, -3, &error));
	printf("Test 5: 7 / 1 = %d (7 is expected)\n", incompleteQuotient(7, 1, &error));
	printf("Test 6: 0 / 5 = %d (0 is expected)\n", incompleteQuotient(0, 5, &error));
	printf("Test 7: 5 / -1 = %d (-5 is expected)\n", incompleteQuotient(5, -1, &error));
	printf("Test 8: 5 / 0 (error is expected)\n");
	incompleteQuotient(5, 0, &error);
	if (error == 1) {
		printf("Error: division by zero! Please change the divider.\n");
	}
}

int main() {
	int error = 0;
	runTests();
	int result = incompleteQuotient(18, -8, &error);
	if (error != 0) {
		printf("Error: division by zero! Please change the divider.\n");
	} else {
		printf("Incomplete quotient: %d\n", result);
	}
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>
#include <math.h>

int incompleteQuotient(int a, int b) {
    if (b == 0) {
        printf("Error: division by zero!\n");
        return 0;
    }
    int dividend = fabs(a);
    int divider = fabs(b);
    int quotient = 0;
    while (dividend >= divider) {
        dividend -= divider;
        quotient++;
    }
    if ((a >= 0 && b > 0) || (a < 0 && b < 0 && dividend == 0)) {
        return quotient;
    }
    else if (a < 0 && b < 0 && dividend != 0) {
        return quotient + 1;
    }
    else if ((dividend == 0) || (b < 0)) {
        return -quotient;
    }
    else {
        return -quotient - 1;
    }
}

bool runTests(void) {
    if (incompleteQuotient(10, 3) != 3) {
        return false;
    }
    if (incompleteQuotient(-10, 3) != -4) {
        return false;
    }
    if (incompleteQuotient(10, -3) != -3) {
        return false;
    }
    if (incompleteQuotient(-10, -3) != 4) {
        return false;
    }
    if (incompleteQuotient(7, 1) != 7) {
        return false;
    }
    if (incompleteQuotient(0, 5) != 0) {
        return false;
    }
    if (incompleteQuotient(5, -1) != -5) {
        return false;
    }
    if (incompleteQuotient(-5, 5) != -1) {
        return false;
    }
    return true;
}

int main(void) {
	setlocale(LC_ALL, "Rus");
	if (!runTests()) {
        printf("Some tests failed! Program won't run.\n");
        return 0;
    }
    int result = incompleteQuotient(20, -3);
    printf("Incomplete quotient: %d\n", result);
    return 0;
}

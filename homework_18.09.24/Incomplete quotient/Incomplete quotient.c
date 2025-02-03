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

    int runTests() {
	    if (incompleteQuotient(10, 3) != 3) return 0;
	    if (incompleteQuotient(-10, 3) != -3) return 0;
	    if (incompleteQuotient(10, -3) != -3) return 0;
	    if (incompleteQuotient(-10, -3) != 3) return 0;
	    if (incompleteQuotient(7, 1) != 7) return 0;
	    if (incompleteQuotient(0, 5) != 0) return 0;
	    if (incompleteQuotient(5, -1) != -5) return 0;
	    if (incompleteQuotient(-5, 5) != -1) return 0;
	    return 1;
    }

    int main() {
	    setlocale(LC_ALL, "Rus");
	    if (!runTests()) {
		    printf("Some tests failed! Program won't run.\n");
		    return 0;
	    }
	    int result = incompleteQuotient(18, -8);
	    printf("Incomplete quotient: %d\n", result);
	    return 0;
    }
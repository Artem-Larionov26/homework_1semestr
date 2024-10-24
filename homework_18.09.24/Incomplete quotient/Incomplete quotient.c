#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int incompleteQuotient(int a, int b) {
	if (b == 0) {
		printf("Ошибка: деление на ноль!\n");
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

int main() {
	setlocale(LC_ALL, "Rus");
	int result = incompleteQuotient(18, -8);
	printf("Неполное частное: %d\n", result);
}
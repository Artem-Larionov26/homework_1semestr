#include<stdio.h>
#include<stdbool.h>

bool isPrime(int num) {
	if (num <= 1) {
		return false;
	}
	for (int i = 2; i * i <= num; i++) {
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}

void primeNumbers(int n) {
	printf("Prime numbers not exceeding %d:\n", n);
	int quantityNumbers = 0;
	for (int i = 2; i <= n; i++) {
		if (isPrime(i)) {
			printf("%d ", i);
			quantityNumbers++;
		}
	}
	if (quantityNumbers == 0) {
		printf("There are no prime numbers\n");
	} else {
		printf("\n");
	}
}

void runTests() {
	printf("Test 1: n = 10\n");
	primeNumbers(10);

	printf("Test 2: n = 20\n");
	primeNumbers(20);

	printf("Test 3: n = 1\n");
	primeNumbers(1);

	printf("Test 4: n = 2\n");
	primeNumbers(2);

	printf("Test 5: n = 0\n");
	primeNumbers(0);

	printf("Test 6: n = 30\n");
	primeNumbers(30);
}

int main() {
	primeNumbers(100);
	runTests();
	return 0;
}
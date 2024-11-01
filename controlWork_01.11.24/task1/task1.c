#include <stdio.h>
#include <stdbool.h>

bool Palindrome(int num) {
	if (num < 0) {
		return false;
	}
	int reversed = 0;
	int original = num;
	while (num != 0) {
		int digit = num % 10;
		reversed = reversed * 10 + digit;
		num /= 10;
	}
	return original == reversed;
}

int main() {
	int num;
	printf("Enter a number: ");
	scanf("%d", &num);
	if (Palindrome(num)) {
		printf("The number %d is a palindrome \n", num);
	} else {
		printf("The number %d isn't a palindrome \n", num);
	}
	return 0;
}

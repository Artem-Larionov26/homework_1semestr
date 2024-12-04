#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isBalanced(const char* str) {
	int balance = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == '(') {
			balance++;
		} else if (str[i] == ')') {
			balance--;
		}
		if (balance < 0) {
			return false;
		}
	}
	return balance == 0;
}

void runTests() {
	const char* tests[] = {
		"()",
		"(())",
		"((()))",
		"(()))",
		"((())",
		"()",
		"(()(()))",
		"(()",
		")",
		"(",
	};
	bool expected[] = { true, true, true, false, false, true, true, false, false, false };
	const int numTests = 10;
	for (int i = 0; i < numTests; i++) {
		bool result = isBalanced(tests[i]);
		printf("Test %d: string \"%s\" -> %s (expected %s)\n", i + 1, tests[i], result ? "Balanced" : "Unbalanced", expected[i] ? "Balanced" : "Unbalanced");
	}
}

int main() {
	runTests();
	char stringForTheUser[100];
	printf("Enter a string to check the balance of the brackets: ");
	if (fgets(stringForTheUser, sizeof(stringForTheUser), stdin)) {
		size_t len = strlen(stringForTheUser);
		if (len > 0 && stringForTheUser[len - 1] == '\n') {
			stringForTheUser[len - 1] = '\0';
		}
	}
	printf("The entered string: %s\n", stringForTheUser);
	if (isBalanced(stringForTheUser)) {
		printf("The brackets are balanced!\n");
	} else {
		printf("The brackets aren't balanced!\n");
	}
	return 0;
}
#include<stdio.h>
#include<stdbool.h>
#include<string.h>

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
	int numTests = 10;
	for (int i = 0; i < numTests; i++) {
		bool result = isBalanced(tests[i]);
		printf("Test %d: string \"%s\" -> %s (expected %s)\n", i + 1, tests[i], result ? "Balanced" : "Unbalanced", expected[i] ? "Balanced" : "Unbalanced");
	}
}

int main() {
	char example[] = {"(())()))"};
	printf("The original string: %s\n", example);
	if (isBalanced(example)) {
		printf("The brackets are balanced\n");
	} else {
		printf("The brackets are unbalanced\n");
	}
	runTests();
	return 0;
}
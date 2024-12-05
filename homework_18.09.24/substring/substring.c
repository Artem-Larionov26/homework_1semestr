#include <stdio.h>
#include <string.h>

int numberOfOccurrences(const char* s, const char* s1) {
	int counter = 0;
	int lenS = strlen(s);
	int lenS1 = strlen(s1);
	for (int i = 0; i <= lenS - lenS1; i++) {
		int flag = 1;
		for (int j = 0; j < lenS1; j++) {
			if (s[i + j] != s1[j]) {
				flag = 0;
				break;
			}
		}
		if (flag == 1) {
			counter++;
		}
	}
	return counter;
}

void runTests() {
	if (numberOfOccurrences("abcabcabc", "abc") == 3) {
		printf("Test 1 passed!\n");
	} else {
		printf("Test 1 failed!\n");
	}
	if (numberOfOccurrences("hellohellohello", "lo") == 3) {
		printf("Test 2 passed!\n");
	} else {
		printf("Test 2 failed!\n");
	}
	if (numberOfOccurrences("aaaaaa", "aa") == 5) {
		printf("Test 3 passed!\n");
	} else {
		printf("Test 3 failed!\n");
	}
	if (numberOfOccurrences("abcd", "e") == 0) {
		printf("Test 4 passed!\n");
	} else {
		printf("Test 4 failed!\n");
	}
	if (numberOfOccurrences("abcdabcd", "abcd") == 2) {
		printf("Test 5 passed!\n");
	} else {
		printf("Test 5 failed!\n");
	}
	if (numberOfOccurrences("abbaaaababbbab", "ab") == 4) {
		printf("Test 6 passed!\n");
	} else {
		printf("Test 6 failed!\n");
	}
	if (numberOfOccurrences("", "a") == 0) {
		printf("Test 7 passed!\n");
	} else {
		printf("Test 7 failed!\n");
	}
}

int main() {
	runTests();
	char s[100];
	char s1[100];
	printf("Enter the main string: ");
	fgets(s, sizeof(s), stdin);
	s[strcspn(s, "\n")] = '\0';
	printf("Enter the substring: ");
	fgets(s1, sizeof(s1), stdin);
	s1[strcspn(s1, "\n")] = '\0';
	int occurrences = numberOfOccurrences(s, s1);
	printf("The number of occurrences of the string %s in string %s : %d\n", s1, s, occurrences);
	return 0;
}

#include<stdio.h>
#include<string.h>

int numberOfOccurrences(const char* S, const char* S1) {
	int counter = 0;
	int lenS = strlen(S);
	int lenS1 = strlen(S1);
	for (int i = 0; i <= lenS - lenS1; i++) {
		int flag = 1;
		for (int j = 0; j < lenS1; j++) {
			if (S[i + j] != S1[j]) {
				flag = 0;
				break;
			}
		}
		if (flag) {
			counter++;
		}
	}
	return counter;
}

void runTests() {
	printf("Test 1: %s in %s : %d\n", "abc", "abcabcabc", numberOfOccurrences("abcabcabc", "abc"));
	printf("Expected : 3\n");
	printf("Test 2: %s in %s : %d\n", "lo", "hellohellohello", numberOfOccurrences("hellohellohello", "lo"));
	printf("Expected : 3\n");
	printf("Test 3: %s in %s : %d\n", "aa", "aaaaaa", numberOfOccurrences("aaaaaa", "aa"));
	printf("Expected : 5\n");
	printf("Test 4: %s in %s : %d\n", "e", "abcd", numberOfOccurrences("abcd", "e"));
	printf("Expected : 0\n");
	printf("Test 5: %s in %s : %d\n", "abcd", "abcdabcd", numberOfOccurrences("abcdabcd", "abcd"));
	printf("Expected : 2\n");
	printf("Test 6: %s in %s : %d\n", "ab", "abbaaaababbbab", numberOfOccurrences("abbaaaababbbab", "ab"));
	printf("Expected : 4\n");
	printf("Test 7: %s in %s : %d\n", "a", "", numberOfOccurrences("", "a"));
	printf("Expected : 0\n");
}

int main() {
	char S[] = { "abcabcabcabc" };
	char S1[] = { "abc" };
	int occurrences = numberOfOccurrences(S, S1);
	printf("The number of occurrences of the string %s in string %s : %d\n", S1, S, occurrences);
	runTests();
	return 0;
}

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int calculate_sums(int numbers[28]) {
	for (int i = 0; i <= 9; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int k = 0; k <= 9; k++) {
				int sum = i + j + k;
				numbers[sum]++;
			}
		}
	}
	int lucky_tickets = 0;
	for (int sum = 0; sum < 28; sum++) {
		lucky_tickets += numbers[sum] * numbers[sum];
	}
	return lucky_tickets;
}

bool test_calculate_sums() {
	int numbers[28] = { 0 };
	calculate_sums(numbers);
	if (numbers[0] != 1)
		return false;
	if (numbers[6] != 28)
		return false;
	if (numbers[27] != 1)
		return false;
	return true;
}


int main(void) {
	if (test_calculate_sums()) {
		printf("Test function passed!\n");
	} else {
		printf("Error in the function calculate_sums!\n");
	}
	int numbers[28] = { 0 };
	int answer = calculate_sums(numbers);
	printf("Lucky tickets: %d\n", answer);
	return 0;
}


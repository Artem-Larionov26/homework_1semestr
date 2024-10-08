#include <stdio.h>
#include <stdbool.h>

void calculate_sums(int numbers[28]) {
	for (int i = 0; i <= 9; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int k = 0; k <= 9; k++) {
				int sum = i + j + k;
				numbers[sum]++;
			}
		}
	}
}


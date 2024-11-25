#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<locale.h>

bool comparingArrays(int array1[], int array2[], int size) {
	for (int i = 0; i < size; i++) {
		if (array1[i] != array2[i]) {
			return false;
		}
	}
	return true;
}

float exponentiation(int base, int degree) {
	float result = 1;
	int degreeAbs = abs(degree);
	while (degreeAbs) {
		if (degreeAbs % 2 == 0) {
			degreeAbs /= 2;
			base *= base;
		} else {
			degreeAbs--;
			result *= base;
		}
	}
	if (degree >= 0) {
		return result;
	} else {
		return (1 / result);
	}
}

void conversionToBinarySystem(int number, char* binaryNumber) {
	int mask = 1;
	for (int i = (sizeof(int) * 8) - 1; i >= 0; i--) {
		binaryNumber[i] = number & mask ? '1' : '0';
		mask = mask << 1;
	}
	binaryNumber[(sizeof(int) * 8)] = '\0';
}

int conversionToDecimalSystem(char* binaryNumber) {
	int result = 0;
	int index = 0;
	while (binaryNumber[index] != '\0') {
		if (binaryNumber[index] == '1') {
			result += exponentiation(2, (sizeof(int) * 8) - 1 - index);
		}
		index++;
	}
	return result;
}

void additionOfBinaryNumbers(char* firstBinaryNumber, char* secondBinaryNumber, char* binarySum) {
	bool nextRank = false;
	for (int i = (sizeof(int) * 8) - 1; i >= 0; i--) {
		if (firstBinaryNumber[i] == '1' && secondBinaryNumber[i] == '1') {
			binarySum[i] = nextRank ? '1' : '0';
			nextRank = true;
		} else if ((firstBinaryNumber[i] == '1' && secondBinaryNumber[i] == '0') || (firstBinaryNumber[i] == '0' && secondBinaryNumber[i] == '1')) {
			binarySum[i] = nextRank ? '0' : '1';
		} else if (firstBinaryNumber[i] == '0' && secondBinaryNumber[i] == '0') {
			if (nextRank) {
				binarySum[i] = '1';
				nextRank = false;
			} else {
				binarySum[i] = '0';
			}
		}
	}
	binarySum[sizeof(int) * 8] = '\0';
}

bool testExponentiation() {
	return ((exponentiation(2, 3) == 8) && (exponentiation(8, 0) == 1) && (exponentiation(2, -2) == 0.25) && (exponentiation(-2, 3) == -8));
}

bool testConversionToDecimalSystem() {
	char binary1[] = "00000000000000000000000000000101";
	char binary2[] = "11111111111111111111111111111011";
	return ((conversionToDecimalSystem(binary1) == 5) && (conversionToDecimalSystem(binary2) == -5));
}

bool testConversionToBinarySystem() {
	int number1 = 5;
	int number2 = -5;
	char binary1[(sizeof(int) * 8) + 1];
	char binary2[(sizeof(int) * 8) + 1];
	conversionToBinarySystem(number1, binary1);
	conversionToBinarySystem(number2, binary2);
	return ((conversionToDecimalSystem(binary1) == number1) && (conversionToDecimalSystem(binary2) == number2));
}

bool testAdditionOfBinaryNumbers() {
	int number1 = 5;
	int number2 = -8;
	char binary1[(sizeof(int) * 8) + 1];
	char binary2[(sizeof(int) * 8) + 1];
	char binarySum[(sizeof(int) * 8) + 1];
	conversionToBinarySystem(number1, binary1);
	conversionToBinarySystem(number2, binary2);
	additionOfBinaryNumbers(binary1, binary2, binarySum);
	return (conversionToDecimalSystem(binarySum) == number1 + number2);
}

bool runTests() {
	return testExponentiation() && testConversionToDecimalSystem() && testConversionToBinarySystem() && testAdditionOfBinaryNumbers();
}

int main(void) {
	setlocale(LC_ALL, "Rus");
	if (!runTests()) {
		printf("Тесты не прошли!\n");
		return -1;
	}
	printf("Тесты пройдены успешно!");
	int firstNumber = 0;
	int secondNumber = 0;
	char firstBinaryNumber[(sizeof(int) * 8) + 1];
	char secondBinaryNumber[(sizeof(int) * 8) + 1];
	char binarySum[(sizeof(int) * 8) + 1];
	printf("Введите первое число: ");
	scanf_s("%d", &firstNumber);
	printf("Введите второе число: ");
	scanf_s("%d", &secondNumber);
	conversionToBinarySystem(firstNumber, firstBinaryNumber);
	printf("Двоичное представление первого числа: \n%s", firstBinaryNumber);
	printf("\n");
	conversionToBinarySystem(secondNumber, secondBinaryNumber);
	printf("Двоичное представление второго числа: \n%s", secondBinaryNumber);
	printf("\n");
	additionOfBinaryNumbers(firstBinaryNumber, secondBinaryNumber, binarySum);
	printf("Сумма чисел в двоичном виде: \n%s", binarySum);
	printf("\n");
	printf("Сумма чисел в десятичном виде: \n%d", conversionToDecimalSystem(binarySum));
	return 0;
}
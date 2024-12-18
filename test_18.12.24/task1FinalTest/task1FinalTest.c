#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


bool binaryToDecimal(const char* binary_string, int* decimal_value) {
    if (binary_string == NULL || decimal_value == NULL) {
        return false; // Ошибка: передан NULL-указатель
    }
    *decimal_value = 0; // Инициализация результата
    size_t length = strlen(binary_string);
    for (size_t i = 0; i < length; i++) {
        if (binary_string[i] != '0' && binary_string[i] != '1') {
            return false; // Ошибка: строка содержит недопустимые символы
        }
        *decimal_value = *decimal_value * 2 + (binary_string[i] - '0');
    }
    return true; // Успешное выполнение
}

// Тестирование функции binaryToDecimal
void runTests() {
    int decimal_value;
    // Тест 1: Простое преобразование
    if (binaryToDecimal("101", &decimal_value) && decimal_value == 5) {
        printf("Test 1 passed.\n");
    }
    else {
        printf("Test 1 failed.\n");
    }
    // Тест 2: Преобразование нуля
    if (binaryToDecimal("0", &decimal_value) && decimal_value == 0) {
        printf("Test 2 passed.\n");
    }
    else {
        printf("Test 2 failed.\n");
    }
    // Тест 3: Преобразование единицы
    if (binaryToDecimal("1", &decimal_value) && decimal_value == 1) {
        printf("Test 3 passed.\n");
    }
    else {
        printf("Test 3 failed.\n");
    }
    // Тест 4: Большое число
    if (binaryToDecimal("110010", &decimal_value) && decimal_value == 50) {
        printf("Test 4 passed.\n");
    }
    else {
        printf("Test 4 failed.\n");
    }
    // Тест 5: Недопустимые символы
    if (!binaryToDecimal("102", &decimal_value)) {
        printf("Test 5 passed.\n");
    }
    else {
        printf("Test 5 failed.\n");
    }
    // Тест 6: NULL строка
    if (!binaryToDecimal(NULL, &decimal_value)) {
        printf("Test 6 passed.\n");
    }
    else {
        printf("Test 6 failed.\n");
    }
    // Тест 7: Пустая строка
    if (!binaryToDecimal("", &decimal_value)) {
        printf("Test 7 passed.\n");
    }
    else {
        printf("Test 7 failed.\n");
    }
}

int main() {
    printf("Run tests:\n");
    runTests();
    char binary_string[33]; // Максимальная длина для 32-битного числа
    int decimal_value;
    printf("Enter a binary number: ");
    if (fgets(binary_string, sizeof(binary_string), stdin) == NULL) {
        printf("Input error!\n");
        return 1;
    }
    size_t length = strlen(binary_string);
    if (length > 0 && binary_string[length - 1] == '\n') {
        binary_string[length - 1] = '\0';
    }
    if (binaryToDecimal(binary_string, &decimal_value)) {
        printf("Decimal value: %d\n", decimal_value);
    }
    else {
        printf("Error: an incorrect string was entered!\n");
    }
    return 0;
}

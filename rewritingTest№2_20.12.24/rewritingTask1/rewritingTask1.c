#include <stdio.h>
#include <stdlib.h>

// Функция для записи чисел из одной группы в файл
void writeGroupToFile(FILE* inputFile, FILE* outputFile, int a, int b, int group) {
    rewind(inputFile); // Возвращаем указатель файла в начало
    int number;
    int first = 1;  // Используется для того, чтобы не ставить пробел перед первым числом

    while (fscanf_s(inputFile, "%d", &number) == 1) {
        // Определяем, к какой группе принадлежит число
        if ((group == 1 && number < a) ||
            (group == 2 && number >= a && number <= b) ||
            (group == 3 && number > b)) {
            // Если это не первое число, ставим пробел перед ним
            if (!first) {
                fprintf(outputFile, " ");
            }
            fprintf(outputFile, "%d", number);
            first = 0; // Следующее число будет не первым
        }
    }
}

int main() {
    // Открытие файлов
    FILE* inputFile = fopen("f.txt", "r");
    if (!inputFile) {
        perror("Error opening input file");
        return EXIT_FAILURE;
    }
    FILE* outputFile = fopen("g.txt", "w");
    if (!outputFile) {
        perror("Error opening output file");
        fclose(inputFile);
        return EXIT_FAILURE;
    }
    // Ввод a и b
    int a, b;
    printf("Enter a and b: ");
    if (scanf_s("%d %d", &a, &b) != 2) {
        printf(stderr, "Invalid input\n");
        fclose(inputFile);
        fclose(outputFile);
        return EXIT_FAILURE;
    }
    //Переписывание чисел по группам
    writeGroupToFile(inputFile, outputFile, a, b, 1);
    fprintf(outputFile, "\n");
    writeGroupToFile(inputFile, outputFile, a, b, 2);
    fprintf(outputFile, "\n");
    writeGroupToFile(inputFile, outputFile, a, b, 3);
    // Закрытие файлов
    fclose(inputFile);
    fclose(outputFile);
    printf("Numbers have been successfully rearranged in g.txt\n");
    return EXIT_SUCCESS;
}
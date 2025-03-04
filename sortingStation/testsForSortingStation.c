#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "sortingStation.h"
#include "testsForSortingStation.h"

bool testForIsDigit() {
    return isDigit('0') && isDigit('1') && isDigit('2') &&
        isDigit('3') && isDigit('4') && isDigit('5') &&
        isDigit('6') && isDigit('7') && isDigit('8') &&
        isDigit('9') && !isDigit('g') && !isDigit(')') &&
        !isDigit('@') && !isDigit('#') && !isDigit('_');
}

bool testForIsOperator() {
    return isOperator('+') &&
        isOperator('-') &&
        isOperator('*') &&
        isOperator('/') &&
        !isOperator('s') &&
        !isOperator('(') &&
        !isOperator('[') &&
        !isOperator('_') &&
        !isOperator('.') &&
        !isOperator('#');
}

bool testForPriority() {
    return (priority('+') == 1 && priority('-') == 1) &&
        (priority('*') == 2 && priority('/') == 2) &&
        (priority('(') == 0 && priority(')') == 0) &&
        (priority(']') == 0 && priority('[') == 0) &&
        (priority('#') == 0 && priority('%') == 0) &&
        (priority('>') == 0 && priority('<') == 0);
}

bool testForSortingStation() {
    char* firstResultForTest = sortingStation("2 + 7");
    if (strcmp(firstResultForTest, "2 7 + ") != 0) {
        free(firstResultForTest);
        return false;
    }
    free(firstResultForTest);

    char* secondResultForTest = sortingStation("(6 + 4) * 8");
    if (strcmp(secondResultForTest, "6 4 + 8 * ") != 0) {
        free(secondResultForTest);
        return false;
    }
    free(secondResultForTest);

    char* thirdResultForTest = sortingStation("(8 + 9) * (1 + 2)");
    if (strcmp(thirdResultForTest, "8 9 + 1 2 + * ") != 0) {
        free(thirdResultForTest);
        return false;
    }
    free(thirdResultForTest);

    char* fourthResultForTest = sortingStation("40 / (5 + 3)");
    if (strcmp(fourthResultForTest, "40 5 3 + / ") != 0) {
        free(fourthResultForTest);
        return false;
    }
    free(fourthResultForTest);

    return true;
}
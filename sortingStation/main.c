#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sortingStation.h"
#include "testsForSortingStation.h"
#include "stack.h"
#include "testStack.h"

int main(void) {
    if (!testCreateStack() || !testIsEmpty() || !testPop() || !testPush() || !testGetValue()) {
        printf("Stack failed the tests!\n");
        return 1;
    }
    if (!testForIsDigit() || !testForSortingStation() || !testForIsOperator() || !testForPriority()) {
        printf("The main functions failed the tests!\n");
        return 1;
    }

    char string[100] = " ";
    printf("Enter the expression in the infix form: ");
    fgets(string, sizeof(string), stdin);
    string[strcspn(string, "\n")] = '\0';
    char* output = sortingStation(string);
    printf("%s\n", output);
    free(output);
}
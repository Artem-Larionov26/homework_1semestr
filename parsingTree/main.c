#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "parsingTree.h"
#include "tests.h"

int main() {
    if (!testTree()) {
        printf("Test failed!\n");
        return 1;
    }
    int errorCode = 0;
    char* inputString = calloc(100, sizeof(char));
    if (inputString == NULL) {
        printf("Memory allocation error!\n");
        return 1;
    }
    FILE* file = fopen("fileForTask.txt", "r");
    if (fgets(inputString, 100, file) == NULL) {
        free(inputString);
        printf("The file is empty!\n");
        return 0;
    }
    int index = 0;
    Node* parseTree = separateArithmeticExpression(inputString, &index, &errorCode);
    int result = calculate(parseTree, &errorCode);
    switch (errorCode) {
    case 0:
        printf("Parse tree: ");
        printTree(parseTree);
        printf("\n");
        printf("Expression value: %d\n", result);
        return 0;
    case 1:
        printf("Memory allocation error!\n");
        return 1;
    case 2:
        printf("Division by zero!\n");
        return 2;
    }
}
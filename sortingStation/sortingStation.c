#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "stack.h"
#include "sortingStation.h"

bool isDigit(char element) {
    return element == '0' || element == '1' || element == '2' || element == '3' || element == '4' ||
        element == '5' || element == '6' || element == '7' || element == '8' || element == '9';
}

bool isOperator(char element) {
    return element == '+' || element == '-' || element == '*' || element == '/';
}

int priority(char operator) {
    if (operator == '+' || operator == '-') {
        return 1;
    }
    if (operator == '*' || operator == '/') {
        return 2;
    }
    return 0;
}

char* sortingStation(char* string) {
    Stack* stackForOperators = createStack();
    char* output = malloc(strlen(string) * 2 + 1);
    if (output == NULL) {
        return NULL;
    }
    int index = 0; //for output
    int k = 0; //for input

    while (k < strlen(string)) {
        if (string[k] == ' ') {
            k++;
            continue;
        }

        if (isDigit(string[k])) {
            while (k < strlen(string) && isDigit(string[k])) {
                output[index] = string[k];
                k++;
                index++;
            }
            output[index] = ' ';
            index++;
        }

        else if (string[k] == '(') {
            push(stackForOperators, string[k]);
            k++;
        }
        else if (string[k] == ')') {
            while (!isEmpty(stackForOperators) && stackForOperators->head->value != '(') {
                output[index] = pop(stackForOperators);
                index++;
                output[index] = ' ';
                index++;
            }
            if (!isEmpty(stackForOperators) && stackForOperators->head->value == '(') {
                pop(stackForOperators);
            }
            k++;
        }

        else if (isOperator(string[k])) {
            while (!isEmpty(stackForOperators) && priority(stackForOperators->head->value) >= priority(string[k])) {
                output[index] = pop(stackForOperators);
                index++;
                output[index] = ' ';
                index++;
            }
            push(stackForOperators, string[k]);
            k++;
        }
    }
    while (!isEmpty(stackForOperators)) {
        output[index] = pop(stackForOperators);
        index++;
        output[index] = ' ';
        index++;
    }
    output[index] = '\0';

    free(stackForOperators);
    return output;
}
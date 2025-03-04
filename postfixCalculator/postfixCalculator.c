#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "postfixCalculator.h"  
#include "stack.h"

bool isDigit(char element) {
    return element == '0' || element == '1' || element == '2' || element == '3' || element == '4' ||
        element == '5' || element == '6' || element == '7' || element == '8' || element == '9';
}

void takeElementsFromStack(Stack* stack, int* number1, int* number2, int* numberOfElementsInTheStack) {
    *number2 = getValue(stack);
    pop(stack);
    *number1 = getValue(stack);
    pop(stack);
    *numberOfElementsInTheStack -= 2;
}

int postfixCalculator(char* string, int* errorCode) {
    Stack* stack = createStack();
    int numberOfElementsInTheStack = 0;
    int indexCounter = 0;
    while (string[indexCounter] != '\0') {
        while (string[indexCounter] == ' ') {
            ++indexCounter;
        }
        if ((string[indexCounter] == '+' || string[indexCounter] == '-'
            || string[indexCounter] == '*' || string[indexCounter] == '/')) {
            if (numberOfElementsInTheStack < 2) {
                *errorCode = 1;
                return -1;
            }
            int number1 = 0;
            int number2 = 0;
            switch (string[indexCounter]) {
            case '+':
                takeElementsFromStack(stack, &number1, &number2, &numberOfElementsInTheStack);
                push(stack, number1 + number2);
                ++numberOfElementsInTheStack;
                break;
            case '-':
                takeElementsFromStack(stack, &number1, &number2, &numberOfElementsInTheStack);
                push(stack, number1 - number2);
                ++numberOfElementsInTheStack;
                break;
            case '*':
                takeElementsFromStack(stack, &number1, &number2, &numberOfElementsInTheStack);
                push(stack, number1 * number2);
                ++numberOfElementsInTheStack;
                break;
            case '/':
                takeElementsFromStack(stack, &number1, &number2, &numberOfElementsInTheStack);
                if (number2 == 0) {
                    *errorCode = 2;
                    return -1;
                }
                push(stack, number1 / number2);
                ++numberOfElementsInTheStack;
                break;
            default:
                break;
            }
        }
        else {
            if (!isDigit(string[indexCounter])) {
                *errorCode = 1;
                return -1;
            }
            int number = string[indexCounter] - '0';
            push(stack, number);
            ++numberOfElementsInTheStack;
        }
        ++indexCounter;
    }
    if (numberOfElementsInTheStack != 1) {
        *errorCode = 1;
        return -1;
    }
    int result = getValue(stack);
    deleteStack(stack);
    return result;
}
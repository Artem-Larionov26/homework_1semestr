#pragma once

#include <stdbool.h>
#include "stack.h"

// Function that checks whether an element is a number
bool isDigit(char element);

// Function that takes elements from the stack
void takeElementsFromStack(Stack* stack, int* number1, int* number2, int* numberOfElementsInTheStack);

// Function that evaluates an expression in reverse Polish notation
int postfixCalculator(char* string, int* errorCode);
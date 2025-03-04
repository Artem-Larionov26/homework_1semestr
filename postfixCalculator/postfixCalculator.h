#pragma once

#include <stdbool.h>
#include "stack.h"

bool isDigit(char element);

void takeElementsFromStack(Stack* stack, int* number1, int* number2, int* numberOfElementsInTheStack);

int postfixCalculator(char* string, int* errorCode);
#pragma once

#include <stdbool.h>

// Function that checks whether an element is a number
bool isDigit(char element);

// Function that checks whether an element is an operator
bool isOperator(char element);

// Function that determines the operator's priority
// Operators '+' and '-' have priority 1, '*' and '/' have priority 2.
// If the symbol is not an operator, 0 is returned.
int priority(char operator);

// Function that converts a string with an infix notation to a string with a prefix notation
char* sortingStation(char* string);
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "stack/stack.h"

bool haveBrackets(char* string) {
    for (size_t i = 0; i < strlen(string); ++i) {
        char currentBracket = string[i];
        if (currentBracket == '(' || currentBracket == '{' || currentBracket == '[' ||
            currentBracket == ')' || currentBracket == '}' || currentBracket == ']') {
            return true;
        }
    }
    return false;
}

bool advancedBracketBalance(char* string) {
    Stack* stack = createStack();
    if (stack == NULL) {
        return false;
    }

    int index = 0;
    while (string[index] != '\0') {
        char current = string[index];

        if (current == '(' || current == '{' || current == '[') {
            push(stack, current);
        }
        else if (current == ')' || current == '}' || current == ']') {
            if (isEmpty(stack)) {
                free(stack);
                return false;
            }
            char top = stack->head->value;
            if ((current == ')' && top != '(') ||
                (current == '}' && top != '{') ||
                (current == ']' && top != '[')) {
                free(stack);
                return false;
            }
            pop(stack);
        }
        ++index;
    }
    bool isBalanced = isEmpty(stack);
    free(stack);
    return isBalanced;
}
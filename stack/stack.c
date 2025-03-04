#include<stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "stack.h"

void push(Stack* stack, int value) {
    StackElement* element = malloc(sizeof(StackElement));
    if (element == NULL) {
        return;
    }
    element->value = value;
    element->next = stack->head;
    stack->head = element;
}

void pop(Stack* stack) {
    if (stack->head == NULL) {
        return;
    }
    StackElement* tmp = stack->head;
    stack->head = stack->head->next;
    free(tmp);
}

Stack* createStack() {
    return (Stack*)calloc(1, sizeof(Stack));
}

bool isEmpty(Stack* stack) {
    return stack->head == NULL;
}

int getValue(Stack* stack) {
    if (stack->head == NULL) {
        return;
    }
    return stack->head->value;
}
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

int pop(Stack* stack) {
    if (stack->head == NULL) {
        return;
    }
    StackElement* tmp = stack->head;
    int value = tmp->value;
    stack->head = stack->head->next;
    free(tmp);
    return value;
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

void deleteStack(Stack* stack) {
    while (stack->head != NULL) {
        pop(stack);
    }
}
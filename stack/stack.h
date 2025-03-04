#pragma once

#include <stdbool.h>

//Structure for head
typedef struct Stack Stack;

typedef struct StackElement {
    int value;
    struct StackElement* next;
} StackElement;

typedef struct Stack {
    StackElement* head;
} Stack;

// Function that creates the first element in the stack
Stack* createStack();

// Function adds an element to the stack
void push(Stack* stack, int value);

// Function removes an element from the stack
void pop(Stack* stack);

// Function checks if the stack is empty
bool isEmpty(Stack* stack);

// Function that gets the value of the stack element
int getValue(Stack* stack);
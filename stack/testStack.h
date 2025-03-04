#pragma once

#include <stdbool.h>

// Function that creates a stack and verifies that it is not NULL 
bool testCreateStack();

// Function that tests adding an element to the stack
bool testPush();

// Function that tests the removal of an element from the stack
bool testPop();

// Function that tests to see if the stack is empty
bool testIsEmpty();

// Function that tests getting an element from the stack
bool testGetValue();
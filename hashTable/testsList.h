#pragma once

#include <stdbool.h>

// Function that checks the creation of a list
bool testCreateList();

// Function that verifies the correct addition of an element and the return of its value
bool testGetValue();

// Function that checks whether an element is correctly added to the head of the list
bool testAddInHead();

// Function that checks whether an element is correctly added to the tail of the list
bool testAddInTail();

// Function that verifies the correct addition of an element
bool testAddValue();

// Function that verifies the correct deletion of an element from the list
bool testDeleteElement();

// Function that verifies the correct return of an element by index
bool testGetElement();

// Function that combines all of the above functions
bool testList();
#pragma once

#include <stdbool.h>

// Function that verifies the correctness of creating a new node
bool testCreateNode(Node* node);

// Function that verifies the correctness of adding and returning the left child
bool testAddLeftChildAndGetLeftChild();

// Function that verifies the correctness of adding and returning the left child
bool testAddRightChildAndGetRightChild();

// Function that checks the return of the node value
bool testGetValue(Node* node);

// Function that checks whether the expression is split correctly and whether the tree is built
bool testSeparateArithmeticExpression(char* string, int* errorCode);

// Function that verifies the correctness of the calculation of tree elements
bool testCalculate(char* string, int* errorCode);

// Function that fully tests the entire program
bool testTree();
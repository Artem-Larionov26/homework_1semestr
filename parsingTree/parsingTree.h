#pragma once

typedef struct Node Node;

// Create a new node
Node* createNode(char* value, int* errorCode);

// Function that adds a left child to the parent node
void addLeftChild(Node* node, Node* child);

// Function that adds a right child to the parent node
void addRightChild(Node* node, Node* child);

// Return the left child
Node* getLeftChild(Node* node);

// Return the right child
Node* getRightChild(Node* node);

// Function that returns the value of a node
const char* getValue(Node* node);

// Function that sets a new node value
void addValue(Node* node, char* value);

// Function that deletes the tree
void deleteTree(Node* node);

// Function that parses a string with an arithmetic expression and builds a parse tree
Node* separateArithmeticExpression(char* string, int* index, int* errorCode);

// Function that parses a string with an arithmetic expression and builds a parse tree
void printTree(Node* node);

// Function that calculates the value of an expression represented as a tree
int calculate(Node* node, int* errorCode);
#pragma once

#include <stdbool.h>

// Function that verifies the correctness of creating a new node
bool testCreateNode(Node* node);

//  Function that verifies the correctness of adding and returning the left child
bool testAddLeftChildAndGetLeftChild();

//  Function that verifies the correctness of adding and returning the right child
bool testAddRightChildAndGetRightChild();

// Function that checks the return of the node value
bool testGetValue(Node* node);

// Function that verifies the correctness of adding an element to the tree
bool testAddElementToTree(Node* node, int* errorCode);

// Function that checks whether an element is found correctly by its key
bool testFindElementByKey(Node* node, int* errorCode);

// Function that verifies the correctness of deleting an element by its key
bool testDeleteElementByKey(Node* node);

// Function that verifies the correctness of all tests
bool testTree();
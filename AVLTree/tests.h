#pragma once

#include <stdbool.h>

// Function that checks the initialization of a node
bool testInitializeNode(void);

// Function that checks the insertion of the left child
bool checkLeftInsertion(void);

// Function that checks the insertion of the right child
bool checkRightInsertion(void);

// Function that verifies the receipt of a value by a key
bool testGetValue(void);

// Function that checks the insertion of an element
bool testInsertElement(AVLNode* root);

// Function that checks the search for an element
bool testKeyExist(AVLNode* root);

// Function that checks the deletion of an element from the tree
bool testDeleteElement(AVLNode** root);

// Function that verifies the correctness of all tests
bool allTests(void);
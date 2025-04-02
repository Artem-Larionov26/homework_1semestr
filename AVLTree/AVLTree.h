#pragma once

#include <stdbool.h>

typedef struct AVLNode AVLNode;

// Initialize a tree node
AVLNode* initializeNode(const char* key, const char* value, int* error);

// Insert an element into the tree
AVLNode* insertElement(AVLNode* root, const char* key, const char* value, int* error);

// Delete a node from the tree
AVLNode* deleteElement(AVLNode* root, const char* key);

// Searching for an element by key
const char* getValue(AVLNode* root, const char* key);

// Function that checks for the presence of a key
bool keyExist(AVLNode* root, const char* key);

// Function that destroys the tree
void destroyTree(AVLNode* root);
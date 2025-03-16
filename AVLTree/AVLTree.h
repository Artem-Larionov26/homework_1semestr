#pragma once

#include <stdbool.h>

typedef struct AVLNode {
    const char* key;
    const char* value;
    int balanceFactor;
    struct AVLNode* left;
    struct AVLNode* right;
} AVLNode;

// Initialize a tree node
AVLNode* initializeNode(const char* key, const char* value, int* error);

// Function that returns the height of a node
int nodeHeight(AVLNode* node);

// Function that refreshes the node height
void refreshHeight(AVLNode* node);

// Small right turn
AVLNode* rotateRight(AVLNode* root);

// Small left turn
AVLNode* rotateLeft(AVLNode* root);

// Big right turn
AVLNode* rotateBigRight(AVLNode* root);

// Big left turn
AVLNode* rotateBigLeft(AVLNode* root);

// Balance the tree
AVLNode* balanceTree(AVLNode* root);

// Insert an element into the tree
AVLNode* insertElement(AVLNode* root, const char* key, const char* value, int* error);

// Find the minimum element
AVLNode* findMin(AVLNode* root);

// Delete a node from the tree
AVLNode* deleteElement(AVLNode* root, const char* key);

// Searching for an element by key
const char* getValue(AVLNode* root, const char* key);

// Function that checks for the presence of a key
bool keyExist(AVLNode* root, const char* key);

// Function that destroys the tree
void destroyTree(AVLNode* root);
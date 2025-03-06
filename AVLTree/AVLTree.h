#pragma once

typedef struct NodeValue {
    const char* key;
    const char* value;
} NodeValue;

typedef struct Node Node;

// Create a node
Node* createNode(NodeValue value, int* errorCode);

// Function that adds a left child to the parent node
void addLeftChild(Node* node, Node* child);

// Function that adds a right child to the parent node
void addRightChild(Node* node, Node* child);

// Return the left child
Node* getLeftChild(Node* node);

// Return the right child
Node* getRightChild(Node* node);

// Return the value of a node
NodeValue getValue(Node* node);

// Function that sets a new node value
void addValue(Node* node, NodeValue value);

// Function that deletes the tree
void deleteTree(Node* node);

// Function that returns the height of a node
int getHeight(Node* node);

// Function that updates the height of a node
int updateHeight(Node* node);

// Make a small left turn
Node* smallLeftTurn(Node** node);

// Make a small right turn
Node* smallRightTurn(Node** node);

// Make a big left turn
Node* bigLeftTurn(Node** node);

// Make a big right turn
Node* bigRightTurn(Node** node);

// Function that performs tree balancing
void treeBalancing(Node** node);

// Function that adds an element to the tree
void addElementToTree(Node** node, NodeValue value, int* errorCode);

// Return the minimum node element
Node* getTheMinimumElementOfTheRightNode(Node* node);

// Function that deletes an element by key
void deleteElementByKey(Node** node, const char* key);

// Find an element by key
Node* findElementByKey(Node* node, const char* key);

// Function that checks whether an element in the tree is found by a key
bool presenceOfElementByKey(Node* node, const char* key);

// Find the parent of an element by key
Node* findByKeyByRemove(Node* node, char* key);
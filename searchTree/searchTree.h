#pragma once

typedef struct NodeValue {
    int key;
    char* value;
} NodeValue;

typedef struct Node Node;

// Create a tree node
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

// Function that adds an element to the tree
void addElementToTree(Node* node, NodeValue value, int* errorCode);

// Find the smallest element in the right subtree
Node* getTheMinimumElementOfTheRightNode(Node* node);

// Find an element by key
Node* findElementByKey(Node* node, int key);

// Function that checks the presence of an element by a key
bool presenceOfElementByKey(Node* node, int key);

// Find the parent of an element by key
Node* findByKeyByRemove(Node* node, int key);

// Function that deletes an element by key
void deleteElementByKey(Node* node, int key);
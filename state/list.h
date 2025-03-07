#pragma once

typedef struct ListElement ListElement;

typedef struct List List;

typedef struct Node Node;

typedef ListElement* Position;

typedef struct Value {
    Node* node;
    int length;
} Value;

// Create a list
List* createList(int* errorCode);

// Position of the first element
Position firstElement(List* list);

// Position of the last element
Position lastElement(List* list);

// Function that adds an element after a position
int addValue(List* list, Position position, Value value, int* errorCode);

// Function that adds an element to the head of the list
void addInHead(List* list, Value value, int* errorCode);

// Function that adds an element to the tail of the list
void addInTail(List* list, Value value, int* errorCode);

// Function that deletes an element after a position
void deleteElement(List* list, Position position);

// Function that deletes an element, but does not delete its value
void deleteElementWithoutErasingValues(List* list, Position position);

// Returns an element by index
Position getElement(List* list, int index);

// Function that returns the value of an element
Value getValue(List* list, Position position);

// Function that returns the size of the list
int getSizeList(List* list);

// Function that checks whether the element is the last one
bool isLast(List* list, Position position);

// Function that checks whether the position is valid
bool isValid(List* list, Position position);

// Function that checks if the list is empty
bool isEmpty(List* list);

// Get the next element
Position next(Position position);

// Function that checks if a node is in the list
bool nodeInList(List* list, Node* node); 

// Function that deletes the list
void deleteList(List* list);

// Function that deletes the list, but does not delete the values themselves
void deleteListWithoutErasingValues(List* list);
#pragma once

#include <stdbool.h>

typedef struct ListElement ListElement;

typedef struct List List;

typedef ListElement* Position;

typedef int Value;

// Create a list
List* createList(int* errorCode);

// Position of the first element
Position firstElement(List* list);

// Function that adds an element after a position
int addContact(List* list, Position position, char* name, char* phone, int* errorCode);

// Function that adds an item to the head of the list
void addInHead(List* list, char* name, char* phone, int* errorCode);

// function that adds an item to the tail of the list
void addInTail(List* list, char* name, char* phone, int* errorCode);

// Function that deletes an element after a position
void deleteElement(List* list, Position position);

// Returns an element by index
Position getElement(List* list, int index);

// Function that returns the name and phone number of an element
void getNameAndPhone(List* list, Position position, char* name, char* phone, int* errorCode);

// Function that checks whether the element is the last one
bool isLast(List* list, Position position);

// Function that checks whether the position is valid
bool isValid(List* list, Position position);

// Getting the next element
Position next(Position position);

// Returns a list item
Value getSizeList(List* list);

// Function that deletes the list
void deleteList(List* list);
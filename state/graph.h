#pragma once

#include "list.h"

typedef struct Node Node;

typedef struct Graph Graph;

// Create a node
Node* createNode(int name, int* errorCode);

// Create a graph
Graph* createGraph(int* errorCode);

// Function that writes down the number of cities
void writeDownTheNumberOfCities(Graph* graph, size_t numberOfCities);

// Function that returns the node name
int getNodeName(Node* node);

// Function that returns the size of a node
size_t getGraphSize(Graph* graph);

// Function that finds a node in a graph
void findNodeInGraph(Node* node, Node** findNode, int name, List* list, int* errorCode);

// Return the found node
Node* wrapFindNodeInGraph(Graph* graph, int name, int* errorCode);

// Function that increases the graph size
void increaseGraphSize(Graph* graph, int index, int* errorCode);

// Function that adds an element to a graph
void addElementToGraph(Graph* graph, Node* node, int* errorCode);

// Function that creates the path
void createAPath(Graph* graph, int nameOfTheShipment, int arrivalName, int length, int* errorCode);

// Return the nearest element
Node* getTheNearestElement(Node* node);

// Function that performs a depth-first traversal of the graph
void wrapDepthFirstTraversalOfAGraph(Node* node, int* errorCode);

// Function that returns a node with the minimum length
Node* nodeWithMinimumLength(List* list, Node* parent);

// Function that finds the nearest unoccupied city
void wrapFindTheNearestUnoccupiedCity(Node* node, int* errorCode);

// Function that assigns cities to states
void assignCitiesToStates(Graph* graph, Graph* captails, int* errorCode);

// Function that outputs states
void printStates(Graph* graph, int* errorCode);

// Function that deletes the graph
void wrapDeleteGraph(Graph* graph, int* errorCode);

// Function that deletes a graph without content
void deleteGraphWithoutContent(Graph* graph);
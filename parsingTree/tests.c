#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "parsingTree.h"
#include "tests.h"

bool testCreateNode(Node* node) {
    return node != NULL;
}

bool testAddLeftChildAndGetLeftChild() {
    int errorCode = 0;
    char* value1 = calloc(20, sizeof(char));
    char* value2 = calloc(20, sizeof(char));
    if (value1 == NULL || value2 == NULL) {
        return false;
    }
    strcpy_s(value1, 19, "abcdef");
    strcpy_s(value2, 19, "ghijkl");
    Node* node = createNode(value1, &errorCode);
    Node* child = createNode(value2, &errorCode);
    addLeftChild(node, child);
    bool result = (getLeftChild(node) == child);
    deleteTree(node);
    return result && errorCode == 0;
}

bool testAddRightChildAndGetRightChild() {
    int errorCode = 0;
    char* value1 = calloc(20, sizeof(char));
    char* value2 = calloc(20, sizeof(char));
    if (value1 == NULL || value2 == NULL) {
        return false;
    }
    strcpy_s(value1, 19, "abcdef");
    strcpy_s(value2, 19, "ghijkl");
    Node* node = createNode(value1, &errorCode);
    Node* child = createNode(value2, &errorCode);
    addRightChild(node, child);
    bool result = (getRightChild(node) == child);
    deleteTree(node);
    return result && errorCode == 0;
}

bool testGetValue(Node* node) {
    return strcmp(getValue, "asdfgh");
}

bool testSeparateArithmeticExpression(char* string, int* errorCode) {
    bool result = false;
    int index = 0;
    Node* node = separateArithmeticExpression(string, &index, errorCode);
    if (!strcmp(getValue(node), "*") && !strcmp(getValue(getLeftChild(node)), "+") &&
        !strcmp(getValue(getLeftChild(getLeftChild(node))), "9") &&
        !strcmp(getValue(getRightChild(getLeftChild(node))), "3") &&
        !strcmp(getValue(getRightChild(node)), "8")) {
        result = true;
    }
    deleteTree(node);
    return result;
}

bool testCalculate(char* string, int* errorCode) {
    bool result = false;
    int index = 0;
    Node* node = separateArithmeticExpression(string, &index, errorCode);
    if (calculate(node, errorCode) == 96) {
        result = true;
    }
    deleteTree(node);
    return result;
}

bool testTree() {
    bool result = false;
    int errorCode = 0;
    char* string = calloc(20, sizeof(char));
    char* value1 = calloc(20, sizeof(char));
    if (value1 == NULL || string == NULL) {
        return false;
    }
    strcpy_s(string, 20, "( * ( + 9 3 ) 8 )");
    strcpy_s(value1, 19, "asdfgh");
    Node* node = createNode(value1, &errorCode);
    if (testCreateNode(node) && testAddLeftChildAndGetLeftChild() &&
        testAddRightChildAndGetRightChild() && testGetValue(node) &&
        testSeparateArithmeticExpression(string, &errorCode) &&
        testCalculate(string, &errorCode)) {
        result = true;
    }
    free(string);
    deleteTree(node);
    return result && errorCode == 0;
}
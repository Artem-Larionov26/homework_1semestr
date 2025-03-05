#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "searchTree.h"
#include "tests.h"

bool testCreateNode(Node* node) {
    return node != NULL;
}

bool testAddLeftChildAndGetLeftChild() {
    int errorCode = 0;
    char* textValue1 = calloc(20, sizeof(char));
    char* textValue2 = calloc(20, sizeof(char));
    if (textValue1 == NULL || textValue2 == NULL) {
        return false;
    }
    strcpy_s(textValue1, 19, "abcdef");
    strcpy_s(textValue2, 19, "ghijkl");
    NodeValue value1 = { 1, textValue1 };
    NodeValue value2 = { 2, textValue2 };
    Node* node = createNode(value1, &errorCode);
    Node* child = createNode(value2, &errorCode);
    addLeftChild(node, child);
    bool result = (getLeftChild(node) == child);
    deleteTree(node);
    return result && errorCode == 0;
}

bool testAddRightChildAndGetRightChild() {
    int errorCode = 0;
    char* textValue1 = calloc(20, sizeof(char));
    char* textValue2 = calloc(20, sizeof(char));
    if (textValue1 == NULL || textValue2 == NULL) {
        return false;
    }
    strcpy_s(textValue1, 19, "abcdef");
    strcpy_s(textValue2, 19, "ghijkl");
    NodeValue value1 = { 1, textValue1 };
    NodeValue value2 = { 2, textValue2 };
    Node* node = createNode(value1, &errorCode);
    Node* child = createNode(value2, &errorCode);
    addRightChild(node, child);
    bool result = (getRightChild(node) == child);
    deleteTree(node);
    return result && errorCode == 0;
}

bool testGetValue(Node* node) {
    return getValue(node).key == 1;
}

bool testAddElementToTree(Node* node, int* errorCode) {
    bool result = false;
    Node* child1 = getRightChild(node);
    Node* child2 = getLeftChild(child1);
    Node* child3 = getRightChild(child2);
    char* string = calloc(20, sizeof(char));
    if (string == NULL) {
        *errorCode = 1;
        return false;
    }
    strcpy_s(string, 19, "asdfgh");
    NodeValue value = { 7, string };
    addElementToTree(node, value, errorCode);
    Node* child4 = getRightChild(child1);
    if (getValue(node).key == 1 && getValue(child1).key == 5 &&
        getValue(child2).key == 3 && getValue(child3).key == 4 &&
        getValue(child4).key == 7) {
        result = true;
    }
    return result;
}

bool testFindElementByKey(Node* node, int* errorCode) {
    bool result = false;
    Node* child1 = getRightChild(node);
    Node* child2 = getLeftChild(child1);
    Node* child3 = getRightChild(child2);
    if (findElementByKey(node, 1) == node && findElementByKey(node, 5) == child1 &&
        findElementByKey(node, 3) == child2 && findElementByKey(node, 4) == child3 &&
        findElementByKey(node, 10) == NULL) {
        result = true;
    }
    return result;
}

bool testDeleteElementByKey(Node* node) {
    deleteElementByKey(node, 5);
    Node* child1 = getRightChild(node);
    Node* child2 = getLeftChild(child1);
    return getValue(child1).key == 7 && getValue(child2).key == 3;
}

bool testTree() {
    bool result = false;
    int errorCode = 0;
    char* textValue1 = calloc(20, sizeof(char));
    char* textValue2 = calloc(20, sizeof(char));
    char* textValue3 = calloc(20, sizeof(char));
    char* textValue4 = calloc(20, sizeof(char));
    if (textValue1 == NULL || textValue2 == NULL || textValue3 == NULL || textValue4 == NULL) {
        return false;
    }
    strcpy_s(textValue1, 19, "qwerty");
    strcpy_s(textValue2, 19, "asdfgh");
    strcpy_s(textValue3, 19, "zxcvbn");
    strcpy_s(textValue4, 19, "poiuyt");
    NodeValue value1 = { 1, textValue1 };
    Node* node = createNode(value1, &errorCode);
    NodeValue value2 = { 5, textValue2 };
    NodeValue value3 = { 3, textValue3 };
    NodeValue value4 = { 4, textValue4 };
    addElementToTree(node, value2, &errorCode);
    addElementToTree(node, value3, &errorCode);
    addElementToTree(node, value4, &errorCode);
    if (testCreateNode(node) && testAddLeftChildAndGetLeftChild() &&
        testAddRightChildAndGetRightChild() && testGetValue(node) && testAddElementToTree(node, &errorCode) &&
        testFindElementByKey(node, &errorCode) &&
        testDeleteElementByKey(node) && errorCode == 0) {
        result = true;
    }
    deleteTree(node);
    return result;
}
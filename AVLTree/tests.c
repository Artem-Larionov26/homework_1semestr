#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "AVLTree.h"
#include "tests.h"

bool testInitializeNode() {
    int error = 0;
    AVLNode* node = initializeNode("testKey", "testValue", &error);
    bool success = (node != NULL && error == 0);
    destroyTree(node);
    return success;
}

bool checkLeftInsertion() {
    int error = 0;
    AVLNode* root = initializeNode("5", "five", &error);
    if (!root || error != 0) {
        destroyTree(root);
        return false;
    }
    root = insertElement(root, "3", "three", &error);
    if (error != 0) {
        destroyTree(root);
        return false;
    }
    bool result = (root->left != NULL && strcmp(root->left->key, "3") == 0 && strcmp(root->left->value, "three") == 0 && root->right == NULL);
    destroyTree(root);
    return result;
}

bool checkRightInsertion() {
    int error = 0;
    AVLNode* root = initializeNode("5", "five", &error);
    if (!root || error != 0) {
        destroyTree(root);
        return false;
    }
    root = insertElement(root, "7", "seven", &error);
    if (error != 0) {
        destroyTree(root);
        return false;
    }
    bool result = (root->right != NULL && strcmp(root->right->key, "7") == 0 && strcmp(root->right->value, "seven") == 0 && root->left == NULL);
    destroyTree(root);
    return result;
}

bool testGetValue() {
    int error = 0;
    AVLNode* node = initializeNode("3", "three", &error);
    bool result = (strcmp(getValue(node, "3"), "three") == 0 && error == 0);
    destroyTree(node);
    return result;
}

bool testInsertElement(AVLNode* root) {
    return (strcmp(getValue(root, "3"), "three") == 0 && strcmp(getValue(root, "5"), "five") == 0 && 
        strcmp(getValue(root, "1"), "one") == 0 && strcmp(getValue(root, "4"), "four") == 0);
}

bool testKeyExist(AVLNode* root) {
    return (keyExist(root, "1") && keyExist(root, "3") && keyExist(root, "4") && keyExist(root, "5") && !keyExist(root, "10"));
}

bool testDeleteElement(AVLNode* root) {
    root = deleteElement(root, "1");
    return (strcmp(getValue(root, "3"), "three") == 0 && strcmp(getValue(root, "5"), "five") == 0 && !keyExist(root, "1"));
}

bool allTests() {
    int error = 0;
    AVLNode* tree = NULL;
    tree = insertElement(tree, "1", "one", &error);
    tree = insertElement(tree, "5", "five", &error);
    tree = insertElement(tree, "3", "three", &error);
    tree = insertElement(tree, "4", "four", &error);
    if (error != 0) {
        destroyTree(tree);
        return false;
    }
    bool result = (testInitializeNode() && checkLeftInsertion() && checkRightInsertion() && testGetValue() && 
        testInsertElement(tree) && testKeyExist(tree) && testDeleteElement(tree));
    destroyTree(tree);
    return result;
}
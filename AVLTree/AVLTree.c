#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "AVLTree.h"

typedef struct AVLNode {
    const char* key;
    const char* value;
    int balanceFactor;
    struct AVLNode* left;
    struct AVLNode* right;
} AVLNode;

AVLNode* initializeNode(const char* key, const char* value, int* error) {
    if (key == NULL || value == NULL) {
        *error = 1;
        return NULL;
    }
    AVLNode* newNode = malloc(sizeof(AVLNode));
    if (!newNode) {
        *error = 1;
        return NULL;
    }
    size_t keyLen = strlen(key) + 1;
    size_t valueLen = strlen(value) + 1;
    newNode->key = malloc(keyLen * sizeof(char));
    newNode->value = malloc(valueLen * sizeof(char));
    if (!newNode->key || !newNode->value) {
        *error = 1;
        free(newNode->key);
        free(newNode->value);
        free(newNode);
        return NULL;
    }
    strcpy(newNode->key, key);
    strcpy(newNode->value, value);
    newNode->balanceFactor = 0;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int nodeHeight(AVLNode* node) {
    return node ? node->balanceFactor : -1;
}

void refreshHeight(AVLNode* node) {
    int leftHeight = nodeHeight(node->left);
    int rightHeight = nodeHeight(node->right);
    if (leftHeight > rightHeight) {
        node->balanceFactor = leftHeight + 1;
    }
    else {
        node->balanceFactor = rightHeight + 1;
    }
}

AVLNode* rotateRight(AVLNode* root) {
    if (root == NULL) {
        return NULL;
    }
    AVLNode* current = root->left;
    if (current == NULL) {
        return root;
    }
    root->left = current->right;
    current->right = root;
    refreshHeight(root);
    refreshHeight(current);
    return current;
}

AVLNode* rotateLeft(AVLNode* root) {
    if (root == NULL) {
        return NULL;
    }
    AVLNode* current = root->right;
    if (current == NULL) {
        return root;
    }
    root->right = current->left;
    current->left = root;
    refreshHeight(root);
    refreshHeight(current);
    return current;
}

AVLNode* rotateBigRight(AVLNode *root) {
    root->left = rotateLeft(root->left);
    return rotateRight(root);
}

AVLNode* rotateBigLeft(AVLNode* root) {
    root->right = rotateRight(root->right);
    return rotateLeft(root);
}

AVLNode* balanceTree(AVLNode* root) {
    int difference = nodeHeight(root->left) - nodeHeight(root->right);
    if (difference > 1) {
        if (nodeHeight(root->left->left) >= nodeHeight(root->left->right)) {
            return rotateRight(root);
        }
        else {
            return rotateBigRight(root);
        }
    }
    else if (difference < -1) {
        if (nodeHeight(root->right->right) >= nodeHeight(root->right->left)) {
            return rotateLeft(root);
        }
        else {
            return rotateBigLeft(root);
        }
    }
    return root;
}

AVLNode* insertElement(AVLNode* root, const char* key, const char* value, int* error) {
    if (!root) {
        return initializeNode(key, value, error);
    }
    int comparison = strcmp(key, root->key);
    if (comparison == 0) {
        free((char*)root->value);
        size_t valueLen = strlen(value) + 1;
        root->value = malloc(valueLen * sizeof(char));
        if (!root->value) {
            *error = 1;
            free(root->value);
            return NULL;
        }
        strcpy(root->value, value);
        return root;
    }
    else if (comparison < 0) {
        root->left = insertElement(root->left, key, value, error);
    }
    else {
        root->right = insertElement(root->right, key, value, error);
    }
    refreshHeight(root);
    return balanceTree(root);
}

AVLNode* findMin(AVLNode* root) {
    while (root->left) {
        root = root->left;
    }
    return root;
}

AVLNode* deleteElement(AVLNode* root, const char* key) {
    if (root == NULL) {
        return NULL;
    }
    if (key == NULL) {
        return root;
    }
    if (root->key == NULL) {
        return root;
    }
    int comparison = strcmp(key, root->key);
    if (comparison < 0) {
        root->left = deleteElement(root->left, key);
    }
    else if (comparison > 0) {
        root->right = deleteElement(root->right, key);
    }
    else {
        AVLNode* left = root->left;
        AVLNode* right = root->right;
        free((char*)root->key);
        free((char*)root->value);
        free(root);
        if (!right) {
            return left;
        }
        AVLNode* min = findMin(right);
        min->right = deleteElement(right, min->key);
        min->left = left;
        refreshHeight(min);
        return balanceTree(min);
    }
    refreshHeight(root);
    return balanceTree(root);
}

const char* getValue(AVLNode* root, const char* key) {
    if (!root) {
        return NULL;
    }
    int comparison = strcmp(key, root->key);
    if (comparison == 0) {
        return root->value;
    }
    else if (comparison < 0) {
        getValue(root->left, key);
    }
    else {
        getValue(root->right, key);
    }
}

bool keyExist(AVLNode* root, const char* key) {
    return getValue(root, key) != NULL;
}

void destroyTree(AVLNode* root) {
    if (!root) {
        return;
    }
    destroyTree(root->left);
    destroyTree(root->right);
    free((char*)root->key);
    free((char*)root->value);
    free(root);
}
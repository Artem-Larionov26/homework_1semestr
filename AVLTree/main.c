#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "AVLTree.h"
#include "tests.h"

void readString(char* buffer, int size) {
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = 0;
}

int main() {
    if (!allTests()) {
        printf("Error: tests failed!\n");
        return 1;
    }
    printf("Operations:\n");
    printf("0. Exit\n");
    printf("1. Add a value for a given key to the dictionary\n");
    printf("2. Get the value for a given key from the dictionary\n");
    printf("3. Check for the specified key in the dictionary\n");
    printf("4. Delete the specified key and its associated value from the dictionary\n");
    AVLNode* dictionary = NULL;
    char key[30] = { 0 };
    char value[100] = { 0 };
    int choice = 0;
    int error = 0;
    while (1) {
        printf("Enter operation number: ");
        scanf("%d", &choice);
        getchar();
        switch (choice) {
            case 0:
                destroyTree(dictionary);
                return 0;
            case 1:
                printf("Enter key: ");
                readString(key, sizeof(key));
                printf("Enter value: ");
                readString(value, sizeof(value));
                dictionary = insertElement(dictionary, key, value, &error);
                if (error == 1) {
                    printf("Memory allocation error!\n");
                    error = 0;
                }
                else {
                    printf("Element added successfully!\n");
                }
                break;
            case 2: 
                printf("Enter the search key: ");
                readString(key, sizeof(key));
                const char* result = getValue(dictionary, key);
                if (result != NULL) {
                    printf("Value: %s\n", result);
                }
                else {
                    printf("The key was not found!\n");
                }
                break;
            case 3: 
                printf("Enter the verification key: ");
                readString(key, sizeof(key));
                if (keyExist(dictionary, key)) {
                    printf("The key exists in the dictionary!\n");
                }
                else {
                    printf("The key was not found!\n");
                }
                break;
            case 4: 
                printf("Enter the key to delete: ");
                readString(key, sizeof(key));
                if (keyExist(dictionary, key)) {
                    dictionary = deleteElement(dictionary, key);
                    printf("The element was successfully deleted!\n");
                }
                else {
                    printf("The key was not found!\n");
                }
                break;
            default: 
                printf("Wrong choice. Try again.\n");
        }
    }
    return 0;
}
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>
#include "list.h"
#include "testsList.h"

int main() {
    if (!testList()) {
        printf("Test falied!\n");
        return 1;
    }
    SortedList* list = initList();
    if (list == NULL) {
        printf("Error: couldn't create a list!\n");
        return 1;
    }
    int choice = 9;
    do {
        printf("\nSelect an action:\n");
        printf("0 - exit\n");
        printf("1 - add a value to the sorted list\n");
        printf("2 - delete a value from the list\n");
        printf("3 - print the list\n");
        printf("Your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 0:
            freeList(&list);
            printf("The work is completed!\n");
            return 0;
        case 1: {
            int value = 0;
            printf("Enter the value to add: ");
            scanf("%d", &value);
            if (insertSorted(list, value) == 0) {
                printf("The element %d has been added.\n", value);
            }
            else {
                printf("Error: couldn't add %d element due to lack of memory!\n", value);
                freeList(&list);
                return 1;
            }
            break;
        }
        case 2: {
            int value;
            printf("Enter the value to delete: ");
            scanf("%d", &value);
            if (deleteValue(list, value)) {
                printf("The element %d has been deleted!\n", value);
            }
            else {
                printf("The element %d was not found or the list is empty!\n", value);
            }
            break;
        }
        case 3:
            printf("The current list: ");
            printList(list);
            break;
        default:
            printf("Wrong choice! Enter a number from 0 to 3!\n");
        }
    } while (choice != 0);
    return 0;
}
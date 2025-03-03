#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define maxEntries 100
#define maxNameLength 50
#define maxPhoneLength 20

typedef struct {
    char name[maxNameLength];
    char phone[maxPhoneLength];
} PhoneBookEntry;

void loadFromFile(PhoneBookEntry phoneBook[], int* entryCount) {
    FILE* file = fopen("phonebook.txt", "r");
    if (file == NULL) {
        printf("File not found!\n");
        return;
    }
    *entryCount = 0;
    while (fscanf(file, "%49s %19s", phoneBook[*entryCount].name, phoneBook[*entryCount].phone) == 2) {
        (*entryCount)++;
        if (entryCount >= maxEntries) break;
    }
    fclose(file);
}

void saveToFile(PhoneBookEntry phoneBook[], int entryCount) {
    FILE* file = fopen("phonebook.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing!\n");
        return;
    }
    for (int i = 0; i < entryCount; i++) {
        fprintf(file, "%s %s\n", phoneBook[i].name, phoneBook[i].phone);
    }
    fclose(file);
    printf("Data saved successfully!\n");
}

void addEntry(PhoneBookEntry phoneBook[], int* entryCount, char* name, char* phone) {
    if (*entryCount >= maxEntries) {
        printf("Phone book is full.\n");
        return;
    }
    strncpy(phoneBook[*entryCount].name, name, maxNameLength);
    strncpy(phoneBook[*entryCount].phone, phone, maxPhoneLength);
    (*entryCount)++;
}

void printAllEntries(PhoneBookEntry phoneBook[], int entryCount) {
    if (entryCount == 0) {
        printf("Phone book is empty!\n");
        return;
    }
    for (int i = 0; i < entryCount; i++) {
        printf("%d. Name: %s, Phone: %s\n", i + 1, phoneBook[i].name, phoneBook[i].phone);
    }
}

char* findPhoneByName(PhoneBookEntry phoneBook[], int entryCount, char* name) {
    for (int i = 0; i < entryCount; i++) {
        if (strcmp(phoneBook[i].name, name) == 0) {
            return phoneBook[i].phone;
        }
    }
    return NULL;
}

char* findNameByPhone(PhoneBookEntry phoneBook[], int entryCount, char* phone) {
    for (int i = 0; i < entryCount; i++) {
        if (strcmp(phoneBook[i].phone, phone) == 0) {
            return phoneBook[i].name;
        }
    }
    return NULL;
}

bool testAddEntry() {
    PhoneBookEntry phoneBook[maxEntries];
    int entryCount = 0;
    addEntry(phoneBook, &entryCount, "010707", "Daria");
    if (entryCount != 1 || strcmp(phoneBook[0].name, "Daria") != 0 || strcmp(phoneBook[0].phone, "010707") != 0) {
        return false;
    }
    return true;
}

bool testFindPhoneByName() {
    PhoneBookEntry phoneBook[maxEntries];
    int entryCount = 0;
    addEntry(phoneBook, &entryCount, "010707", "Daria");
    char* expectedPhone = "010707";
    char* foundPhone = findPhoneByName(phoneBook, entryCount, "Daria");
    if (foundPhone == NULL || strcmp(foundPhone, expectedPhone) != 0) {
        return false;
    }
    return true;
}

bool testFindNameByPhone() {
    PhoneBookEntry phoneBook[maxEntries];
    int entryCount = 0;
    addEntry(phoneBook, &entryCount, "010707", "Daria");
    char* expectedName = "Daria";
    char* foundName = findNameByPhone(phoneBook, entryCount, "010707");
    if (foundName == NULL || strcmp(foundName, expectedName) != 0) {
        return false;
    }
    return true;
}

int main(void) {
    if (testAddEntry() || testFindPhoneByName() || testFindNameByPhone()) {
        printf("Tests failed!\n");
        return 0;
    }
    PhoneBookEntry phoneBook[maxEntries];
    char name[maxNameLength];
    char phone[maxPhoneLength];
    int entryCount = 0;
    int choice;
    loadFromFile(phoneBook, &entryCount);
    do {
        printf("Phone Directory Menu:\n");
        printf("0 - Exit\n");
        printf("1 - Add entry\n");
        printf("2 - Print all entries\n");
        printf("3 - Find phone by name\n");
        printf("4 - Find name by phone\n");
        printf("5 - Save data to file\n");
        printf("Enter your choice: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 0:
            printf("Exiting...\n");
            break;
        case 1:
            printf("Enter name: ");
            scanf_s("%s", name, maxNameLength);
            printf("Enter phone number: ");
            scanf_s("%s", phone, maxPhoneLength);
            addEntry(phoneBook, &entryCount, name, phone);
            break;
        case 2:
            printAllEntries(phoneBook, entryCount);
            break;
        case 3:
            printf("Enter name: ");
            scanf_s("%s", name, maxNameLength);
            char* foundPhone = findPhoneByName(phoneBook, entryCount, &name);
            if (foundPhone != NULL) {
                printf("Phone number: %s\n", foundPhone);
            }
            else {
                printf("Name not found.\n");
            }
            break;
        case 4:
            printf("Enter phone number: ");
            scanf_s("%s", phone, maxPhoneLength);
            char* foundName = findNameByPhone(phoneBook, entryCount, &phone);
            if (foundName != NULL) {
                printf("Name: %s\n", foundName);
            }
            else {
                printf("Phone number not found.\n");
            }
            break;
        case 5:
            saveToFile(phoneBook, entryCount);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);
}
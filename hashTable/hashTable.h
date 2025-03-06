#pragma once

typedef struct HashTable HashTable;

// Create hash table
HashTable* createHashTable(int* errorCode);

// Function that calculates the fill factor of a hash table
float getFillFactor(HashTable* hashTable);

// Function that returns the maximum length of lists
int getMaxLenght(HashTable* hashTable);

// Function that calculates the average length of a list in a hash table
int getAverageListLength(HashTable* hashTable);

// Function that calculates the average length of a list in a hash table
int hashFunction(char* key);

// Function that adds a new element to the hash table
void addValueToHashTable(HashTable* hashTable, Value value, int* errorCode);

// Function that searches for the number of occurrences of a word
int getWordFrequencyFromHashTable(HashTable* hashTable, char* key);

// Function outputs values from the entire hash table
void printValuesOfTheEntireHashTable(HashTable* hashTable);

// Function that deletes a hash table
void deleteHashTable(HashTable* hashTable);
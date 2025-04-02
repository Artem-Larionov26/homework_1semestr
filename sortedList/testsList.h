#pragma once

#include <stdbool.h>

// Function that checks the creation of an empty list
bool testInitList(void);

// Function that checks the insertion of a single element
bool testSingleInsert(void);

// Function that checks the sorting during insertion
bool testSortedInsert(void);

// Function that checks the deletion of an existing value
bool testDeleteExisting(void);

// Function that checks for deletion from an empty list
bool testDeleteFromEmpty(void);

// Function that combines all of the above functions
bool testList(void);
#pragma once

#include <stdbool.h>

// Function that checks the creation of an empty list
bool testInitList();

// Function that checks the insertion of a single element
bool testSingleInsert();

// Function that checks the sorting during insertion
bool testSortedInsert();

// Function that checks the deletion of an existing value
bool testDeleteExisting();

// Function that checks for deletion from an empty list
bool testDeleteFromEmpty();

// Function that combines all of the above functions
bool testList();
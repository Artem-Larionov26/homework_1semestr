#pragma once

// Combines two sorted lists into one sorted list
static List* merge(List* first, List* second, bool sortByName, int* errorCode);

// Recursively splits the list into two parts, sorts them, and merges them using the merge function.
List* mergeSorting(List* list, bool sortByName, int* errorCode);
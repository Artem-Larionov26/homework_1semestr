#pragma once

// Function that returns the number of spaces in a line
int numberOfSpacesInALine(char* string);

// Function that fills in three variables in a row
void fillThreeVariablesFromAString(char* buffer, char* name1, char* name2, char* name3);

// Function that reads from a file
void readFromFile(FILE* file, Graph* graph, Graph* capitals, int* errorCode);
#include <stdio.h>﻿
#include <stdlib.h>
#include <stdbool.h>
#include "graph.h"
#include "readFromFile.h"
#include "testsList.h"
#include "testsGraph.h"

int main(void) {
    if (!testGraph() || !testList()) {
        printf("Test failed!\n");
        return 1;
    }
    int errorCode = 0;
    Graph* graph = createGraph(&errorCode);
    Graph* capitals = createGraph(&errorCode);
    FILE* file = fopen("fileForTask.txt", "r");
    if (file == NULL) {
        printf("Memory allocation error!\n");
        return 1;
    }
    readFromFile(file, graph, capitals, &errorCode);
    fclose(file);
    assignCitiesToStates(graph, capitals, &errorCode);
    printStates(capitals, &errorCode);
    wrapDeleteGraph(graph, &errorCode);
    deleteGraphWithoutContent(capitals);
    if (errorCode == 1) {
        printf("Memory allocation error!\n");
        return 1;
    }
}
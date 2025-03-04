#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "list.h"

void countingRhyme(List* list, int n, int m, int* errorCode) {
    Position position = firstElement(list);
    for (int i = 1; i <= n; ++i) {
        addInTail(list, i, errorCode);
    }
    while (getSizeList(list) != 1) {
        for (int i = 0; i < m - 1; ++i) {
            position = next(position);
            if (position == firstElement(list)) {
                position = next(position);
            }
        }
        if (next(position) != firstElement(list)) {
            deleteElement(list, position);
        }
        else {
            position = next(position);
            deleteElement(list, position);
        }
    }
}

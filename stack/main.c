#include <stdio.h>
#include "stack.h"
#include "testStack.h"

int main(void) {
    if (!testCreateStack() || !testPush() || !testPop() || !testIsEmpty() || !testGetValue()) {
        printf("Tests failed!\n");
        return 1;
    }
    Stack* stack = createStack();
    push(stack, 1);
}
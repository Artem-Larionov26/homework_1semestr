#include <stdio.h>
#include <stdbool.h>
#include "testsForPostfixCalculator.h"
#include "stack.h"
#include "postfixCalculator.h"

bool testPostfixCalculator() {
    int errorCode = 0;
    bool test1 = postfixCalculator("1 2 +", &errorCode) == 3 && errorCode == 0;

    errorCode = 0;
    bool test2 = postfixCalculator("1 25 ++", &errorCode) == 8 && errorCode == 0;

    errorCode = 0;
    bool test3 = postfixCalculator("96 - 12 +*", &errorCode) == 9 && errorCode == 0;

    errorCode = 0;
    bool test4 = postfixCalculator("8 2 /", &errorCode) == 4 && errorCode == 0;

    return test1 && test2 && test3 && test4;
}


bool testProgram() {
    return testPostfixCalculator() && (createStack() != NULL);
}
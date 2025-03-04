#include <stdbool.h>
#include "testsForMainFunctions.h"
#include "advancedBracketBalance.h"

bool testForHaveBrackets() {
    return !haveBrackets("abcdefg") && haveBrackets("ab((cdef))") &&
        !haveBrackets("ololololo") && haveBrackets("i[sh") && haveBrackets("}um(ka") && haveBrackets("ag(fd{");
}

bool testForAdvancedBracketBalanced() {
    return !advancedBracketBalance(")))(((") && !advancedBracketBalance("}}}{{{") && !advancedBracketBalance("]]][[[")
        && advancedBracketBalance("(())") && advancedBracketBalance("{{}}") && advancedBracketBalance("[[]]")
        && !advancedBracketBalance(")olo))(olo((") && !advancedBracketBalance("z}xc}}{{zxc{z") && !advancedBracketBalance("btr]bt]][rr[[")
        && advancedBracketBalance("ulu(ulu(ulu)ulu)") && advancedBracketBalance("{ulu{ulul}ulu}") && advancedBracketBalance("[ulu[ulu]]ul");
}
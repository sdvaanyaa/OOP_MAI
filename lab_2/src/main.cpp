#include <iostream>
#include <string.h>
#include "../include/HexArray.h"

int main(){
    HexArray hx1("FFFFFEC0");
    HexArray hx2("CACACAB2");
    HexArray correctDiff("3535340E");
    HexArray diff = hx1 - hx2;
    hx1.debugPrint();
    hx2.debugPrint();
    diff.debugPrint();
    correctDiff.debugPrint();
}
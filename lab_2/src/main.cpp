#include <iostream>
#include <string.h>
#include "../include/HexArray.h"


int main(){
    HexArray hx1(1, 'A');
    HexArray hx2(1, 2);

    HexArray correctSum("12");
    HexArray correctDiff("8");

    HexArray sum = hx1 + hx2;
    HexArray diff = hx1 - hx2;

    hx1.debugPrint();
    hx2.debugPrint();
    sum.debugPrint();
    correctSum.debugPrint();
    diff.debugPrint();
    correctDiff.debugPrint();
}
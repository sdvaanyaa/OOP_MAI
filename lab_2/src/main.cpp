#include <iostream>
#include <string.h>
#include "../include/HexArray.h"


int main(){
    HexArray hx1(1, 'A');
    HexArray hx2(1, 3);

    HexArray correctSum("13");
    HexArray correctDiff("8");

    HexArray sum = hx1 + hx2;
    HexArray diff = hx1 - hx2;

    hx1.print();
    hx2.print();
    sum.print();
    correctSum.print();
    diff.print();
    correctDiff.print();

    std::cout << 'A' + 0 << std::endl;
}
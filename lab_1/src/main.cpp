#include "hearOfNum.h"
#include <iostream>  
#include <fstream>
#include <string>

using namespace std;

int main() {
    std::locale::global(std::locale("")); 
    string day;
    int num {0};
    cout << "Введите день недели и цифру: ";
    cin >> day >> num;
    
    if (hearOfNum(day, num)){
        cout << "Боюсь(" << endl;
    } else {
        cout << "Не боюсь)" << endl;
    }
    return 0;
}
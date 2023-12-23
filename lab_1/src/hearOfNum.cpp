#include "hearOfNum.h" 
#include <iostream>
#include <string>

using namespace std;

const int MondayNum {12};
const int TuesdayNum {95};
const int WednesdayNum {34};
const int ThursdayNum {0};
const int FridayNum {2};
const int SaturdayNum {56};
const int Sunday1Num {666};
const int Sunday2Num {-666};

bool hearOfNum(string day, int num){       

    if (day == "понедельник") {
        return num == MondayNum;
    } else if (day == "вторник") {
        return num > TuesdayNum;
    } else if (day == "среда") {
        return num == WednesdayNum;
    } else if (day == "четверг") {
        return num == ThursdayNum;
    } else if (day == "пятница") {
        return num % FridayNum == 0;
    } else if (day == "суббота") {
        return num == SaturdayNum;
    } else if (day == "воскресенье") {
        return num == Sunday1Num || num == Sunday2Num;
    } else {
        std::cout << "Не день недели\n";
        return true;
    }
}
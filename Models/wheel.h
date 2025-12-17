//
// Created by Mark on 12/16/25.
//

#ifndef WHEEL_H
#define WHEEL_H

#include <vector>
#include "../Utility/utility.h"
#include "../Utility/OperationCodes.h"
#include <set>
#include <string>

int WHEEL_SIZE = 10;

class Wheel {
private:
    int roulette_values[WHEEL_SIZE];
    bool win;
    int guessed_value;
    std::string wheel;
public:

    Wheel(bool win, int guessed_value);
    void print_wheel();
private:
    void generate_wheel();
    void generate_ascii_string();
};



#endif //WHEEL_H

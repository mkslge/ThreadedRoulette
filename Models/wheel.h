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

inline int WHEEL_SIZE = 12;

class Wheel {
private:
    std::vector<int >roulette_values;
    std::vector<std::string> string_structure;
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

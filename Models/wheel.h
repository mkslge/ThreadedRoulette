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
    Wheel();
    Wheel(bool win, int guessed_value);
    void print_wheel();
    void spin();
private:
    void generate_wheel();
    void generate_ascii_string();
    void print_string_structure();
    void run_ascii_animation();
    void clear_ascii_structure();
};



#endif //WHEEL_H

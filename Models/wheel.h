//
// Created by Mark on 12/16/25.
//

#ifndef WHEEL_H
#define WHEEL_H

#include <vector>
#include "../Utility/utility.h"
#include "../Utility/constants.h"
#include <set>
#include <string>



class Wheel {
private:
    std::vector<int >roulette_values;
    std::vector<std::string> string_structure;
    bool win;
    bool result_known;
    std::string wheel;
public:
    Wheel();
    Wheel(bool win);
    void print_wheel();
    void spin();
private:
    void generate_wheel();
    void generate_ascii_string();
    void print_string_structure();
    void run_ascii_animation();
    void clear_ascii_structure();
    void print_win_message();
    void print_lose_message();
};



#endif //WHEEL_H

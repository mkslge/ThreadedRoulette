//
// Created by Mark on 11/9/25.
//

#ifndef OUTCOME_H
#define OUTCOME_H

#include <string>
#include <utility>
#include <random>
#include <ctime>
#include <cstdlib>
#include <unordered_set>
#include "color.h"



class Outcome {
private:
    Color color;
    int value;




public:
    static Outcome generate_random_outcome();


    Outcome(Color color, int value);
    Outcome();
    Outcome(const Outcome& other);

    Color get_color();

    int get_value();

    bool operator==(Outcome other);

    std::string to_string();






};





#endif //OUTCOME_H

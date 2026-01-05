//
// Created by Mark on 11/9/25.
//

#ifndef OUTCOME_H
#define OUTCOME_H

#include <string>
#include "color.h"
#include<unordered_set>

static const std::unordered_set<int> red_numbers = {
    1,3,5,7,9,12,14,16,18,
    19,21,23,25,27,30,32,34,36
};

class Outcome {
private:
    Color color;
    int value;

public:
    static Outcome generate_random_outcome();


    Outcome(Color color, int value);
    Outcome();
    Outcome(const Outcome& other);

    bool operator==(Outcome other);

    Color get_color() const;

    int get_value() const;
    std::string to_string() const;
};





#endif //OUTCOME_H

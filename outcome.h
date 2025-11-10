//
// Created by Mark on 11/9/25.
//
#include <utility>
#include "color.h"
#ifndef OUTCOME_H
#define OUTCOME_H

class Outcome {
private:
    Color color;
    int value;

public:
    static Outcome generate_random_outcome();


    Outcome(Color color, int value);
    Outcome();

    Color get_color();

    int get_value();

    bool operator==(Outcome other);






};





#endif //OUTCOME_H

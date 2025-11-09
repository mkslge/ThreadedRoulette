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
    Outcome(Color color, int value) {
        this->color = color;
        this->value = value;
    }

    bool equals(Outcome outcome) {
        return false;
    }


    static Outcome generate_random_outcome() {
        return {Color::GREEN, -1};
    }



};



#endif //OUTCOME_H

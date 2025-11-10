//
// Created by Mark on 11/9/25.
//

#include "outcome.h"

Outcome::Outcome(Color color, int value) : color(color), value(value) {}
Outcome::Outcome() : color(Color::GREEN), value(-1){}


Color Outcome::get_color() {
    return color;
}

int Outcome::get_value() {
    return value;
}

bool Outcome::operator==(Outcome other) {
    return this->color == other.get_color() && this->value == other.get_value();
}

Outcome Outcome::generate_random_outcome() {
    return {Color::GREEN, -1};
}

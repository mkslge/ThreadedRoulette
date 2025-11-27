//
// Created by Mark on 11/9/25.
//

#include "outcome.h"

Outcome::Outcome(Color color, int value) : color(color), value(value) {

}
Outcome::Outcome() : color(Color::GREEN), value(-1) {

}


Color Outcome::get_color() {
    return color;
}

int Outcome::get_value() {
    return value;
}

bool Outcome::operator==(Outcome other) {
    return this->color == other.get_color() && this->value == other.get_value();
}



std::string Outcome::to_string() {
    return "Color: " + color_to_string(color) + ", Value: " + std::to_string(value);
}


int get_random_roulette_number() {
    return rand() % 37;
}

Outcome Outcome::generate_random_outcome() {
    int random_number = get_random_roulette_number();
    if (random_number == 0) {
        return {Color::GREEN, 0};
    }

    static const int red_numbers[] = {
        1,3,5,7,9,12,14,16,18,
        19,21,23,25,27,30,32,34,36
    };

    for (int red_nubmer : red_numbers) {
        if (random_number == red_nubmer) {
            return {Color::RED, random_number};
        }
    }

    return {Color::BLACK, random_number};
}
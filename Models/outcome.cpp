//
// Created by Mark on 11/9/25.
//

#include "outcome.h"

#include "../Utility/constants.h"


Outcome::Outcome(Color color, int value) : color(color), value(value) {

}

Outcome::Outcome() : color(Color::GREEN), value(-1) {

}



Outcome::Outcome(const Outcome& other) {
    this->color = other.color;
    this->value = other.value;
}

Color Outcome::get_color() const {
    return color;
}

int Outcome::get_value() const {
    return value;
}

bool Outcome::operator==(Outcome other) {
    return this->color == other.get_color() && this->value == other.get_value();
}



std::string Outcome::to_string() const {
    return "Color: " + color_to_string(color) + ", Value: " + std::to_string(value);
}


int get_random_roulette_number() {
    return rand() % constants::ROULETTE_SIZE;
}


Outcome Outcome::generate_random_outcome() {
    int random_number = get_random_roulette_number();

    if (random_number == constants::GREEN_VALUE) {
        return {Color::GREEN, constants::GREEN_VALUE};
    }

    Color resulting_color = red_numbers.contains(random_number) ? Color::RED : Color::BLACK;
    return {resulting_color, random_number};
}
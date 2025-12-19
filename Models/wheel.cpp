//
// Created by Mark on 12/16/25.
//

#include "wheel.h"

#include <thread>


Wheel::Wheel(bool win, int guessed_value) {
    this->win = win;
    this->guessed_value = guessed_value;
    this->generate_wheel();
    this->generate_ascii_string();

}

Wheel::Wheel() {
    this->win = false;
    this->guessed_value = get_random_value(OperationCodes::get_roulette_size());
    this->generate_wheel();
    this->generate_ascii_string();

}

void Wheel::spin() {
    this->run_ascii_animation();
}

void Wheel::generate_wheel() {
    std::set<int> generated_values;
    generated_values.emplace(this->guessed_value);
    roulette_values.emplace_back(this->guessed_value);

    for (int i = 1; i < WHEEL_SIZE;i++) {
        int generated_value = get_random_value(OperationCodes::get_roulette_size());
        while (generated_values.contains(generated_value)) {
            generated_value = get_random_value(OperationCodes::get_roulette_size());
        }
        generated_values.emplace(generated_value);
        roulette_values.emplace_back(generated_value);
    }
}




void Wheel::generate_ascii_string() {
    string_structure.emplace_back(R"(              _________
         .-'''           '''-.
     .-''     )");
    string_structure.emplace_back(std::to_string(roulette_values[0]));

    string_structure.emplace_back(R"(   )");
    string_structure.emplace_back(std::to_string(roulette_values[1]));

    string_structure.emplace_back(R"(        ''-.
   .'      )");
    string_structure.emplace_back(std::to_string(roulette_values[11]));

    string_structure.emplace_back(R"(                 )");
    string_structure.emplace_back(std::to_string(roulette_values[2]));

    string_structure.emplace_back(R"(    '.
  /    )");
    string_structure.emplace_back(std::to_string(roulette_values[10]));

    string_structure.emplace_back(R"(        _______         )");
    string_structure.emplace_back(std::to_string(roulette_values[3]));

    string_structure.emplace_back(R"(      \
 |             .-''       ''-.           |
 |   )");
    string_structure.emplace_back(std::to_string(roulette_values[9]));

    string_structure.emplace_back(R"(      |      ●        |      )");
    string_structure.emplace_back(std::to_string(roulette_values[4]));

    string_structure.emplace_back(R"(   |
 |             '-._________.-'           |
  \      )");
    string_structure.emplace_back(std::to_string(roulette_values[8]));

    string_structure.emplace_back(R"(                         )");
    string_structure.emplace_back(std::to_string(roulette_values[5]));

    string_structure.emplace_back(R"(   /
   '.        )");
    string_structure.emplace_back(std::to_string(roulette_values[7]));

    string_structure.emplace_back(R"(               )");
    string_structure.emplace_back(std::to_string(roulette_values[6]));

    string_structure.emplace_back(R"(      .'
     '-.                          .-'
         '-.__________________.-')");
    string_structure.emplace_back("\n");

}

void Wheel::print_string_structure() {
    for (const auto & curr_string : string_structure) {
        std::cout << curr_string;
    }
    clearScreen();
}
void Wheel::run_ascii_animation() {
    for (int i = 0; i < 5;i++) {
        this->generate_ascii_string();
        this->roulette_values = rotate_vector(this->roulette_values);
        this->print_string_structure();
        this->clear_ascii_structure();
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

}

void Wheel::clear_ascii_structure() {
    string_structure.clear();
}




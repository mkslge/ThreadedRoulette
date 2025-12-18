//
// Created by Mark on 12/16/25.
//

#include "wheel.h"




void Wheel::generate_wheel() {
    //this->roulette_values[10];
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


Wheel::Wheel(bool win, int guessed_value) {
    this->win = win;
    this->guessed_value = guessed_value;
    this->generate_wheel();
    this->generate_ascii_string();
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
 |             .-''       ''-.             |
 |   )");
    string_structure.emplace_back(std::to_string(roulette_values[9]));

    string_structure.emplace_back(R"(      |      ●        |      )");
    string_structure.emplace_back(std::to_string(roulette_values[4]));

    string_structure.emplace_back(R"(   |
 |             '-._________.-'             |
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
     '-.                                      .-'
         '-.__________             ________.-')");




    for (int i = 0; i < string_structure.size();i++) {
        std::cout << string_structure[i];
    }
}





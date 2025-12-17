//
// Created by Mark on 12/16/25.
//

#include "wheel.h"




void Wheel::generate_wheel() {
    std::set<int> generated_values;
    generated_values.emplace(this->guessed_value);

    for (int i = 0; i < WHEEL_SIZE;i++) {
        int generated_value = get_random_value(OperationCodes::get_roulette_size());
        while (generated_values.contains(generated_value)) {
            generated_value = get_random_value(OperationCodes::get_roulette_size());
        }
        generated_values.emplace(generated_value);
    }
}


Wheel::Wheel(bool win, int guessed_value) {
    this->win = win;
    this->guessed_value = guessed_value;

}

void Wheel::generate_ascii_string() {
    static const std::string wheel_template = R"(              _________
         .-'''           '''-.
     .-''     {00}   {01}        ''-.
   .'      {11}                 {02}    '.
  /    {10}        _______         {03}      \
 |             .-''       ''-.             |
 |   {09}      |      ●        |      {04}   |
 |             '-._________.-'             |
  \      {08}                         {05}   /
   '.        {07}               {06}      .'
     '-.                                      .-'
         '-.__________             ________.-'
)";


}





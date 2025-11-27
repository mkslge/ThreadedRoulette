//
// Created by Mark on 11/9/25.
//

#include "utility.h"

/* DIFFERENT COMMANDS: CLIENT -> SERVER
 * JOIN: J
 * EXIT: E
 * BET : <COLOR><VALUE>_<AMOUNT>
 *
 */


bool is_bet_command(const std::string &cmd) {
    return cmd[0] == 'B';
}

std::string create_bet_message(int bet_amount, std::string color) {
    return "B" + std::to_string(bet_amount) + color;
}

std::string string_to_lower(std::string) {
    return "";
}

bool is_valid_color_command(std::string &color) {
    //std::string lowercase_color = std::tolower(color);
    return color == "R" || color == "B" || color == "G";
}
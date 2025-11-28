//
// Created by Mark on 11/9/25.
//

#include "utility.h"

/* DIFFERENT COMMANDS: CLIENT -> SERVER
 * JOIN: J
 * EXIT: E
 * BET : B AMOUNT COLOR
 *
 */

/* Converts string to all lowercase
 */
std::string string_to_lower(std::string str) {
    std::transform(str.begin(), str.end(), str.begin(),
        [](unsigned char c) {std::tolower(c);} );
    return str;
}
/*
 * Precondition: Assumes string is non-null, and has been lowercased.
 * Result: Returns true if string is a valid bet command (aka does it start with B)
 */
bool is_bet_command(const std::string &cmd) {
    return !cmd.empty() && cmd[0] == 'b';
}

/* Encodes bet into format b <AMOUNT> <COLOR CODE>
 */
std::string create_bet_message(int bet_amount, const std::string& color) {
    return string_to_lower("b " + std::to_string(bet_amount) + " " + color);
}


/* Function checks if the color string indicates a valid roulette color
 * (e.g. red black or green)
 *
 *
 */
bool is_valid_color_command(std::string &color) {
    std::string lc_color = string_to_lower(color);
    return !lc_color.empty() && (lc_color == "r" || lc_color == "b" || lc_color == "g");
}


int get_bet_amount() {
    bool valid_bet = false;
    while (!valid_bet) {
        cin
    }
}
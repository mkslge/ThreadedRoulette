//
// Created by Mark on 11/28/25.
//

#include "bet.h"


bet::bet() {

}

bet::bet(int amount, const std::string &color) {
    this->amount = amount;
    this->color = color;
}

/* Function checks if the color string indicates a valid roulette color
 * (e.g. red black or green)
 *
 *
 */
bool bet::valid_bet_color(std::string &color) {
    std::string lc_color = string_to_lower(color);
    return !lc_color.empty() && (lc_color == "r" || lc_color == "b" || lc_color == "g");
}


/*
 * Precondition: Assumes string is non-null, and has been lowercased.
 * Result: Returns true if string is a valid bet command (aka does it start with B)
 */
bool bet::is_bet_command(const std::string &cmd) {
    return !cmd.empty() && cmd[0] == 'b';
}


/* Encodes bet into format b <AMOUNT> <COLOR CODE>
 */
std::string bet::create_bet_code() {
    return string_to_lower("b " + std::to_string(this->amount) + " " + this->color);
}



int bet::prompt_bet_amount() {

    while (true) {
        int amount;
        std::cin >> amount;
        if (this->valid_bet_amount(amount)) {
            this->amount = amount;
            return amount;
        }
    }
    return -1;
}


bool bet::valid_bet_amount(int bet_amount) {
    return bet_amount >= MIN_BET_AMOUNT && bet_amount <= MAX_BET_AMOUNT;
}

std::string bet::prompt_bet_color() {

    while (true) {
        std::string color;
        std::cin >> color;
        if (this->valid_bet_color(color)) {
            this->color = color;
            return color;
        }
    }
    return "";
}
//
// Created by Mark on 11/28/25.
//

#include "bet.h"

bet::bet() {

}

bet::bet(clientinfo client) {
    this->client = client;
}

bet::bet(int amount, const std::string &color, clientinfo client) {
    this->amount = amount;
    this->color = color;
    this->client = client;
}

bet::bet(int amount, const std::string &color) {
    this->amount = amount;
    this->color = color;
}

std::string bet::prompt_bet_color() {

    while (true) {
        std::cout << "What color do you want to bet on? (R, B, or G)" << std::endl;
        std::string color;
        std::cin >> color;
        if (valid_bet_color(color)) {
            this->color = color;
            return color;
        } else {
            std::cout << "Invalid color , try again." << std::endl;
        }
    }
    return "";
}

int bet::prompt_bet_amount(clientinfo client) {

    while (true) {
        std::cout << "How much do you want to bet?" << std::endl;
        int amount;
        std::cin >> amount;
        if (this->valid_bet_amount(amount) && client.sufficient_balance(amount)) {
            this->amount = amount;
            return amount;
        } else {
            std::cout << "Invalid bet amount, try again." << std::endl;
        }
    }
    return -1;
}

bool bet::valid_and_funded_bet(int bet_amount) {
    return bet_amount >= MIN_BET_AMOUNT && bet_amount <= MAX_BET_AMOUNT && this->client.sufficient_balance(bet_amount);
}


/* Encodes bet into format b <AMOUNT> <COLOR CODE>
 */
std::string bet::create_bet_code() {
    return string_to_lower("b " + std::to_string(this->amount) + " " + this->color);
}



/*
 * Precondition: Assumes string is non-null, and has been lowercased.
 * Result: Returns true if string is a valid bet command (aka does it start with B)
 */
bool bet::is_bet_command(const std::string &cmd) {
    string_to_lower(cmd);
    std::string lowercase_cmd = string_to_lower(cmd);
    return !lowercase_cmd.empty() && lowercase_cmd[0] == 'b';
}

bool bet::valid_bet_amount(int bet_amount) {
    return bet_amount >= MIN_BET_AMOUNT && bet_amount <= MAX_BET_AMOUNT;
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


bet bet::encode_bet_string(std::string bet_string) {
    std::vector<std::string> split_bet_string = split_string(bet_string, ' ');
    if (split_bet_string.size() < 3) {
        return bet();
    }
    std::string p_bet_cmd = split_bet_string[0];
    std::string p_amount = split_bet_string[1];
    std::string p_color = split_bet_string[2];


    return bet(std::stoi(p_amount), p_color);
}

bool bet::is_winning_bet(Outcome outcome) {
    std::map<char,Color> map = get_outcome_map();

    return map[color[0]] == outcome.get_color();
}

int bet::get_amount() {
    return this->amount;
}
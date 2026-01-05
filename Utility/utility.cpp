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



std::string string_to_lower(std::string str) {
    std::transform(str.begin(), str.end(), str.begin(),
        [](unsigned char c){return std::tolower(c);});
    return str;
}

std::vector<std::string> split_string(const std::string& str, char delim) {
    std::stringstream ss(str);
    std::string curr_snippet;
    std::vector<std::string> strings;
    while(std::getline(ss, curr_snippet, delim)) {
        strings.emplace_back(curr_snippet);
    }
    return strings;
}


std::map<char, Color> outcome_map;
std::map<char, Color> get_outcome_map() {
    if (outcome_map.empty()) {
        outcome_map['r'] = Color::RED;
        outcome_map['b'] = Color::BLACK;
        outcome_map['g'] = Color::GREEN;
    }
    return outcome_map;
}


bool is_join_message(std::string msg) {
    msg = string_to_lower(msg);

    return !msg.empty() && msg[0] == constants::JOIN_CODE;
}

bool is_exit_message(std::string msg) {
    msg = string_to_lower(msg);

    return !msg.empty() && msg[0] == constants::EXIT_CODE;
}


int get_random_value(int max) {
    return rand() % max;
}

void init_random_seed() {
    srand(time(0));
}


std::vector<int> rotate_vector(const std::vector<int> &vector) {
    std::vector<int> temp_vector(vector.size());
    for (int i = 0; i < vector.size();i++) {
        temp_vector[i] = vector[(i + 1) % vector.size()];
    }
    return std::vector(temp_vector);
}

void clearScreen() {
    //ANSI escape code
    std::cout << "\033[2J\033[H";
}

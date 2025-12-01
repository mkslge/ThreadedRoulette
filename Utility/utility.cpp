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
        [](unsigned char c){std::tolower(c);});
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










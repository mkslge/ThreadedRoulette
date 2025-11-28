//
// Created by Mark on 11/9/25.
//
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#ifndef UTILITY_H
#define UTILITY_H

#include "../messenger.h"
#include <string>
#include <algorithm>
#include <cctype>

std::string string_to_lower(std::string);
bool is_bet_command(const std::string &cmd);
bool is_valid_color_command(std::string &color);
std::string create_bet_message(int bet_amount, const std::string& color);




#endif //UTILITY_H

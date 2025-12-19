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
#include <vector>
#include <sstream>
#include <random>
#include <ctime>
#include <map>
#include "../Models/color.h"
#include "OperationCodes.h"
std::string string_to_lower(std::string);

std::vector<std::string> split_string(const std::string&, char delim);

std::map<char, Color> get_outcome_map();
int get_random_value(int max);

bool is_join_message(std::string msg);
bool is_exit_message(std::string msg);

void init_random_seed();
std::vector<int> rotate_vector(const std::vector<int> &vector);
void clearScreen();


#endif //UTILITY_H

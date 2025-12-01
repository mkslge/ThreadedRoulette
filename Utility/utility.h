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

std::string string_to_lower(std::string);

std::vector<std::string> split_string(const std::string&, char delim);




#endif //UTILITY_H

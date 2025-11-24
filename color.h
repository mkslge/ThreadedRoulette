//
// Created by Mark on 11/9/25.
//

#ifndef COLOR_H
#define COLOR_H
#include <string>
#include <random>
#include <iostream>
#include <cstdlib>
#include <ctime>
enum class Color {BLACK, RED, GREEN};

std::string color_to_string(Color color);
Color get_random_color();


#endif //COLOR_H

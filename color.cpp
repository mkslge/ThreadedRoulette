//
// Created by Mark on 11/9/25.
//

#include "color.h"


std::string color_to_string(Color color) {
    switch (color) {
        case Color::BLACK:
            return "Black";

        case Color::RED:
            return "Red";

        case Color::GREEN:
            return "Green";

    }
    return "Unknown";

}


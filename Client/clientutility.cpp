//
// Created by Mark on 12/2/25.
//

#include "clientutility.h"

bool result_is_win(std::string result) {
    return result[0] == constants::get_win_code();
}

int parse_bet_result(const std::string& response_string){
    std::vector<std::string> split_bet_string = split_string(response_string, ' ');
    if (split_bet_string.size() < 2) {
        return 0;
    }
    std::string p_result = split_bet_string[0];
    int p_amount = std::stoi(split_bet_string[1]);

    return result_is_win(p_result) ? p_amount : -p_amount;
}


void spin_wheel_animation() {
    Wheel animation_wheel = Wheel();
    while (!BET_RESULT_RECEIVED) {
        animation_wheel.spin();
    }
}
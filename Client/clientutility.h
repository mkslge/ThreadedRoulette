//
// Created by Mark on 12/2/25.
//

#ifndef CLIENTUTILITY_H
#define CLIENTUTILITY_H


#include <string>
#include "../Utility/utility.h"
#include "../Utility/constants.h"
#include "../Models/wheel.h"

inline bool BET_RESULT_RECEIVED = false;

int parse_bet_result(const std::string& response_string);
bool result_is_win(std::string result);

void spin_wheel_animation();


#endif //CLIENTUTILITY_H

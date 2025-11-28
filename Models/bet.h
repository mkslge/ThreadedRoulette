//
// Created by Mark on 11/28/25.
//

#ifndef BET_H
#define BET_H
#include <string>
#include <iostream>
#include "../Utility/utility.h"

int MAX_BET_AMOUNT = 1000;
int MIN_BET_AMOUNT = 1;


class bet {
private:
    bool valid_bet_amount(int bet_amount);
public:
    bet();
    bet(int amount, const std::string &color);
    std::string create_bet_code();

    bool valid_bet_color(std::string &color);
    bool is_bet_command(const std::string &cmd);
    int prompt_bet_amount();
    std::string prompt_bet_color();


private:
    int amount;
    std::string color;

};



#endif //BET_H

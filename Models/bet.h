//
// Created by Mark on 11/28/25.
//

#ifndef BET_H
#define BET_H
#include <string>
#include <iostream>
#include "../Utility/utility.h"
#include "../Client/clientinfo.h"

inline int MAX_BET_AMOUNT = 1000;
inline int MIN_BET_AMOUNT = 1;


class bet {
private:

public:
    bet(clientinfo client);
    bet(int amount, const std::string &color, clientinfo client);
    bet(int amount, const std::string &color);
    bet();




    int prompt_bet_amount();

    bool valid_and_funded_bet(int bet_amount);

    std::string prompt_bet_color();

    std::string create_bet_code();
    static bet encode_bet_string(std::string bet_string);
    static bool is_bet_command(const std::string &cmd);
    static bool valid_bet_color(std::string &color);
    static bool valid_bet_amount(int amount);




private:
    int amount;
    std::string color;
    clientinfo client;

};



#endif //BET_H

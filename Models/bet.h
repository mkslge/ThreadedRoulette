//
// Created by Mark on 11/28/25.
//

#ifndef BET_H
#define BET_H
#include <string>
#include <iostream>
#include "../Utility/utility.h"
#include "clientinfo.h"
#include "outcome.h"

inline int MAX_BET_AMOUNT = 1000;
inline int MIN_BET_AMOUNT = 1;


class bet {
private:

public:
    bet();
    bet(clientinfo client);
    bet(int amount, const std::string &color, clientinfo client);
    bet(int amount, const std::string &color);

    std::string prompt_bet_color();
    int prompt_bet_amount(clientinfo client);

    std::string create_bet_code();

    bool valid_and_funded_bet(int bet_amount);
    bool is_winning_bet(Outcome winning_outcome);
    bool valid_bet_color(std::string &color);
    bool valid_bet_amount(int amount);


    int get_amount();

    void set_clientinfo(clientinfo client) {
        this->client = client;
    }

    static bet encode_bet_string(std::string bet_string);
    static bool is_bet_command(const std::string &cmd);

private:
    int amount;
    std::string color;
    clientinfo client;

};



#endif //BET_H

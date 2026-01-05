//
// Created by Mark on 11/26/25.
//

#ifndef OPERATIONCODES_H
#define OPERATIONCODES_H



class constants {
public:
    static char EXIT_CODE;
    static char JOIN_CODE;
    static char BET_CODE;
    static char WIN_CODE;
    static char LOSS_CODE;
    static int ROULETTE_SIZE;
    static int STARTUP_TIME;
    static int GREEN_VALUE;
    static int ROULETTE_ASCII_SIZE;
    static int SERVER_STARTING_BALANCE;
private:
    constants();
public:
    static char get_exit_code();
    static char get_join_code();
    static char get_bet_code();
    static char get_win_code();
    static char get_loss_code();
    static int get_roulette_size();
    static int get_startup_time();
    static int get_green_value();
    static int get_roulette_ascii_size();
    static int get_server_starting_balance();
};



#endif //OPERATIONCODES_H

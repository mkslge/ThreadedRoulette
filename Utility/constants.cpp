//
// Created by Mark on 11/26/25.
//

#include "constants.h"

char constants::EXIT_CODE = 'e';
char constants::JOIN_CODE = 'j';
char constants::BET_CODE = 'b';
char constants::WIN_CODE = 'w';
char constants::LOSS_CODE = 'l';
int constants::ROULETTE_SIZE = 37;
int constants::STARTUP_TIME = 5;
int constants::GREEN_VALUE = 0;
int constants::ROULETTE_ASCII_SIZE = 12;
int constants::SERVER_STARTING_BALANCE = 10000;

constants::constants() {

}



char constants::get_exit_code() {
    return EXIT_CODE;
}

char constants::get_join_code() {

    return JOIN_CODE;
}

char constants::get_bet_code() {

    return BET_CODE;
}

char constants::get_win_code() {

    return WIN_CODE;
}

char constants::get_loss_code() {

    return LOSS_CODE;
}

int constants::get_roulette_size() {

    return ROULETTE_SIZE;
}

int constants::get_startup_time() {
    return STARTUP_TIME;
}

int constants::get_green_value() {
    return GREEN_VALUE;
}

int constants::get_roulette_ascii_size() {
    return ROULETTE_ASCII_SIZE;
}

int constants::get_server_starting_balance() {
    return SERVER_STARTING_BALANCE;
}


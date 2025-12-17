//
// Created by Mark on 11/26/25.
//

#include "OperationCodes.h"

char OperationCodes::EXIT_CODE = 'e';
char OperationCodes::JOIN_CODE = 'j';
char OperationCodes::BET_CODE = 'b';
char OperationCodes::WIN_CODE = 'w';
char OperationCodes::LOSS_CODE = 'l';
int OperationCodes::ROULETTE_SIZE = 37;

OperationCodes::OperationCodes() {

}



char OperationCodes::get_exit_code() {
    return EXIT_CODE;
}

char OperationCodes::get_join_code() {

    return JOIN_CODE;
}

char OperationCodes::get_bet_code() {

    return BET_CODE;
}

char OperationCodes::get_win_code() {

    return WIN_CODE;
}

char OperationCodes::get_loss_code() {

    return LOSS_CODE;
}

int OperationCodes::get_roulette_size() {

    return ROULETTE_SIZE;
}


//
// Created by Mark on 11/26/25.
//

#include "OperationCodes.h"

char OperationCodes::EXIT_CODE = 'e';
char OperationCodes::JOIN_CODE = 'j';
char OperationCodes::BET_CODE = 'b';

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

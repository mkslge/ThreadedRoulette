//
// Created by Mark on 11/26/25.
//

#include "OperationCodes.h"

const char* OperationCodes::EXIT_CODE = nullptr;
const char* OperationCodes::JOIN_CODE = nullptr;

const char *OperationCodes::get_exit_code() {
    if (!EXIT_CODE) {
        EXIT_CODE = "E";
    }
    return EXIT_CODE;
}

const char *OperationCodes::get_join_code() {
    if (!JOIN_CODE) {
        JOIN_CODE = "J";
    }
    return JOIN_CODE;
}

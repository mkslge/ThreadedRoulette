//
// Created by Mark on 11/28/25.
//

#include "clientinfo.h"


clientinfo::clientinfo() {
    this->balance = DEFAULT_STARTING_BALANCE;
}

clientinfo::clientinfo(int starting_balance) {
    this->balance = starting_balance;
}

void clientinfo::add_balance(int amount) {
    this->balance += amount;
}

void clientinfo::remove_balance(int amount) {
    this->balance -= amount;
}

bool clientinfo::sufficient_balance(int bet_amount) const {
    return bet_amount <= this->balance;
}




